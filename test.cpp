#include "buddy.h"
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;


void test_alloc2(){

	int x = buddy_malloc(11);

	int y = buddy_malloc(18);

	int z = buddy_malloc(3);

	int w = buddy_malloc(132);
    // cout<<"here"<<endl;
	int p = buddy_malloc(133);

	return;
}

void test_alloc3()
{
    int x = buddy_malloc(11);

	int y = buddy_malloc(18);

	int z = buddy_malloc(3);

	int w = buddy_malloc(72);
    // cout<<"here"<<endl;
	int p = buddy_malloc(56);
    return;
}
