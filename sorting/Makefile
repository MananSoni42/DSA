all: sort_test.c ${sort}_sort.o sort.o 
	gcc -o sort_test sort_test.c sort.o ${sort}_sort.o

time: sort_time.c ${sort}_sort.o sort.o
	gcc -o sort_time sort_time.c sort.o ${sort}_sort.o

%_sort.o: %_sort.c sort.o
	gcc -c $<

sort.o: sort.c sort.h
	gcc -c sort.c

.PHONY: clean
clean:
	tt *.o
