#ifndef SORT_H
#define SORT_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 100

typedef struct data {
    int index;
    int data;
} DATA;

DATA* getArr(char* type, int len); // get an array for sorting 
/* Current options are:
 * reverse: reverse sorted array
 * random: array filed with random numbers (in the index)
*/ 

void sort(DATA*,int); // function to sort based on index

void printList (DATA* arr, int len); // print the entire array

void swap(DATA* elem1, DATA* elem2); // swap 2 data elements

#endif
