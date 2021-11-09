//
// Created by Расим Гарипов on 16.10.2021.
//
#include <cstdio>
#include <omp.h>
#include <libc.h>

int main() {
    int n = 28;
#pragma omp parallel num_threads(8)
    {
        int thread_id = omp_get_thread_num();
        int nthread = omp_get_num_threads();
        printf("%d\n", thread_id);
#pragma omp atomic
        n -= thread_id;
        sleep(n);
        printf("Hello world, thread %d of %d\n", thread_id, nthread);
    }
}
