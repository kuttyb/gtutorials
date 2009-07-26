// Heres my adaptive lock ( we should add biased locking later to avoid excessive CAS ):

typedef struct _thread_status {
  DWORD  threadID;
  BOOL   isThreadRunnning;
} THREAD_STATUS;

typedef struct _Lock {
  BIT            isLocked;
  DWORD          owningThreadIDCachedValue; // So accesses can be made w/o dereferncing pLockOwner
  TURNSTILE      waiterThreads;
  THREAD_STATUS *pLockOwner;
} LOCK;


// Adaptive Locking
BOOLEAN acquireLock(LOCK lock) {
  // Trivially succeed if already holding lock
  if (owningThreadIDCachedValue == CURRENT_THREAD_ID){
    return TRUE;
  }

  // FAST PATH just dumb spin
  int fastPathRetries = MAX_FAST_PATH_RETRIES;
  for(int fastPathRetries = MAX_FAST_PATH_RETRIES; (CAS(lock.isLocked, 1, 0) != 1) && fastPathRetries != 0;
      fastPathRetries--);

  //
  // Check if current lock owner is actually running, slightly slower path because of pointer
  // dereference.
  // 
  if (lock.pLockOnwer->isThreadRunning == TRUE) {
    for(int spinForRunningThreadToRelinquish = MAX_WAIT_FOR_RUNNING_THREAD_TO_RELINQUISH;
	(CAS(lock.isLocked, 1, 0) != 1) && spinForRunningThreadToRelinquish != 0;
	spinForRunningThreadToRelinquish--);
  }

  // SLOW PATH trap to kernel
  return slowKernelAcquire();
}

BOOLEAN slowKernelAcquire(Lock lock) {
  acquireTurnstile();

  //
  // last ditch attempt
  // Reason its done inside the turnstile lock is to establish a clear
  // happens before with any lock releases
  // 
  if (CAS(lock.isLocked, 1, 0) == 1) {
    return TRUE;
  }

  //
  // Add thread to turnstile (this can be time consuming since we need to place it at the right
  // priority queue
  // 
  addThreadToTurnstile();

  //
  // Put thread to sleep
  // Dispatcher lock is a simple spinlock that raises IRQL to the dispatch level then spins for acquire
  // 
  acquireDispatcherLockForCurrentCpu();
  RemoveThreadFromCurrentCpuReadyQueue();
  releaseDispatcherLockForCurrentCpu();

  releaseTurnstile();
}


void release(Lock lock) {
  lock.threadID = INVALID_THREAD;
  
  STORE(lock.isLocked, FALSE);
  STOREBARRIER();

  slowReleasePath();
}

void slowReleasePath(Lock lock) {
  acquireTurnstile();

  //
  // This is also where you may want to adjust MAX_WAIT_FOR_RUNNING_THREAD_TO_RELINQUISH
  // and MAX_FAST_PATH_RETRIES values to avoid livelock starvations where threads on the fast
  // path are starving those waiting on the turnstile
  // 
  THREAD *threadList = NULL;
  threadList = policyToWakeupOneOrManyThreads();
  removeThreadsFromTurnstile(threadList);

  acquireDispatcherLockForCurrentCpu();
  addThreadsIntoCurrentCpuReadyQueue();
  releaseDispatcherLockForCurrentCpu();

  releaseTurnstile();
}
