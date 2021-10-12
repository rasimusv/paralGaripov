//
// Created by Расим Гарипов on 12.10.2021.
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

    double sumA = 0;
    double sumB = 0;

#pragma omp parallel for reduction(+:sumA, sumB)
    {
    for (int i = 0; i < 10; i++) {
        sumA += a[i];
        sumB += b[i];
    }
}
    if (sumA == sumB) {
        printf("Avg values are equal: %f", sumA / (double) 10);
    } else {
        printf("Avg for a: %f, Avg for b: %f", sumA / (double) 10, sumB / (double) 10);
    }
}