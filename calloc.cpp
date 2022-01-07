
#include "buddy.h"



vector<int> buddy_calloc(int n, int size){
	vector<int> ans;
	int total = log2(TOTAL_MEMORY);
	int curr = log2(size);
	int max_permissible_n = 1 <<(total-curr);
	if(n>max_permissible_n){
		// cout<<"invalid nmember value"<<endl;
	}
	else {
	for(int i =0;i<n;i++){
		ans.push_back(buddy_malloc(size));
	}
  }
  return ans;
}