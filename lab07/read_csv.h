#ifndef READ_CSV_H
#define READ_CSV_H

#define STRMAX 20

typedef struct data {
    char name[STRMAX];
    long empID;
} DATA;

DATA* read_from_csv(char*,int*);

#endif
