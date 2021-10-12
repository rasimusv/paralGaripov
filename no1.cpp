//
// Created by Расим Гарипов on 11.10.2021.
//
#include <cstdio>
#include <omp.h>

int main() {
#pragma omp parallel num_threads(8)
    {
        int thread_id = omp_get_thread_num();
        int nthread = omp_get_num_threads();
        printf("Hello world, thread %d of %d\n", thread_id, nthread);
    }
}