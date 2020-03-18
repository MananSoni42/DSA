compare: compareSort.c sort.o read_csv.o
	gcc -o compareSort compareSort.c sort.o read_csv.o

test: testSort.c sort.o read_csv.o
	gcc -o testSort testSort.c sort.o read_csv.o

sort.o: sort.c read_csv.h
	gcc -c sort.c

read_csv.o: read_csv.h read_csv.c
	gcc -c read_csv.c
