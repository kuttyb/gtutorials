typedef struct {
   volatile uint32_t  current_index;

   uintptr_t listeners[MAX][2];
   mutex_t   non_isr_lock;
} Engine;


void on_isr(Engine *ptr) {
   const uint32_t local_index = ptr->current_index;
   mfence();
   
   for (uint32_t i = 0; i < MAX; ++i_) 
       if (listeners[i][local_index]) signal(listeners[i][local_index]);
}


void non_isr_add_listener(Engine *ptr, uintptr_t listener_addr) {
  // Stop other non_isr threads from competing with you	
  sleep_lock(ptr->non_isr_lock);

  const uint32_t other_index = ptr->current_index;
  mfence();
  const uint32_t local_index = (other_index + 1) % 2;
	
  // Add new element into the double buffered copy
  bool bAdded = false;
  for (int x = 0; x < MAX; ++x) {
      if (!bAdeed && !listeners[x][local_index]) {
      	 listeners[x][local_index] = listener_addr;
	 bAdded = true;
      } else {
      	 listeners[x][local_index] = listener_addr[x][non_local_index];
      }
  }
  assert(bAdded);

  // Flip the other buffer for the ISR to see
  assert(cmpxchg(&listener->current_index, other_index, local_index));

  sleep_unlock(ptr->non_isr_lock);
}