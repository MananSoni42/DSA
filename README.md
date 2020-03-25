# DSA (CS F211)
* This repository contains code where I implement and explore the various Data Structures and Algorithms. This code was mainly written while I was studying Data Structure and Algorithms course (CS F211) at BITS Pilani.
* It has 2 branches - master and lab.  
	* **[master](https://github.com/MananSoni42/DSA/tree/master)**: Contains code where I explore the different data structures and algorithms that have been taught in the classroom.
	* **[lab](https://github.com/MananSoni42/DSA/tree/lab)**: Contains code for the weekly lab assignments along with the lab sheet for the week (PDF).

P.S.
Check out [Valgrind](https://valgrind.org/). It is a very effective memory management tool which can automatically detect many memory management and threading bugs, and profile your programs in detail.  
<img src="https://thumbs.gfycat.com/GentleTimelyFox-size_restricted.gif" width="150" height="100" />  
It has saved hours of my time while debugging (mainly for segfaults).

## Naming convention
All executable files have the same name as the source file without the extension. For example the executable file for ```reverse.c``` will be stored as ```reverse```.
## Compiling
Compiling files may not be straightforward as the files may depend on several header files within the directory, for ease and usability, a [Makefile](https://www.gnu.org/software/make/manual/html_node/Introduction.html) has been provided in each directory. It can be used to compile all the files in a given directory, some defaults included in each Makefile are:  
```make```: Defaults to the ```make all``` command  
```make all```:  Generate object  and executable files for all relevant source files  
```make clean```: Clean the directory i.e. remove all executable files  

# Overview of sections
1. [Linked Lists](#Linked-Lists)
2. [CSV reader](#CSV-reader)
3. [Sorting](#Sorting) 
4. [Program Tree](#Program-Tree)

# Linked Lists
Create a (singly) Linked List ADT with the following operators:
* newList() - create a new Linked List
* addAfter(LL, elem, newElem) - add newElem after elem in the LL if elem exists in the LL
* addBefore(LL, elem, newElem) - add newElem before elem in the LL if elem exists in the LL
* deleteElem(LL, elem) - delete elem from LL if it exists
* printList(LL) - print the entire LL

Using the given ADT, different Linked Lists problems are tackled, these include:
* finding the middle element
* deleting the entire list
* delete alternate elements of the list
* Find the kth element from the end
* Reverse the given linked list (recursive and iterative implementations)
* Detect loops in a given linked list

# CSV reader
A program that can display the contents of any given csv. The maximum linewidth is specified in the header file (read_csv.h).
The program focuses on being able to read any given csv file along with the ability to correctly terminate with the correct error code in case of any inconsistencies. Some focus has also been put on displaying the csv in a pleasing manner.

# Sorting
Many popular sorting algorithms are implemented in a (hopefully) generalizable manner. The data structure used to hold the data has 2 fields:
index - Must be positive integers between 0 and MAX-1
data - Can be arbitrary
Sorting is performed by comparing the indices only. 

## implementaion
All sorting algorithms are stored in seperate files. E.g if you wanted to implement selection sort, write a function sort:
```void sort(DATA* arr, int len)``` in selection_sort.c. (It is important that you store the file with the correct name as this is required by the Makefile). 

## Makefile
The makefile for the sorting is a bit different as it takes a command line arguement namely sort. You can do the following
```
make sort=quick  # compiles sort_test using the quick sort implementation provided at quick_sort.c
make time sort=quick  # compiles sort_time using the quick sort implementation provided at quick_sort.c
make clean
```

## Usage
To test your sorting algorithm, a program - sort_test has been provided. It takes 2 command line arguments - the size and type of the array. Suppose you wanted to test your implementation of selection sort with a reverse sorted array of size 42. You would need to write:
```
make sort=selection
./sort_test 42 reverse
```
For timing your sorting algorithm, a utility sort_time is provided.
E.g:
```
make time sort=selection
./sort_time 1 10000 5 selection results.csv
```
This would time your sorting algorithm for numbers from 1 to 10,000 increasing by 5 each time (1, 6, 11, ..., 9991, 9996) and store the results in results.csv

The sorts implemented over here are:
* O(n*n): Selection sort, Bubble sort, Insertion sort
* O(n*lgn): Merge sort, Heap sort, Quick sort
* O(n): Counting sort, Radix sort

## Comparing the sorts (time v/s size)
1. Sorting arrays initialized using random values
![results for sorting random arrays](https://github.com/MananSoni42/DSA/blob/master/sorting/random_sort.png)

2. Sorting arrays that are intially reverse sorted
![results for sorting random arrays](https://github.com/MananSoni42/DSA/blob/master/sorting/reverse_sort.png)

# Program Tree
```
├── linked_list				
|	    ├── ll.h 		# header file for a generic linked list
|	    ├── testll 		# Verify that the basic linked list functions are correctly implemented
|	    ├── middle 		# print the middle element of a given list in O(n) time
|	    ├── k_end 		# print the kth element from the end in O(n) time
|	    ├── delete 		# delete the entire list
|	    ├── del_alternate 	# delete alternate nodes
|	    ├── loop 		# detect loops in a list
|	    ├── reverse_iter 	# reverse a list iteratively ( O(n) time, O(1) space )
|	    ├── reverse_rec 	# reverse a list recursively ( O(n) time, O(n) space )
|	    └── Makefile 	# Apart from the usual, make <executable> - create executable for the specific code E.g - make middle
├── csv_reader
|	    ├── read_csv.h 	# header file - contains constants for max linewidth and max allowed fields
|	    ├── read_csv.c 	# contains the bulk of the code used to read the csv line by line
|	    ├── test_read_csv 	# executable file that can read given csvs (given as command line arguements)
|	    └── Makefile 	# makefile
└── sorting
|	    ├── sort.h 	# header file - contains constants for max integer permitted in index
|	    ├── sort_test.c 	# test a particular sorting algorithm - takes command line arguements
|	    ├── sort_time.c 	# test a particular sort and measure the time taken to run the sorting algorithm - takes command line arguements
|	    ├── bubble_sort.c
|	    ├── insertion_sort.c
|	    ├── selection_sort.c
|	    ├── merge_sort.c
|	    ├── quick_sort.c 	# has options to choose partitions - first element, last element, random element, median of 3 random element
|	    ├── heap_sort.c
|	    ├── counting_sort.c # may throw segmentation fault work if MAX (defined in sort.h) is too large
|	    ├── radix_sort.c
|	    └── Makefile 	# makefile
```
