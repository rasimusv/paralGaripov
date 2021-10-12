//
// Created by Расим Гарипов on 12.10.2021.
//
#include <cstdio>
#include <omp.h>

int main() {
    int a[12];
    int b[12];
    int c[12];

#pragma omp parallel for schedule(static, 3) num_threads(3)
    for (int i = 0; i < 12; i++) {
        a[i] = i + 100;
        b[i] = 50 - i;
        printf("a: %d,  b: %d, thread %d of %d\n", a[i], b[i], omp_get_thread_num(), omp_get_num_threads());
    }

#pragma omp parallel for schedule(dynamic, 3) num_threads(4)
    for (int i = 0; i < 12; i++) {
        c[i] = a[i] + b[i];
        printf("a: %d,  b: %d, thread %d of %d\n", a[i], b[i], omp_get_thread_num(), omp_get_num_threads());
    }
}