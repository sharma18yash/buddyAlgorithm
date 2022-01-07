#ifndef BUDDY_H
#define BUDDY_H

#include <iostream>
#include<bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define LEVEL 10
#define TOTAL_MEMORY (1 << LEVEL)
#define PAGE_SIZE sysconf(_SC_PAGESIZE)

extern uint8_t* heap;
extern void* memory;

extern mutex heap_lock;
extern mutex offset_map_lock;
extern mutex index_map_lock;


struct alloc_data {
	int level;
	int index;
	int size_allocated;
	int size_requested;
	int offset;
};


extern map<int, alloc_data> offset_to_alloc_data_map;
extern map<int, alloc_data> index_to_alloc_data_map; 


int buddy_posix_memalign(int alignment, int size);

int allocate_memory(uint8_t* heap, int allowed_size, int level, 
	int index, int current_node_size, int size_requested);

int buddy_malloc(int size);

vector<int> buddy_calloc(int n, int size);

int buddy_realloc(uintptr_t address_to_realloc, int size);

void combine(int index_to_free);

void _b_free(int offset_to_free, int level_to_free, int index_to_free);
void buddy_free(uintptr_t address);

void init_memory();
int convert_to_greater_power_of_2(int size);
int get_left_index(int index);
int get_right_index(int index);
int calculate_address_offset(int index, int curr_level);
void update_curr_index_state(int curr_index, int left_tree_index, int right_tree_index);

void test_alloc2();
void test_alloc3();

void malinfo();

int buddy_reallocArray(uintptr_t address_to_realloc, int n, int size);

#endif