
#include "buddy.h"
using namespace std;

int allocate_memory(uint8_t* heap, int allowed_size, int level, 
	int index, int current_node_size, int size_requested) {

	// cout << "current_node_size : " <<  current_node_size << endl;
	if (allowed_size > current_node_size) {
		return -1;
	}

	if (allowed_size == current_node_size) {
		if (heap[index] == 0) { 
			// cout << "node of same size and unused found : " << index << endl;
			heap[index] = 1;
			int free_offset = calculate_address_offset(index, level);

			struct alloc_data temp_alloc_data_struct = {level, index, current_node_size, 
														size_requested, free_offset};
			offset_to_alloc_data_map.insert(make_pair(free_offset, temp_alloc_data_struct));
			index_to_alloc_data_map.insert(make_pair(index, temp_alloc_data_struct));

			return free_offset;
		}

		return -1;
	}
	if(heap[index] == 3 || heap[index] == 1) {
		return -1;
	}

	int left_tree_index = get_left_index(index);
	int right_tree_index = get_right_index(index);

	if (left_tree_index >= TOTAL_MEMORY || right_tree_index >= TOTAL_MEMORY) {
		return -1;
	}

	int address_allocated = allocate_memory(heap, allowed_size, level + 1, 
											left_tree_index, current_node_size / 2, 
											size_requested);

	//cout<<"address is "<<address_allocated<<" index is "<<index<<endl;

	
	if(address_allocated == -1) {
		address_allocated = allocate_memory(heap, allowed_size, level + 1, 
											right_tree_index, current_node_size / 2, 
											size_requested);
	}

	update_curr_index_state(index, left_tree_index, right_tree_index);

	return address_allocated;
}

int buddy_malloc(int size) {

	heap_lock.lock();
	int allowed_size = convert_to_greater_power_of_2(size);

	heap_lock.unlock();

	int address_allocated = allocate_memory(heap, allowed_size, 0, 0, TOTAL_MEMORY, size);

	return address_allocated;
}