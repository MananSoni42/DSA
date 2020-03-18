#include<stdio.h>
#include "sort.h"
#include "read_csv.h"

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
