#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

typedef struct 
{
	uint32_t   type;
	uint64_t  arg0;
	uint64_t  arg1;
	uint64_t  arg2;
	uint64_t  arg3;
} Event;

#define TRACEBUF_MAX  (8)
#define TRACEBUF_EVENT_MINIT    (0x1)
#define TRACEBUF_EVENT_MCOMMIT  (0x2)
#define TRACEBUF_EVENT_MRELEASE (0x3)

Event tracebuf[TRACEBUF_MAX];
uint32_t tracebuf_index;

void add_event(uint8_t type, uint64_t arg0, uint64_t arg1, uint64_t arg2, uint64_t arg3) 
{
	Event *ptr = &tracebuf[tracebuf_index];
	ptr->type = type;
	ptr->arg0 = arg0;
	ptr->arg1 = arg1;
	ptr->arg2 = arg2;
	ptr->arg3 = arg3;
	printf("adding at index %d\n", tracebuf_index);
	tracebuf_index = (tracebuf_index + 1) % TRACEBUF_MAX;
}

void print_events(void) 
{
	for (uint32_t i = 0; i < TRACEBUF_MAX; ++i) 
	{
		Event *event = &tracebuf[i];
		printf("tracebuf[%d]=%d 0x%llx 0x%llx 0x%llx 0x%llx\n", 
		       i, event->type, event->arg0, event->arg1, event->arg2, event->arg3);
	}
}


int main(void) 
{
	printf("addr is %p\n", &tracebuf);
	
	for (uint32_t i = 0; i <= TRACEBUF_MAX; ++i) 
	{
		add_event(TRACEBUF_EVENT_MINIT, i, i+1, i+2, i+3);		
	}

	print_events();
	
	return 0;
}
