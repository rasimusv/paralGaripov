//
// Created by Расим Гарипов on 11.10.2021.
//
#include <cstdio>
#include <omp.h>
#include <climits>
#include <ctime>

int main() {
    srand(time(0));

    int d[6][8];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            d[i][j] = rand() % 999999 + 1;
        }
    }
#pragma omp parallel sections shared(d)
    {
#pragma omp section
        {
            double sum = 0;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    sum += d[i][j];
                }
            }
            int thread_id = omp_get_thread_num();
            printf("Thread %d, avg = %f\n", thread_id, (sum / (double) (6 * 8)));
        }
#pragma omp section
        {
            int max = INT_MIN;
            int min = INT_MAX;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    if (d[i][j] < min) {
                        min = d[i][j];
                    }
                    if (d[i][j] > max) {
                        max = d[i][j];
                    }
                }
            }
            int thread_id = omp_get_thread_num();
            printf("Thread %d, min = %d, max = %d\n", thread_id, min, max);
        }
#pragma omp section
        {
            int count = 0;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    if (d[i][j] % 3 == 0) {
                        count++;
                    }
                }
            }
            int thread_id = omp_get_thread_num();
            printf("Thread %d, count = %d\n", thread_id, count);
        }
    }
}