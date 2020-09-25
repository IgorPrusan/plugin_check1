#include<iostream>
#include<fstream>
#include"Header.h"

using namespace std;

bool Is_good(double x) {
	if ((x > 0) && x == (int)x) //"хорошими" числами считаю все натуральные числа
		return true;
	return false;
}

int main(int argc, char* argv[]) {
	double* A;
	int N;
	if (argc > 1) {
		N = argc - 1;
		A = Task_1(N, argv);
	}
	else {
		cout << "No arguments!\nN = ";
		cin >> N;
		A = new double[N];
		for (int i = 0; i < N; ++i) {
			cout << "Enter A[" << i << "]: ";
			cin >> A[i];
		}
	}
	cout << "Got your sequance!\n";

	ofstream file;
	string path;
	cout << "Path to the file with results: ";
	cin >> path;
	file.open(path);

	file << "Initial sequance: \n";
	for (int i = 0; i < N; ++i) {
		file << A[i] << " ";
	}

	bool (*ptrToIsGood)(double) = &Is_good;
	Task_2(A, N, ptrToIsGood);

	file << "\n\"Good\" numbers - natural numbers. \"Bad\" numbers - everything else.\nOrdered sequance: \n";
	for (int i = 0; i < N; ++i) {
		file << A[i] << " ";
	}

	file << "\nThis sequance has " << N << " numbers. Their arithmetical mean = " << Task_3(A, N)<<".\n";

	cout << "Successfully downloaded results in the file \"" << path << "\"!"<<endl;

	return 0;
}