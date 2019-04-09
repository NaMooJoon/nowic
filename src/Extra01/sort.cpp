// Extra pset // sort.cpp
// 21800179 ������

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <sstream>
#include <iomanip>
#include "nowic.h"
#include "sort.h"
using namespace std;


void random_list(int* list, int N);
void print_list(int *list, int N);
void pass_func(int* list, int N);

//int ascending(int a, int b) { return a - b; }
//int descending(int a, int b) { return b - a; }

#if 1
int main( int argc, char* argv[] ) {
	int N;
	int* list = nullptr;
	clock_t start, end;
	srand(time(nullptr));
	void (*fp[])(int*, int, int comp(int, int)) = { bubbleSort, insertionSort,
							 						quickSort, selectionSort };
	string func_sort[] = {"Bubble", "Insertion", "Quick", "Selection"};
	// Get the size from user interactively.
	if(argc > 1) {
		stringstream ss(argv[1]);
		ss >> N;
	}else {
		N = GetInt("Enter a number of samples: ");
	}

	if(N <= 0) {
		cout << "Your input(0) cannot be processed." << endl << "Usage: sort [N]\n";
		exit(EXIT_FAILURE);
	}

	list = new (nothrow) int[N];
	assert(list != nullptr);

	random_list(list, N);

	cout << "Test Case: Not passing a function pointer: quickSort(list, N)" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout.width(10);
	cout << "NOTsorted:";
	print_list(list, N);

	selectionSort(list, N);

	cout.width(10);
	cout << "sorted:";
	print_list(list, N);

	random_list(list, N);

	cout << endl;
	cout << "Test Case: Passing a function pointer: quickSort(list, N, up)" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout.width(10);
	cout << "NOTsorted:";
	print_list(list, N);

	quickSort(list, N, ascending);

	cout.width(10);
	cout << "sorted:";
	print_list(list, N);

	cout << endl;
	cout << "Test Case: Passing a function pointer: quickSort(list, N, dn)" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout.width(10);
	cout << "NOTsorted:";
	print_list(list, N);

	quickSort(list, N, descending);

	cout.width(10);
	cout << "sorted:";
	print_list(list, N);

	cout << endl;
	cout << "Test Case: Using an array of function pointers" << endl;
	cout << "----------------------------------------------" << endl;

	int fun_size = sizeof(func_sort) / sizeof(func_sort[0]);
	for(int i = 0; i < 4; i++) {
		random_list(list, N);
		cout << "NOTsorted[" << setw(6) << func_sort[i] << "]:";
	 	print_list(list, N);
		// sort
		cout << "Up sorted[" << setw(6) << func_sort[i] << "]:";
		start = clock();
		fp[i](list, N, ascending);
		end = clock();
		print_list(list, N);
		cout << "-->Duration: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds\n";

		cout << "Dn sorted[" << setw(6) << func_sort[i] << "]:";
		start = clock();
		fp[i](list, N, descending);
		end = clock();
		print_list(list, N);
		cout << "-->Duration: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds\n";

		cout << "\n\n";
	}


	delete[] list;
	cout << "Happy Coding~~\n";

	return EXIT_SUCCESS;
}
#endif


void random_list(int* list, int N) {
	for (int i = 0; i < N; i++)
		list[i] = rand() % N + 1;
}

void print_list(int *list, int N) {
	for (int i = 0; i < N; i++)
		cout << " " << list[i];
	cout << endl;
}

void pass_func(int* list, int N) {
	cout.width(10);
	cout << "NOTsorted:";
	print_list(list, N);

	quickSort(list, N);

	cout.width(10);
	cout << "sorted:";
	print_list(list, N);
}
