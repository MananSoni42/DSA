#include<stdio.h>
#include "read_csv.h"

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("usage: ./read_csv <file name> [seperator]\n");
        return 3;
    }
    char *fname = argv[1];
    char sep = argv[2][0];
      
    int err_code = read_from_csv(fname,sep);
    return err_code;
}
