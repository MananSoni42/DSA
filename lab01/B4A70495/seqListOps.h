#include "storage.h"

extern seqlist createlist();
extern void initialize_elements (joblist arr);
extern void insertelements (joblist arr,seqarr s);
extern void printseqlist(seqlist);
extern void copy_sorted_ele (joblist);
extern void insert_joblist(joblist, PRIORITY);
extern void insert_joblist_decr(joblist);
extern void printjoblist(joblist j);
extern seqlist insert(Job j , seqlist sl);
