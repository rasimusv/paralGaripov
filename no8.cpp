//
// Created by Расим Гарипов on 12.10.2021.
//
#include <cstdio>
#include <omp.h>

#define N 1000

int main() {

    int a[N][N];
    int b[N];
    int res[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = i + 98763 - j;
        }

        b[i] = 85745 + (i * 45);
    }

    double start = omp_get_wtime();

    for (int i = 0; i < N; i++)
    {
        float temp = 0;
        for (int j = 0; j < N; j++)
        {
            temp += a[i][j] * b[j];
        }
        res[i] = temp;
    }

    printf("Regular = %f\n", omp_get_wtime() - start);
    start = omp_get_wtime();

#pragma omp parallel for schedule(static, 5) num_threads(8)
    for (int i = 0; i < N; i++) {
        float temp = 0;
        for (int j = 0; j < N; j++)
        {
            temp += a[i][j] * b[j];
        }
        res[i] = temp;
    }

    printf("static = %f\n", omp_get_wtime() - start);
    start = omp_get_wtime();

#pragma omp parallel for schedule(dynamic, 200) num_threads(8)
    for (int i = 0; i < N; i++) {
        float temp = 0;
        for (int j = 0; j < N; j++)
        {
            temp += a[i][j] * b[j];
        }
        res[i] = temp;
    }

    printf("dynamic = %f\n", omp_get_wtime() - start);
    start = omp_get_wtime();

#pragma omp parallel for schedule(guided, 200) num_threads(8)
    for (int i = 0; i < N; i++) {
        float temp = 0;
        for (int j = 0; j < N; j++)
        {
            temp += a[i][j] * b[j];
        }
        res[i] = temp;
    }

    printf("guided = %f\n", omp_get_wtime() - start);
    start = omp_get_wtime();

#pragma omp parallel for schedule(auto) num_threads(8)
    for (int i = 0; i < N; i++) {
        float temp = 0;
        for (int j = 0; j < N; j++)
        {
            temp += a[i][j] * b[j];
        }
        res[i] = temp;
    }

    printf("auto = %f\n", omp_get_wtime() - start);
}