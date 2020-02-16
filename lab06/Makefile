rec: merge_rec.o read.o
		 gcc -o merge_test_rec merge_test.c merge_rec.o read.o

iter: merge_iter.o read.o
		gcc -o merge_test_iter merge_test.c merge_iter.o read.o

read.o: read.c read.h
		gcc -c read.c

merge_iter.o: merge_iter.c
		gcc -c merge_iter.c

merge_rec.o: merge_rec.c
		gcc -c merge_rec.c
