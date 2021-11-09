//
// Created by Расим Гарипов on 16.10.2021.
//
#include <cstdio>
#include <omp.h>
#include <ctime>
#include <climits>

#define N 29

int main() {
    int a[N];
    int max = INT_MIN;
    srand(static_cast<unsigned int>(time(0)));


    for (int i = 0; i < N; i++) {
        a[i] = rand() % 999999 + 1;
    }

#pragma omp parallel for num_threads(6)
    for (int i = 0; i < N; i++) {
        if (a[i] % 7 == 0) {
#pragma omp critical
            if (a[i] > max) {
                max = a[i];
            }
        }
    }
    printf("MAX: %d\n", max);
}