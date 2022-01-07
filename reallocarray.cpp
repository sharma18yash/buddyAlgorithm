#include "buddy.h"
using namespace std;

int buddy_reallocArray(uintptr_t address_to_realloc, int n, int size){
	return buddy_realloc(address_to_realloc, n*size);
}