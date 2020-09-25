#include<cmath>

double* Task_1(int N, char** argv) {
	double* A = new double[N];
	for (int i = 0; i < N; ++i) {
		A[i] = atof(argv[i + 1]);
	}
	return A;
}