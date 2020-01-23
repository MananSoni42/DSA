#include <stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
	FILE *fin,*fout;
	if (argc != 3) {
		printf("ERROR: Incorrect number of arguements expected: 2 found: %d\n", argc-1);
		exit(1);
	}

	fin = fopen (argv[1], "r");
	fout = fopen(argv[2], "w");
	if (fin == NULL) {
		printf("ERROR: Could not open input file: %s\n", argv[1]);
		exit(2);
	}
	else if (fout == NULL) {
		printf("ERROR: Could not open output file: %s\n", argv[2]);
		exit(2);
	}
	
	char ch;
	/* incorrect as EOF character is also copied 
	while (!feof(fin)) {
		ch = fgetc(fin);
		fputc(ch,fout);
	}
	*/
	ch = fgetc(fin);
	while (!feof(fin)) {
		fputc(ch,fout);
		ch = fgetc(fin);
	}
	printf("Succesfully copied from %s to file %s\n", argv[1],argv[2]);
	fclose(fin);
	fclose(fout);
	return 0;
}
