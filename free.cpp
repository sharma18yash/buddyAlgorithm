

#include "buddy.h"
using namespace std;



void combine(int index_to_free) {
	// cout << "index_to_free : " << index_to_free << endl;

	while(true) {
		int sibling_index = index_to_free - 1 + (index_to_free & 1) * 2;
		// cout << "sibling_index : " << sibling_index << endl;

		if(sibling_index < 0 || heap[sibling_index] == 1 || 
			heap[sibling_index] == 2 || heap[sibling_index] == 3) {

			// cout << "sibling not free " << endl;
			while(((index_to_free = (index_to_free + 1) / 2 - 1) >= 0) && 
					heap[index_to_free == 3]) {
				// cout << "marking parent index : " << index_to_free << " split" << endl;
				heap[index_to_free] = 2;
			}

			return;
		}

		int parent_index = (index_to_free + 1) / 2 - 1;
		if (heap[sibling_index] == 0) {

			heap[parent_index] = 0;
		}

		index_to_free = parent_index;
	}


}

void _b_free(int offset_to_free, int level_to_free, int index_to_free) {
	
	heap_lock.lock();
	heap[index_to_free] = 0;

	combine(index_to_free);
	heap_lock.unlock();
}

void buddy_free(uintptr_t address) {
	int offset_to_free = address - uintptr_t (memory);

	// cout << "offset to free : " << offset_to_free << endl;
	offset_map_lock.lock();
	auto iter = offset_to_alloc_data_map.find(offset_to_free);

	if (iter == offset_to_alloc_data_map.end()) {
		// cout << "Address is unallocated" << endl;
	}

	struct alloc_data temp_alloc_data_struct = iter->second;

	offset_map_lock.unlock();

	int level_to_free = temp_alloc_data_struct.level;
	int index_to_free = temp_alloc_data_struct.index;

	_b_free(offset_to_free, level_to_free, index_to_free);

	offset_map_lock.lock();
	index_map_lock.lock();

	offset_to_alloc_data_map.erase(offset_to_free);
	index_to_alloc_data_map.erase(index_to_free);

	
	offset_map_lock.unlock();
	index_map_lock.unlock();
}