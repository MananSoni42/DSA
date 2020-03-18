#include<stdio.h>
#include<stdbool.h>
#include "read_csv.h"

void insertionSort(DATA arr[], int n) {
    int i, j;
    DATA key;

    for (i=1;i<n;i++) {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j].empID > key.empID) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int partition(DATA arr[], int lo, int hi) {
    int i=lo-1, j;
    DATA x=arr[hi], temp;
    for (j=lo;j<hi;j++) {
        if (arr[j].empID <= x.empID) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; 
        }
        temp = arr[hi];
        arr[hi] = arr[i+1];
        arr[i+1] = temp;
    }
    return i+1;
}

void push(int stack[], int *top, int val) {
    (*top)++;
    stack[*top] = val;
}

int pop(int stack[], int *top) {
    int val = stack[*top];
    (*top)--;
    return val;
}

void quickSort(DATA arr[], int n) {
    int stack[n], top=-1, lo=0, hi=n-1, p;
    push(stack, &top, lo);
    push(stack, &top, hi);

    while(top >=0) {
        hi = pop(stack, &top);
        lo = pop(stack, &top);

        p = partition(arr, lo ,hi);

        if (p > lo+1) {
            push(stack, &top, lo);
            push(stack, &top, p-1);
        }

        if (hi > p+1) {
            push(stack, &top, p+1);
            push(stack, &top, hi);
        }
    }   
}

void quickInsSort(DATA arr[], int n, int cutoff) {
    int stack[n], top=-1, lo=0, hi=n-1, p;
    push(stack, &top, lo);
    push(stack, &top, hi);

    while(top >=0) {
        hi = pop(stack, &top);
        lo = pop(stack, &top);

        if (hi-lo+1 <= cutoff) {
            insertionSort(&arr[lo],hi-lo+1);
            continue;
        }

        p = partition(arr, lo ,hi);

        if (p > lo+1) {
            push(stack, &top, lo);
            push(stack, &top, p-1);
        }

        if (hi > p+1) {
            push(stack, &top, p+1);
            push(stack, &top, hi);
        }
    }   
}

