#include <stdio.h>
#include <stdlib.h>

//Zwraca tablicę 10-elementową, O(log n)
int* count_digits(int n){
    int* result = malloc(sizeof(int) * 10);
    for(int i = 0; i < 10; i++) result[i] = 0;
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
    free(digits_n);
    return result;
}

int similar(int n, int m){
    int* digits_n = count_digits(n);
    int* digits_m = count_digits(m);
    for(int i = 0; i < 10; i++){
        if(digits_n[i] != digits_m[i]){
            free(digits_m);
            free(digits_n);
            return 0;
        }
    }
    free(digits_m);
    free(digits_n);
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