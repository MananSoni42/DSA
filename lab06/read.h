#define STRMAX 20

typedef struct data {
    char name[STRMAX];
    double cgpa;
} DATA;

DATA* read_from_csv(char*,int*);
