To allocate requested memory we will find the next greater power of 2
and find it in the allocation pool(in implementation binary tree is used)
where free memory nodes are available in size of power of 2.
We will define a level for the binary tree which will be capable of
allocation 2^level number of memory blocks.Example:If we take
level=7,we can have 2^7=128 total memory blocks to allocate.

    Some of the terminologies used:
        ● Index:Index represents the block number.
        ● Offset:Offset is weight that a node contains which inturn helps in
          finding an address.
        ● Level:Level at which the node is placed in the tree.
          Each node of allocation pool or binary tree is denoted as one of the
          below:
          ● UNUSED - 0
          ● USED - 1
          ● FULL - 3
          ● SPLIT - 2
         
1.UNUSED- If a node is not allocated it will be marked as
UNUSED.
Initially all the nodes will be marked as UNUSED.
2.USED-If a node is allocated it will be marked as USED.

3.FULL-If both the childs of a node are USED then the node will be
marked as FULL.

4.SPLIT:If any one of the child of a node is available to allocate
memory,then the node will be marked as SPLIT.
