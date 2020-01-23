#include <stdio.h>
#include "seqListOps.h"

int main(void)
{
 seqarr seq;
 joblist arr;
 
 initialize_elements (arr); // initialize job lists
 
 printf("\nInitial job list:\n");
 printjoblist(arr);
 
 insert_joblist_decr(arr); // traverse joblist 3 times and insert into st in sorted order

 copy_sorted_ele (arr); // copy from st back to joblist
 
 printf("\nSorted job list:\n");
 printjoblist(arr);
}
 
