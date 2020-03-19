all: test_sort.c ${sort}_sort.o sort.o 
	gcc -o test_sort test_sort.c sort.o ${sort}_sort.o

%_sort.o: %_sort.c sort.o
	gcc -c $<

sort.o: sort.c sort.h
	gcc -c sort.c

.PHONY: clean
clean:
	tt *_sort.o *.o
