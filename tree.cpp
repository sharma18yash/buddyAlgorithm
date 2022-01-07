#include "buddy.h"
using namespace std;

int convert_to_greater_power_of_2(int size) {
	int next_power = 1;
    if (size && !(size & (size - 1)))
        return size;
 
    while (next_power < size)
        next_power <<= 1;
     
    return next_power;
}

int get_left_index(int index) {
	return index * 2 + 1;
}

int get_right_index(int index) {
	return index * 2 + 2;
}

int calculate_address_offset(int index, int curr_level) {
	int no_of_nodes_At_level = (index + 1) - (1 << curr_level);

	return no_of_nodes_At_level << (LEVEL - curr_level);
}

void update_curr_index_state(int curr_index, int left_tree_index, int right_tree_index) {
	//cout<<"index here "<<curr_index<<" left is "<<heap[left_tree_index]<<" right is "<<heap[right_tree_index]<<endl;
	if (heap[left_tree_index] == 1 && heap[right_tree_index] == 1) {
		// cout << "marking parent index  : " << curr_index << " as full" << endl;
		heap[curr_index] = 3;
	} else if ((heap[left_tree_index]== 1 && heap[right_tree_index] == 0)
				|| (heap[left_tree_index] == 2 || heap[right_tree_index] == 2) 
				|| (heap[left_tree_index] == 3 && heap[right_tree_index] == 0)) {
		//cout<<"11111"<<endl;
		// cout << "marking parent index  : " << curr_index << " as split" << endl;
		heap[curr_index] = 2;
	} else if (heap[left_tree_index]== 0 && heap[right_tree_index] == 1
				|| (heap[left_tree_index] == 2 || heap[right_tree_index] == 2)
				|| (heap[left_tree_index] == 3 && heap[right_tree_index] == 0)) {
		//cout<<"2222<"<<endl;
		// cout << "marking parent index  : " << curr_index << " as split" << endl;
		heap[curr_index] = 2;
	} else if (heap[left_tree_index]== 1 && heap[right_tree_index] == 3) {
		// cout << "marking parent index  : " << curr_index << " as full" << endl;
		heap[curr_index] = 3;
	} else if (heap[left_tree_index]== 3 && heap[right_tree_index] == 1) {
		// cout << "marking parent index  : " << curr_index << " as full" << endl;
		heap[curr_index] = 3;
	} else if (heap[left_tree_index]== 3 && heap[right_tree_index] == 3) {
		// cout << "marking parent index  : " << curr_index << " as full" << endl;
		heap[curr_index] = 3;
	}
}