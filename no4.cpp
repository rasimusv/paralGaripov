//
// Created by Расим Гарипов on 11.10.2021.
//
#include <cstdio>
#include <omp.h>

int main() {

    int a[10];
    int b[10];

    for (int i = 0; i < 10; i++) {
        a[i] = i + 100;
        b[i] = 50 - i;
    }

    int max = 0;
    int min = 10000;

#pragma omp parallel num_threads(2)
    {
        if (omp_get_thread_num() == 0) {
            for (int i = 0; i < 10; i++) {
                if (a[i] < min) {
                    min = a[i];
                }
            }
        }
        if (omp_get_thread_num() == 1) {
            for (int i = 0; i < 10; i++) {
                if (b[i] > max) {
                    max = b[i];
                }
            }
        }
    }
    printf("MIN: %d, MAX: %d", min, max);
}