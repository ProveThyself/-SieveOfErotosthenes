#include <iostream>
#include <cstdio>

const int max_size = 1000000;

void eratosthenes(int n) {
    int isPrime[n + 1];
    
    for (int i = 0; i <= n; ++i) {
        isPrime[i] = true;
    }
    
    isPrime[0] = isPrime[1] = false;
    
    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
    
    printf("Простые числа до %d: ", n);
    for (int p = 2; p <= n; ++p) {
        if (isPrime[p]) {
            printf("%d ", p);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Введите число n: ");
    scanf("%d", &n);
    if (n < 2) {
        printf("Нет простых чисел в диапазоне до %d.\n", n);
    } 
    else if (n > max_size) {
        printf("Пожалуйста, введите число не больше %d.\n", max_size);
    } 
    else {
        eratosthenes(n);
    }
    
    return 0;
}