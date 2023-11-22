#include <stdio.h>

int a(int n);
long double b(int n);
int c(int n, int x);

int main(){
    int n = 0;
    int x = 0;
    printf("Podaj n, x: ");
    scanf("%i %i", &n, &x);
    printf("Pkt a: %i\nPkt b: %LF\nPkt c: %i\n", a(n), b(n), c(n, x));
    return 0;
}

//O(1)
int a(int n){
    if(n % 2 != 0) n *= -1;
    return n;
}

//O(n)
long double b(int n){
    long double result = 0;
    for(int i = 1; i <= n; i++){
        if(i % 2 == 0) result += 1/(long double)i;
        else result -= 1/(long double)i;
    }
    return result;
}

//O(n)
int c(int n, int x){
    int result = 0;
    int power = x;
    for(int i = 1; i <= n; i++){
        result += i * power;
        power *= x;
    }
    return result;
}