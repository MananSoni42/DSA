#include<stdio.h>
/*
 * Observation: Address of goa,hyd,dubai is same and different from the address of bits
 *              while the adress of pilani changes in each function call 
 * This program shows that local variables are deterministically assigned
 * the same memory block by the compiler and this block is unallocated as
 * soon as the scope of the variable ends.
**/ 

int bits=0;

void p(int n) {
    int pilani = n;
    printf("Adress of pilani in %d: %u\n",n,&pilani);

    if (n > 50) {
        return;
    }
    p(n+1);
}

void g() {
    int goa;
    printf("Adress of goa: %u\n",&goa);
}

void h() {
    int hyd;
    printf("Adress of hyderabad: %u\n",&hyd);
}

void d() {
    int dubai;
    printf("Adress of dubai: %u\n",&dubai);
}

int main() {
    printf("Address of bits: %u\n",&bits);
    g();
    h();
    d();
    p(1);
}
