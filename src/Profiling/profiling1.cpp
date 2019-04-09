// 03분반 21800179 김준현
/*
On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
Signed: 김준현 Section:  03분반 Student  Number: 21800179
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "sort.h"

using namespace std;

const int STARTING_SAMPLES = 100;

//void selectionSort(int *list, int n);
//void quickSort(int *list, int n);

// a helper function
// Compute the number of digit first.
// For example, 1 for [0..9], 2 for [10..99], 3 for [100..999] and so on.
// Then compute the step: 1 for 1, 10 for 2, 100 for 3 and so on.
int getStep(int n) {
	int digit = 1;
	int step = 1;

	// your code here
	while(step * 10 <= n) {
		step *= 10;
	}

	return step;
}

// rand() returns a random number between 0 and RAND_MAX which is defined in stdlib.h
// RAND_MAX is surprisingly small (30K ~ 50K range, not 1M nor 1B) and also depends
// on the machine.  RAND_MAX is defined as 0x7FFF (or 32767 = 2 ^ 15 - 1)
// The following program will work for random values in the
// range[0, (RAND_MAX + 1)*(RAND_MAX + 1)), providing there's no overflow.

// returns an array filled with random numbers [0..size)
void getRandomSample(int list[], int size) {
	// printf("Preparing the sample data set...(MAX_RAND=%d)\n", RAND_MAX);
	// get a unique sequence
	for (int i = 0; i < size; i++) list[i] = i;

	srand((unsigned)time(NULL));	    // initialize random seed
	for (int i = 0; i < size; i++) {
		int x = (rand() * ((long)RAND_MAX + 1) + rand()) % size;
		int t = list[x];                // swap - the current i with randomly selected x
		list[x] = list[i];
		list[i] = t;
	}
}

//////////////// Step 4: your code here ////////////////////////////////////
/*
void sortProfiling(void (*sortFunc)(int *, int), int *list, int n,
int starting_samples = STARTING_SAMPLES)
{


}
*/


/////////////////////////////////////////////////////////////////////////////
////// Step 5: Turn off this main() and use one in sortDriver3.cpp //////////
/////////////////////////////////////////////////////////////////////////////
#if 1
int main(int argc, char *argv[]) {
	int N = 0;
	int *list;

	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdout, NULL, _IONBF, 0);

	if (argc == 1) {
		string str;
		cout << "The minimum number of entries is set to " << STARTING_SAMPLES << endl;
		cout << "Enter the number of max entries to sort: ";
		getline(cin, str);
		stringstream ss(str);
		ss >> N;
	}
	else if (argc == 2) {
		char *end;
		N = strtol(argv[1], &end, 10);
		if (N <= 0 || *end != '\0')
			std::cout << "Usage: randomN N\n";
	}

	if (N <= STARTING_SAMPLES) {
		cout << "Enter a number much larger than " << STARTING_SAMPLES << ".\n";
		exit(EXIT_FAILURE);
	}

	cout << "The maximum sample data size is " << N << "\n";
	list = new int[N];

	double duration;
	cout << "         n\t repetitions\t   sort(sec)\n";
	for (int i = STARTING_SAMPLES; i <= N; i += getStep(i)) {
		long repetitions = 0;
		clock_t start = clock();
		do {
			repetitions++;
			getRandomSample(list, i);			// shuffle the array
			quickSort(list, i);
			//selectionSort(list, i);
		} while (clock() - start < 1000000);		// run it over one sec

		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		duration /= repetitions;

		cout << fixed;
		cout << setw(10) << i << "\t"
			<< setw(12) << repetitions << "\t"
			<< setw(12) << duration << endl;
	}

	delete list;
	return 0;
}
#endif
