#include <stdio.h>
#include "compare.h"
int nextfreeloc = 0;
int ind = 0;

void printjob (Job j)
{
 printf ("JOB ID = %d, Priority = %d, Execution time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}

void printseqlist(seqlist sl)
{
 int i;
 printf ("size of list = %d\n",sl.size);
 for (i=st[sl.head].next ; st[i].next != -1 ; i=st[i].next)
 {
  printjob (st[i].ele);
 }
}

void printjoblist (joblist j)
{
 int i;
 for (i=0;i<MAX;i++)
 {
  printjob (j[i]);
 }
}

void initialize_elements (joblist ele)
{
 int i,size;
 /*printf ("No of Jobs");
  scanf ("%d",&size);
 for (i=0;i<10;i++)
 {
  printf ("Enter job ID");
  scanf ("%d",ele[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",ele[i].pri);
  printf ("Execution Time");
  scanf ("%d",ele[i].et);
  printf ("Arrival Time");
  scanf ("%d",ele[i].at);
 }*/
 i=0;
 ele[0].id=1;
 ele[0].pri=0;
 ele[0].at=1;
 ele[0].et=5;
 ele[1].id=2;
  ele[1].pri=1;
   ele[1].at=9;
    ele[1].et=3;
ele[2].id=3;
 ele[2].pri=2;
  ele[2].at=11;
   ele[2].et=12;
ele[3].id=4;
 ele[3].pri=0;
  ele[3].at=4;
   ele[3].et=7;
ele[4].id=5;
 ele[4].pri=1;
  ele[4].at=8;
   ele[4].et=2;
ele[5].id=6;
 ele[5].pri=2;
  ele[5].at=12;
   ele[5].et=11;
ele[6].id=7;
 ele[6].pri=0;
  ele[6].at=3;
   ele[6].et=9;
ele[7].id=8;
 ele[7].pri=1;
  ele[7].at=7;
   ele[7].et=4;
ele[8].id=9;
 ele[8].pri=2;
  ele[8].at=13;
   ele[8].et=10;
ele[9].id=10;
 ele[9].pri=0;
  ele[9].at=2;
   ele[9].et=15;

/* ele[0].pri = ele[3].pri = ele[6].pri = PRI_0;
 ele[1].pri = ele[4].pri = ele[7].pri = PRI_1;
 ele[2].pri = ele[5].pri = ele[8].pri = ele[9].pri = PRI_2;
 for (i=0;i<MAX;i++)
 {
  ele[i].id = i+1;
  ele[i].et = i+2;
  ele[i].at = i;
 }
 ele[2].at = 10;
 ele[5].at = 1;
 ele[6].at = 5;*/
}

void insert_joblist(joblist jl, PRIORITY p) {
	int i,j,k;
	Job key;
	for (i=0; i<MAX; i++) { 
		if (jl[i].pri == p) {
			key = jl[i];
			for (j=0;j<ind;j++) {
				if (st[j].ele.pri == p && (compare(key, st[j].ele) == LESSER || compare(key, st[j].ele) == EQUAL)) {
					break;
				}
			}
			for (k=ind-1; k>=j; k--) {
				st[k+1].ele = st[k].ele;
			}
			st[j].ele = key;
			ind++;
		}
	}
}

void insert_joblist_decr(joblist jl) {
	insert_joblist(jl,PRI_2);
	insert_joblist(jl,PRI_1);
	insert_joblist(jl,PRI_0);
}

void copy_sorted_ele(joblist ele)
{
	for (int i=0; i<MAX; i++) {
		ele[i] = st[i].ele;
	}
}

