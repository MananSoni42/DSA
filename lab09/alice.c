#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

long int hash(char* str, long long int basenum, long int tablesize) {
    if (str == NULL) {
        return 0;
    }
    int len = strlen(str);
    long long int sum=0;

    for(int i=0;i<len;i++) {
        sum += ((int)str[i])%basenum;
    }
    
    return (sum%basenum)%tablesize;
}

long int count_collision(char** str, int len, long long int basenum, long int tablenum) {
    int arr[tablenum], num=0;
    long int ind;
    memset(arr, 0, tablenum*sizeof(int));
    for (int i=0;i<len;i++) {
        ind = hash(str[i], basenum, tablenum);
        //printf("%d %s %ld\n",i,str[i],hash);
        arr[ind]++;
        if (arr[ind] == 2) {
            num++;
        }
    }
    return num;
}

char** parse(char* fname, int* s) {
    FILE* fstream = fopen(fname, "r");
    int i=0, j, size=100;
    char **arr_temp, **arr = (char**)malloc(size*sizeof(char*));
    char ch[MAX];

    if (!fstream) {
        printf("Could not read file!\n");
        return NULL;
    }

    while(1) {
        fscanf(fstream, "%s", &ch);

        if (feof(fstream)) {
            break;
        }

        if (i == size-1) {
            size=size*2;
            arr_temp = (char**)realloc(arr,size*sizeof(char*));
            arr = arr_temp;
        }

        arr[i] = (char*)malloc(MAX*sizeof(char));
        strcpy(arr[i], ch);

        i++;
    }
    *s = i;
    return arr;
}

int main() {
    int size=0;
    char **strs = parse("lab_sheet/aliceinwonderland.txt",&size);
    printf("size: %d\n",size);

    long int min_coll=size, coll, best_tn, tn[3] = {5000, 50000, 500000};
    long long int best_bn, bn[3][6] =  {
                            {5471,8221,9887,5001167,5001301,5001421}, 
                            {50021,75797,98893,50001299,50001527,50001929}, 
                            {500153,851117,998717,500000489,500001553,500001941}
                        };
    /*
    for (int i=0;i<3;i++) {
        for (int j=0;j<6;j++) {
            printf("%ld %lld\n",tn[i],bn[i][j]);
        }
    }
    */
    for (int i=0;i<3;i++) {
        for (int j=0;j<6;j++) {
            printf("Testing %ld %lld",tn[i],bn[i][j]);
            coll = count_collision(strs,size,bn[i][j],tn[i]);
            printf(" -> %d\n",coll);
            if (coll < min_coll) {
                min_coll = coll;
                best_tn = tn[i];
                best_bn = bn[i][j];
            }
        }
    }

    printf("\n\nBest combination is:\ntable number: %ld, base number: %lld with %d collisions\n",best_tn, best_bn, min_coll);
}
