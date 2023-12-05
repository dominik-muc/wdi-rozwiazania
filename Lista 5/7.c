#include <stdio.h>

int meow(int n, int m){
    int k = 0;
    int curr = 1;
    while (n < curr){
        curr *= m;
        k += 1;
    }
    return k;
}