

# DSA (CS F211)
* This repository contains code done as a part of the Data Structure and Algorithms course done at BITS Pilani.
* It has 2 main branches - master and experiments.  
	* **[master](https://github.com/MananSoni42/DSA/tree/master)**: Contains code where I explore the different data structures and algorithms that have been taught in the classroom.
	* **[lab](https://github.com/MananSoni42/DSA/tree/lab)**: Contains code for the weekly lab assignments along with the lab sheet for the week (PDF).

## Master
### Naming convention
All executable files have the same name as the source file without the extension. For example the executable file for ```reverse.c``` will be stored as ```reverse```.
### Compiling
Compiling files may not be straightfoard as the files may depend on several header files within the directory, for ease and usability, a [Makefile](https://www.gnu.org/software/make/manual/html_node/Introduction.html) has been provided that can be used to compile all the files in a given directory 
Commands
```make all```:  Generate object  and executable files for all suitable source files
```make clean```: Clean the directory i.e. remove all object and executable files

## Overview of programs
```
├── linked_list
|	    ├── ll.h # header file for a generic linked list
|	    ├── testll # Verify that the basic linked list functions are correctly implemented
|	    ├── middle # print the middle element of a given list
|	    ├── k_endc # print the kth element from the end
|	    ├── del # delete the entire list
|	    ├── del_alternate # delete alternate nodes
|	    ├── loop # detect and remove loops 
|	    └── reverse # reverse a list 
├── csv_reader
└── sorting 
```
