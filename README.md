

# DSA (CS F211)
* This repository contains code done as a part of the Data Structure and Algorithms course done at BITS Pilani.
* It has 2 main branches - master and experiments.  
	* **[master](https://github.com/MananSoni42/DSA/tree/master)**: Contains code where I explore the different data structures and algorithms that have been taught in the classroom.
	* **[lab](https://github.com/MananSoni42/DSA/tree/lab)**: Contains code for the weekly lab assignments along with the lab sheet for the week (PDF).

P.S.
Check out [Valgrind](https://valgrind.org/). It is a very effective memory management tool which can automatically detect many memory management and threading bugs, and profile your programs in detail.
It has saved hours of my time while debugging (mainly for segfaults).

## Master
### Naming convention
All executable files have the same name as the source file without the extension. For example the executable file for ```reverse.c``` will be stored as ```reverse```.
### Compiling
Compiling files may not be straightforward as the files may depend on several header files within the directory, for ease and usability, a [Makefile](https://www.gnu.org/software/make/manual/html_node/Introduction.html) has been provided in each directory. It can be used to compile all the files in a given directory, some defaults included in each Makefile are:  
```make```: Defaults to the ```make all``` command  
```make all```:  Generate object  and executable files for all relevant source files  
```make clean```: Clean the directory i.e. remove all executable files  

## Overview of sections
### Linked Lists
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

### CSV reader
A program that can display the contents of any given csv. The maximum linewidth is specified in the header file (read_csv.h).
The program focuses on being able to read any given csv file along with the ability to correctly terminate with the correct error code in case of any inconsistencies. Some focus has also been put on displaying the csv in a pleasing manner.

### sorting
Many popular sorting algorithms are implemented.

## Program Tree
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
```
