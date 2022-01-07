
#include "buddy.h"

using namespace std;


int buddy_posix_memalign(int alignment, int size) {
	int address_offset = buddy_malloc(size);

	// printf("original offset : %d\n", address_offset);
	// printf("original address : %p\n", (memory + address_offset));

	int rem = uintptr_t(memory + address_offset) % alignment;
	if ( rem == 0) {
		// cout << "memory aligned" << endl; 
		return address_offset;
	} else {
		// cout << "memory not aligned by : " << rem << endl;
		// cout << "new offset : " << (address_offset + alignment - rem) << endl;
	}
	offset_map_lock.lock();
	auto iter = offset_to_alloc_data_map.find(address_offset);

	if (iter != offset_to_alloc_data_map.end()) {
		struct alloc_data temp_alloc_data_struct = iter->second;

		if (address_offset + rem + temp_alloc_data_struct.size_allocated >= TOTAL_MEMORY) {
			memory = memory + PAGE_SIZE;
		}
		
		temp_alloc_data_struct.offset = address_offset + (alignment - rem);
		iter->second = temp_alloc_data_struct;
	}

	offset_map_lock.unlock();

	return (address_offset + alignment - rem);
}