//
// Created by Расим Гарипов on 16.10.2021.
//
#include <omp.h>
#include <iostream>

bool is_prime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    int left;
    int right;
    scanf("%d[\n]", &left);
    scanf("%d[\n]", &right);

#pragma omp parallel for schedule(auto) num_threads(6)
    for (int i = left; i <= right; i++) {
        if (is_prime(i)) {
            printf("%d\n", i);
        }
    }
}