#include<iostream>

void Task_2(double* A, int N, bool (*is_good)(double)) {
    for (int j = 0; j < N; j++) {
        bool flag = false;
        for (int i = 0; i < N - 1; ++i) {
            if (is_good(A[i])) {
                std::swap(A[i], A[i + 1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
}

double Task_3(double* A, int N) {
    double arithmeticalMean = 0;
    for (int i = 0; i < N; ++i) {
        arithmeticalMean += A[i];
    }
    return arithmeticalMean /= N;
}