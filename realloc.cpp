



#include "buddy.h"
using namespace std;

int buddy_realloc(uintptr_t address_to_realloc, int size) {
	int offset_to_realloc = address_to_realloc - uintptr_t(memory);

	// cout << "offset to realloc : " << offset_to_realloc << endl;

	offset_map_lock.lock();
	auto iter = offset_to_alloc_data_map.find(offset_to_realloc);

	if (iter == offset_to_alloc_data_map.end()) {
		// cout << "Address is unallocated" << endl;
		return -1;
	}

	struct alloc_data temp_alloc_data_struct = iter->second;

	offset_map_lock.unlock();

	int level_to_realloc = temp_alloc_data_struct.level;
	int index_to_realloc = temp_alloc_data_struct.index;
	int size_to_realloc = temp_alloc_data_struct.size_requested;

	buddy_free(address_to_realloc);

	int address_allocated = buddy_malloc(size);

	if(address_allocated == -1) {
		cout << "could not find enough space to realloc" << endl;
		address_allocated = buddy_malloc(size_to_realloc);
	}

	return address_allocated;
}