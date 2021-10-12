//
// Created by Расим Гарипов on 11.10.2021.
//
#include <cstdio>
#include <omp.h>


int main() {
    int a = 1000;
    int b = 500;

    printf("Task 1\nBefore task: a  %d, b  %d\n", a, b);
#pragma omp parallel num_threads(2) private(a) firstprivate(b)
    {
        int thread_id = omp_get_thread_num();
        a += thread_id;
        b += thread_id;
        printf("In progress: a  %d, b  %d\n", a, b);
    }
    printf("After task: a  %d, b  %d\n\n", a, b);

    printf("Task 2\nBefore task: a  %d, b  %d\n", a, b);
#pragma omp parallel num_threads(4) shared(a) private(b)
    {
        int thread_id = omp_get_thread_num();
        a -= thread_id;
        b -= thread_id;
        printf("In progress: a  %d, b  %d\n", a, b);
    }
    printf("After task: a  %d, b  %d\n", a, b);
}