#include "buddy.h"

using namespace std;

void malinfo()
{
    int internal_frag=0;
    int total_space_allocated=0;
    int total_space_requested=0;
    for(auto it:index_to_alloc_data_map)
	{
        cout<<"Size requested "<<it.second.size_requested<<"B"<<endl;
        cout<<"Size allocated "<<it.second.size_allocated<<"B"<<endl;
        cout<<"index at "<<it.second.index<<endl;
        total_space_allocated+=it.second.size_allocated;
        total_space_requested+=it.second.size_requested;
        internal_frag+= (it.second.size_allocated-it.second.size_requested);
        cout<<"starting from location ";
        printf("%p", uintptr_t(memory)+it.second.offset);
        cout<<endl;
        cout<<"Internal fragmentaion = "<<-1*(it.second.size_requested-it.second.size_allocated)<<"B"<<endl;
		cout<<"=========================================="<<endl;
	}

    cout<<"Total space requested = "<<total_space_requested<<"B"<<endl;

    cout<<"Total space allocated = "<<total_space_allocated<<"B"<<endl;

    cout<<"Total internal fragmentation = "<<internal_frag<<"B"<<endl;

}