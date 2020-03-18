/** compareSort.c **/

double* testRun(DATA* arr1, int len) {
    struct timeval t1, t2;
    double qt,it;
    double* arr = (double*)malloc(2*sizeof(double));
    DATA* arr2 = (DATA*)malloc(len*sizeof(DATA));
    memcpy(arr2,arr1,len*sizeof(DATA));

    // start timer
    gettimeofday(&t1, NULL);

    insertionSort(arr1,len);

    // stop timer
    gettimeofday(&t2, NULL);

    // compute and print the elapsed time in millisec
    it = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
    it += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms

    // start timer
    gettimeofday(&t1, NULL);

    quickSort(arr2,len);

    // stop timer
    gettimeofday(&t2, NULL);

    // compute and print the elapsed time in millisec
    qt = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
    qt += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms

    free(arr2);

    arr[0] = it;
    arr[1] = qt;

    return arr;
}

int estimateCutoff(DATA* arr, int len) {
    int lo = 0, hi = len, mid;
    double err = 0.001;
    double *tarr;
    DATA* copy_arr = (DATA*)malloc(len*sizeof(DATA));

    do {
        mid = (lo+hi)/2;
        memcpy(copy_arr, arr, mid*sizeof(DATA));
        tarr = testRun(copy_arr, mid);

        if (tarr[0] > tarr[1]) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    } while (abs(tarr[0]-tarr[1] >= err));

    free(copy_arr);
    free(tarr);

    return mid;
}

int main(int argc, char **argv) {

    if (argc < 3) {
        printf("Usage: ./compareSort <inFile> <outFile>\n");
        return 1;
    }

    int len=0;
    DATA* arr = read_from_csv(argv[1], &len);

    int cutoff = estimateCutoff(arr,len);

    struct timeval t1,t2;
    double time;

    // start timer
    gettimeofday(&t1, NULL);

    quickInsSort(arr,len,cutoff);

    // stop timer
    gettimeofday(&t2, NULL);

    // compute and print the elapsed time in millisec
    time = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
    time += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
    printf("n: %10d, cutoff: %3d, time: %f\n", len, cutoff, time);

    FILE* fptr = fopen(argv[2],"w");
    if (fptr == NULL) {
        printf("Could not open file: %s!\n",argv[2]);
    }
    for (int i=0;i<len;i++) {
        fprintf(fptr,"%s,%d\n", arr[i].name, arr[i].empID);
    }
    fclose(fptr);

    return 0;
}

/** read_csv.c **/
#define MAX 100
#define FIELDS 2

DATA *read_from_csv(char* f, int *len) {
    char line[MAX],buffer[MAX];
    char *tok,*lptr;
    bool err=false;
    int k=0,size=10,i;
    DATA *arr = (DATA*)malloc(sizeof(DATA)*size);

    FILE* fstream = fopen(f,"r");

    if (!fstream) {
        printf("ERROR! Could not open file: %s\n",f);
        return NULL;
    }

    while(1) {
        if (err) {
            printf("An error occured\n");
            break;
        }

        if (k == size) {
            size*=2;
            arr = realloc(arr,sizeof(DATA)*size);
        }

        fgets(line,MAX,fstream); // read a line from the text file

        lptr = line; // use a ptr to string for easier string manipulations

        tok = strtok(lptr,",");
        for (i=0;i<FIELDS;i++) {

            if (tok == NULL) { // catch any unknown errors
                err = true;
                break;
            }

            switch(i) {
                case 0: strcpy(arr[k].name, tok); break;
                case 1: strcpy(buffer,tok); arr[k].empID = atol(buffer); break;
            }
            tok = strtok(NULL,",");
        } k++;

        if (feof(fstream)) { break; }
    }

    fclose(fstream);
    *len = (k>1)?k-1:0;
    return arr;
}

/** sort.c **/
void insertionSort(DATA arr[], int n) {
    int i, j;
    DATA key;

    for (i=1;i<n;i++) {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j].empID > key.empID) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int partition(DATA arr[], int lo, int hi) {
    int i=lo-1, j;
    DATA x=arr[hi], temp;
    for (j=lo;j<hi;j++) {
        if (arr[j].empID <= x.empID) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        temp = arr[hi];
        arr[hi] = arr[i+1];
        arr[i+1] = temp;
    }
    return i+1;
}

void push(int stack[], int *top, int val) {
    (*top)++;
    stack[*top] = val;
}

int pop(int stack[], int *top) {
    int val = stack[*top];
    (*top)--;
    return val;
}

void quickSort(DATA arr[], int n) {
    int stack[n], top=-1, lo=0, hi=n-1, p;
    push(stack, &top, lo);
    push(stack, &top, hi);

    while(top >=0) {
        hi = pop(stack, &top);
        lo = pop(stack, &top);

        p = partition(arr, lo ,hi);

        if (p > lo+1) {
            push(stack, &top, lo);
            push(stack, &top, p-1);
        }

        if (hi > p+1) {
            push(stack, &top, p+1);
            push(stack, &top, hi);
        }
    }
}

void quickInsSort(DATA arr[], int n, int cutoff) {
    int stack[n], top=-1, lo=0, hi=n-1, p;
    push(stack, &top, lo);
    push(stack, &top, hi);

    while(top >=0) {
        hi = pop(stack, &top);
        lo = pop(stack, &top);

        if (hi-lo+1 <= cutoff) {
            insertionSort(&arr[lo],hi-lo+1);
            continue;
        }

        p = partition(arr, lo ,hi);

        if (p > lo+1) {
            push(stack, &top, lo);
            push(stack, &top, p-1);
        }

        if (hi > p+1) {
            push(stack, &top, p+1);
            push(stack, &top, hi);
        }
    }
}
 /** testSort.c **/
 
 int main() {
     int len=0;
     DATA* arr = read_from_csv("lab_sheet/1000", &len);
     printf("length: %d\n\n",len);

     printf("%s %d\n",arr[0].name,arr[0].empID);
     printf("%s %d\n",arr[1].name,arr[1].empID);
     printf("%s %d\n",arr[2].name,arr[2].empID);
     printf("%s %d\n",arr[len-3].name,arr[len-3].empID);
     printf("%s %d\n",arr[len-2].name,arr[len-2].empID);
     printf("%s %d\n",arr[len-1].name,arr[len-1].empID);

     quickSort(arr,len); printf("\n");

     printf("%s %d\n",arr[0].name,arr[0].empID);
     printf("%s %d\n",arr[1].name,arr[1].empID);
     printf("%s %d\n",arr[2].name,arr[2].empID);
     printf("%s %d\n",arr[len-3].name,arr[len-3].empID);
     printf("%s %d\n",arr[len-2].name,arr[len-2].empID);
     printf("%s %d\n",arr[len-1].name,arr[len-1].empID);

     return 0;
 }
