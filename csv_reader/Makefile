all: read_csv.o
	gcc -o test_read_csv test_read_csv.c read_csv.o

read_csv.o: read_csv.c read_csv.h
	gcc -c read_csv.c

.PHONY: clean
clean:
	rm -f test_read_csv *.o
