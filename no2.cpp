//
// Created by Расим Гарипов on 11.10.2021.
//
#include <cstdio>
#include <omp.h>

int main() {
    int count_of_threads = 3;

#pragma omp parallel num_threads(3) if(count_of_threads > 1 )
    {
        int thread_id = omp_get_thread_num();
        int nthread = omp_get_num_threads();
        printf("Thread %d, count %d\n", thread_id, nthread);
    }

    count_of_threads = 1;

#pragma omp parallel num_threads(3) if(count_of_threads > 1)
    {
        int thread_id = omp_get_thread_num();
        int nthread = omp_get_num_threads();
        printf("Thread %d, count %d\n", thread_id, nthread);
    }
}