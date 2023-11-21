#include <stdio.h>

//O(log max(a, b))
int nwd(int a, int b){
    if(b == 0)
        return a;
    return nwd(b, a % b);
}

//O(log max(a, b))
int nww(int a, int b){
    return a * b / nwd(a, b);
}

//O(log max(a, b))
void reduce_fraction(int* a, int* b){
    int r = nwd(*a, *b);
    *a /= r;
    *b /= r;
}

int main(){
    int a = 12;
    int b = 48;
    printf("Podaj a, b: ");
    scanf("%i %i", &a, &b);
    printf("NWD: %i\n", nwd(a, b));
    printf("NWW: %i\n", nww(a, b));
    reduce_fraction(&a, &b);
    printf("Skrócony ułamek: %i/%i\n", a, b);
    return 0;
}