//
// Created by Расим Гарипов on 16.10.2021.
//
#include <omp.h>
#include <cstdio>

#define N 30

int main() {
    int a[N] = {1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1};
    int result = 0;
    int power = 1;

#pragma omp parallel for num_threads(6) reduction(+:result)
    for (int i = N - 1; i >= 0; i--) {
#pragma omp critical
        {
            result += a[i] * power;
            power *= 2;
        }
    }
    printf("%d\n", result);
}