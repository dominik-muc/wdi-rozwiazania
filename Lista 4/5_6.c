#include <stdio.h>

//O(log n)
int is_palindromic(int n, int k){
    int number[32] = {0};
    int size = 0;
    while(n > 0){
        number[size] = n % k;
        n /= k;
        size++;
    }
    for(int i = 0; i < size / 2 + 1; i++){
        if(number[i] != number[size-i-1]) return 0;
    }
    return 1;
}

int main(){
    int n = 0;
    int k = 0;

    printf("Podak n, k: ");
    scanf("%i %i", &n, &k);
    if(is_palindromic(n, k)){
        printf("Jest palindromem k-arnym\n");
        return 0;
    }
    printf("Nie jest palindromem k-arnym\n");
    return 0;
}