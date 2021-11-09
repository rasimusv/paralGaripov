//
// Created by Расим Гарипов on 16.10.2021.
//
#include <omp.h>
#include <cstdio>

int main() {
    int x = 210;
    int result = 0;

#pragma omp parallel for num_threads(6) reduction(+:result)
    for (int i = 1; i < x * 2; i += 2) {
        result += i;
    }
    printf("%d\n", result);
}