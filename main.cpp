#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#include <unistd.h>
#include "buddy.h"
#include <mutex>
#include <pthread.h>

using namespace std;



uint8_t* heap;
void* memory;
map<int, alloc_data> offset_to_alloc_data_map;
map<int, alloc_data> index_to_alloc_data_map; 

mutex heap_lock;
mutex offset_map_lock;
mutex index_map_lock;

void init_memory() {
	heap =(uint8_t*) sbrk(TOTAL_MEMORY);
	memory = sbrk(TOTAL_MEMORY);
	memset(heap, 0, TOTAL_MEMORY - 1);
	memset(memory, 0, TOTAL_MEMORY - 1);
}


void testCase1() {
	test_alloc2();
}

void testCase2() {
	test_alloc3();
}

int main() {
	init_memory();

	thread t1(testCase1);
	thread t2(testCase2);
	t1.join();
	t2.join();

	malinfo();

	return 0;
}