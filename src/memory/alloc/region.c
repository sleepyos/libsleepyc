#include <sleepyc/memory.h>
#include <sleepyc/internal/guts_of_the_allocator.h>

SCAllocatedRegion_t *SCAllocatedRegion_head = NULL;
SCAllocatedRegion_t *SCAllocatedRegion_tail = NULL;

SCAllocatedRegion_t *SCAllocatedRegion_getForPtr
(void *ptr)
{
	if (SCAllocatedRegion_head == NULL)
	{
		return NULL;
	}

	// TODO: make searching more optimized?
	SCAllocatedRegion_t *current = SCAllocatedRegion_head;
	while (current != NULL && current->ptr != ptr) {
		current = current->next;
	}

	return current;
}

SCAllocatedRegion_t *SCAllocatedRegion_newFromPtrSize
(void *ptr, size_t len)
{
	SCAllocatedRegion_t *region = MemoryAllocate__raw(sizeof(SCAllocatedRegion_t));
	region->ptr = ptr;
	region->len = len;
	region->next = NULL;

	if (SCAllocatedRegion_tail != NULL)
	{
		SCAllocatedRegion_tail->next = region;
		SCAllocatedRegion_tail = region;
	}

	if (SCAllocatedRegion_head == NULL)
	{
		SCAllocatedRegion_head = region;
		SCAllocatedRegion_tail = region;
	}

	return region;
}

void SCAllocatedRegion_destroy
(SCAllocatedRegion_t *region)
{
	// If this region is the head, it's easier to remove
	if (region == SCAllocatedRegion_head)
	{
		SCAllocatedRegion_head = region->next;
		MemoryFree__raw(region, sizeof(SCAllocatedRegion_t));
		return;
	}

	// Walk the list
	SCAllocatedRegion_t *prev = SCAllocatedRegion_head;
	for (;;)
	{
		if (prev == NULL || prev->next == region)
		{
			break;
		}

		prev = prev->next;
	}

	prev->next = prev->next->next;
	MemoryFree__raw(region, sizeof(SCAllocatedRegion_t));
}
