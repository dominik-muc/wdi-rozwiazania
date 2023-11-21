#include <stdio.h>
#include <stdlib.h>

//Zwraca tablicę 9-elementową, O(log n)
int* count_digits(int n){
    int* result = malloc(sizeof(int) * 9);
    while(n > 0){
        result[n % 10]++;
        n /= 10;
    }
    return result;
}

int diffrent_digits(int n){
    int* digits_n = count_digits(n);
    int result = 0;
    for(int i = 0; i < 10; i++){
        if(digits_n[i] > 0) result++;
    }
    return result;
}

int similar(int n, int m){
    int* digits_n = count_digits(n);
    int* digits_m = count_digits(m);
    for(int i = 0; i < 10; i++){
        if(digits_n[i] != digits_m[i]) return 0;
    }
    return 1;
}

int main(){
    int n = 0;
    int m = 0;
    printf("Podaj n, m: ");
    scanf("%i %i", &n, &m);
    printf("Liczba n jest %i-cyfrowa.\n", diffrent_digits(n));
    printf("Liczba m jest %i-cyfrowa.\n", diffrent_digits(m));
    if(similar(n, m)){
        printf("Liczby n i m są podobne.\n");
        return 0;
    }
    printf("Liczby n i m nie są podobne.\n");
    return 0;
}