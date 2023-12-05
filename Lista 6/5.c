#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* primes(int n);

int main(){
    int n;
    printf("Podaj n: ");
    scanf("%i", &n);
    printf("Liczby pierwsze <2, n>: ");
    int* s = primes(n);
    for(int i = 0; i < n; i++){
        if(!s[i]) printf("%i ", i);
    }
    putchar('\n');
    return 0;
}

//liczba naturalna n -> tablica (wskaźnik do tablicy) n-elementowa s, s[i] = 1 <=> i nie należy do S, s[i] = 0 <=> i należy do S
int* primes(int n){
    int* s = calloc(n, sizeof(int));
    s[0] = 1;
    s[1] = 1;
    for(int i = 2; i < (int)sqrt(n); i++){
        if(!s[i]){
            int j = i + i;
            while(j < n){
                s[j] = 1;
                j += i;
            }
        }
    }
    return s;
}