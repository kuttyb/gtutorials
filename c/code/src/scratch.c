#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

typedef struct {
  void**     array;
  uint32_t   entries;
  uint32_t   curnext;
  uint32_t   prevnext;
  uint32_t   maxcurrent;
} DependencyStack;

DependencyStack* exportDependencyStack(uint32_t maxentries) {
  DependencyStack* stack = calloc(1, sizeof(DependencyStack));
  assert(stack);
  *stack = (DependencyStack) {
    .array    = calloc(maxentries, sizeof(void*)),
    .entries  = maxentries,
    .curnext  = 0,
    .prevnext = 0,
    .maxcurrent = 0
  };
  return stack;
}

void destroyDependencyStack(DependencyStack* stack) {
  assert(stack);
  free(stack->array);
  free(stack);
}

void addCurrent(DependencyStack* stack, void* entry) {
  assert(stack); 
  assert(entry); 
  if (stack->curnext >= stack->entries) {
    printf("addCurrent curnext %d stack->entries %d\n",
	   stack->curnext, stack->entries);
    assert(0);
  }
  //  printf("adding to entry %d\n", stack->curnext);
  stack->array[stack->curnext++] = entry;
}

void* getPrev(DependencyStack* stack) {
  assert(stack);
  if ((stack->prevnext >= stack->maxcurrent) ||
      (stack->prevnext >= stack->entries)) {
    /* printf("%s Bailing stack->prevnext %d stack->entries %d\n", */
    /* 	   __FUNCTION__, stack->prevnext, stack->entries); */
    return NULL;
  } else {
    /* printf("%s returning from entry %d\n", */
    /* 	   __FUNCTION__, stack->prevnext); */
    return stack->array[stack->prevnext++];
  }
}

void resetStack(DependencyStack* stack) {
  assert(stack);
  stack->maxcurrent = stack->curnext;
  stack->curnext  = 0;
  stack->prevnext = 0;
}

static inline uint32_t getlocalend(uint32_t localstart, uint32_t globalend, uint32_t bulk) {
  uint32_t localend = localstart + bulk - 1;
  if (localend > globalend) {
    return globalend; 
  } else {
    return localend;
  }
}

#define BULKFOR(start, end, bulk, localstart, localend) \
  for(localstart = start; (localstart <= end) && (localend = getlocalend(localstart, end, bulk)); \
      localstart+=bulk)

typedef struct {
  uint32_t start;
  uint32_t end;
} Range;

static void perlogbase(const uint32_t inlogctr, const uint32_t totalelements, 
		       const uint32_t threads,  DependencyStack* depstack,
		       const uint32_t logbase) {
  const uint32_t maxelements = totalelements - 1;
  uint32_t logctr = inlogctr <= maxelements ? inlogctr : totalelements;
  uint32_t perthreadrange = maxelements / (threads * logctr);
  if (!perthreadrange) perthreadrange = 1;
  perthreadrange = perthreadrange * logctr;
  printf("===========================================\n");
  printf("%s LOGCTR %d PerThreadRange %d\n", __FUNCTION__, logctr, perthreadrange);

  uint32_t ls, le;
  uint32_t sid = 0;
  /** Loop to distribute work among separate threads (substreams if you will) */
  BULKFOR(0, maxelements, perthreadrange, ls, le) {
    uint32_t lls, lle;
    printf("\tSID %d\n", sid);
    /** Within a thread, split perthreadrange into separate cmds */
    BULKFOR(ls, le, logctr, lls, lle) {
      Range* range = calloc(1, sizeof(Range));
      *range = (Range) {
	.start = lls,
	.end   = lle
      };
      printf("\t\t%d - %d\n", lls, lle);
      /** wire up dependencies with previous iteration */
      for(uint32_t p = 0; p < logbase; p++) {
	Range* temprange = getPrev(depstack);
	if (!temprange) break;
	if (1) {
	  printf("\t\t\tDEPSTACK: depends on [%d - %d]\n",
		 temprange->start, temprange->end);
	}
      }
      addCurrent(depstack, range);
    }
    sid = (sid + 1) % threads;
  }
  printf("===========================================\n");
}

static void predux() {
  const uint32_t threads     = 5;
  const uint32_t maxelements = 50;
  const uint32_t logbase     = 3;
  const uint32_t depstsize   = (maxelements / logbase) + 1;
  DependencyStack* depstack  = exportDependencyStack(depstsize);
  printf("Dependency Stack Size %d\n", depstsize);

  uint8_t stop = 0;
  for (uint32_t i = logbase; ; i*=logbase) {
    if (i >= maxelements) {
      if (stop) break;
      else stop = 1;
    }
    resetStack(depstack);
    printf("%s logbase %d current %d next %d\n",
	   __FUNCTION__, i, depstack->curnext, depstack->prevnext);
    perlogbase(i, maxelements, threads, depstack, logbase);
  }

  destroyDependencyStack(depstack);
}

int main(void) {

  predux();

  printf("before\n");
  __clear_cache((void*)0, (void*)10);
  printf("after\n");

  return 0;
}

