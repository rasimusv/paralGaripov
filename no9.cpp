//
// Created by Расим Гарипов on 16.10.2021.
//
#include <cstdio>
#include <omp.h>
#include <climits>
#include <ctime>


#define N 6
#define M 8

int main() {
    int min = INT_MAX;
    int max = INT_MIN;
    int d[N][M];

    srand(static_cast<unsigned int>(time(0)));


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            d[i][j] = rand() % 999999 + 1;
        }
    }

#pragma omp parallel for num_threads(6)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

#pragma omp critical
            if (d[i][j] > max) {
                max = d[i][j];
            }

#pragma omp critical
            if (d[i][j] < min) {
                min = d[i][j];
            }
        }
    }

    printf("MIN: %d, MAX: %d", min, max);
}