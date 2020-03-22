#include "sort.h"
#include<stdlib.h>
#include<time.h>
#include<math.h>

int partition(DATA* arr, int l, int h, char* type) { 
    // partition based on type which is one of [first,last,random,median(of 3 random elements)], median is the default option
    int p;
    srand(time(0));
    if (!strcmp(type, "last")) {
        p = h;
    }
    else if (!strcmp(type, "first")) {
        p = l;
    }
    else if (!strcmp(type, "random")) {
        p = l + rand()%(h-l+1);
    }
    else {
        if (h-l < 3) {
            p = l;
        }
        else { // median case
            int p1 = l + rand()%(h-l+1);
            int p2 = l + rand()%(h-l+1);
            int p3 = l + rand()%(h-l+1);

            if ((p1<p2 && p2<p3) || (p3<p2 && p2<p1)) {
                p = p2;
            }
            else if ((p2<p1 && p1<p3) || (p3<p1 && p1<p2)) {
                p = p1;
            }
            else {
                p = p3;
            }
        }
    }


    DATA pivot = arr[p];
    int ind=l;
    
    //printf("\t(%d,%d): %d | ", l, h, pivot.index);
    for (int j=l; j<=h; j++) {
        if (arr[j].index < pivot.index) {
            if (j==p) {
                p = ind;
            }
            else if (ind == p) {
                p = j;
            }
            swap(&arr[ind],&arr[j]);
            ind++;
        }
    }
    //printf("%d %d\n", arr[ind], arr[p]);
    swap(&arr[ind],&arr[p]);
    return ind;


}

void quick_sort(DATA* arr, int l, int h) {
    int p;
    if (l < h) {
        p = partition(arr,l,h,"median");
        //printf("%d %d\n",p,arr[p].index);
        //printList(arr,10);
        quick_sort(arr,l,p-1);
        quick_sort(arr,p+1,h);
    }
}

void sort(DATA* arr, int len) {
    quick_sort(arr,0,len-1);
}
