//
// Created by Расим Гарипов on 16.10.2021.
//
#include <cstdio>
#include <omp.h>
#include <ctime>

#define N 30

int main() {
    int a[N];
    int count = 0;
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < N; i++) {
        a[i] = rand() % 999999 + 1;
    }

#pragma omp parallel for num_threads(6)
    for (int i = 0; i < N; i++) {
        if (a[i] % 9 == 0) {
#pragma omp atomic
            count += 1;
        }
    }
    printf("Count: %d\n", count);
}