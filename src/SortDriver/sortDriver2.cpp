/*On my honor, I pledge that I have neither received
 nor provided improper assistance in the completion
  of this assignment.
  Signed: JunHyeon Kim   Section: 03   Student Number: 21800179*/


/*
* Lecture Note by idebtor@gmail.com
*
* This program is written to run the sort algorithms.
* It takes the number of data samples to sort from the user.
* Then, the int array is created and filled with random numbers.
* User may selection one of sort functions to be used. Then
* execution time and its output is displayed.
*
* History:
* 02/10/19:		Created in C++
*
* Before Compilation, you must have some files (static library and
* include file) ready as shown below:
*   src/selection.cpp, bubble.cpp ...
*   include/nowic.h
*	lib/libnowic.a        (nowic.lib for Visual Studio)
* Compilation:
*	g++ selection.cpp insertion.cpp quicksort.cpp bubble.cpp
*       sortDriver.cpp -I../include -L../lib -lnowic -o sort
*/

#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include "nowic.h"

using namespace std;

void bubbleSort(int *list, int n);
void insertionSort(int *list, int n);
void quickSort(int *list, int n);
void selectionSort(int *list, int n);

void printList(int *list, int n, int max_print, int per_line);
void randomize(int list[], int n);

// Randomize: shuffle the sequence
// For every sample, starting from the first element in the list,
// it is swapped with the element randomly selected by the index
// generated by a 'real' (not pseudo) random number out of from
// 0 to N - 1.
// Hint: Refer to rand() and srand() function document.
void randomize(int list[], int n) {
	DPRINT(cout << ">randomize...N=" << n << endl;)
	srand((unsigned)time(NULL));

	int randomNumber;
	int temp;
	//cout << "your code here\n";
	for(int i = 0; i < n; i++) {
		randomNumber = rand() % n;
		temp = list[i];
		list[i] = list[randomNumber];
		list[randomNumber] = temp;
	}

	DPRINT(cout << "<randomize" << endl;)
}

// When we have a long list, we want to print some in the front
// part of the list and some in the rear part of the list.
//
// The max+print specifies the number of samples in either front
// or rear part of the list.  The per_line determines how many
// samples prints per line.
//
// If max_print is larger than or equal to the sample size N,
// prints max_print/2 samples only.
// For example:
// Case 1) N = 12, max_print = 100, per_line = 20
//		0	1	2	3	4	5
//		6	7	8	9  10  11
// Case 2) N = 12, max_print = 100, per_line = 4
//		0	1	2	3
//		4	5
//		6	7	8	9
//	   10  11
// Case 3) N = 12, max_print = 4, per_line = 6
//		0	1	2	3
//		8	9  10  11
// There should be a line feed between the front part and
// the rear part.
// Observe the sample runs using sortx.exe provided with you.

// Optionally, you may have this kind of a help function.
// void _printList(int *list, int start, int end, int per_line)

void printList(int *list, int N, int max_print, int per_line) {
	DPRINT(cout << ">printList...N=" << N << " max_print=" << max_print << endl;)
		int size;
		int count = 0;
		// your code here
		// Optionally, you may create a help function such as _printList()/
		(N <= max_print)? (size = N/2) : (size = max_print);
		// print the first part.
		for(int i = 0; i < size; i++) {
			count ++;
			cout << "\t" << list[i];
			if(count % per_line == 0)
				cout << "\n";
		}
		cout << "\n\n";
		count = 0;
		// print the rear part.
		for(int i = N - size; i < N; i++) {
			count ++;
			cout << "\t" << list[i];
			if(count % per_line == 0)
				cout << endl;
		}

		//cout << "your code here\n";

	DPRINT(cout << "<printList" << endl;)
}

// sortDriver to test sort functions or algorithms.
int main(int argc, char *argv[]) {
	int N = 0;						// default sample size
	int keyin;
	int *list = NULL;				// input and output buffer
	int max_print = 10;				// default max_print(=front_part+last_part)
	int per_line = max_print / 2;	// default samples per line to print
	clock_t start, end;
	char randomized = 'N';
	char option_char;
	char option_str[512];
	char algorithm_list[4][20] = {"Bubble", "Insertion", "Quicksort", "Selection"};
	enum algorithm_enum { BUBBLE, INSERTION, QUICKSORT, SELECTION };
	int  algorithm_chosen = SELECTION;  // default algorithm chosen
	DPRINT(cout << ">main...N=" << N << endl;)
    // Funtion pointer
    void (*Sort)(int*, int);

	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdout, NULL, _IONBF, 0);

	do {
		sprintf(option_str, "[sort=%s N=%d randomized=%c max_print=%d per_line=%d]",
			algorithm_list[algorithm_chosen], N, randomized, max_print, per_line);
		cout << "\n\tOPTIONS: " << option_str << "\n"
			"\tn - number of samples size and initialize\n"
			"\tr - randomize(shuffle) samples\n"
			"\ta - algorithm to run\n"
			"\ts - sort()\n"
			"\tm - max samples to display at front or rear\n"
			"\td - max samples to display per line\n";


		option_char = GetChar("\tCommand(q to quit): ");
		DPRINT(cout << "option_char = " << option_char << endl;)

		switch (option_char) {
		case 'a': DPRINT(cout << "case = " << option_char << endl;)

			switch (GetChar("\tEnter b for bubble, i for insertion, s for selection, q for quick sort: ")) {

			// your code here
			case 'b': 	algorithm_chosen = BUBBLE;
                        Sort = bubbleSort;
						break;
			case 'i':	algorithm_chosen = INSERTION;
                        Sort = insertionSort;
						break;
			case 's':	algorithm_chosen = SELECTION;
                        Sort = selectionSort;
						break;
			case 'q':	algorithm_chosen = QUICKSORT;
                        Sort = quickSort;
						break;

			default: { cout << "\tNo such an algorithm available. Try it again.\n"; break; }
			}

			//////////////
			break;

		case 'n': DPRINT(cout << "case = " << option_char;)

			keyin = GetInt("\tEnter input sample size: ");
			if (keyin < 1) {
				cout << "\tExpecting a number larger than 0";
				break;
			}

			// set N with the new keyin value
			N = keyin;
			// before allocating the new list, free the old list if not NULL
			if(list != NULL)  delete [] list;
			// allocate memory for new data samples
			list = new (nothrow) int[N];
			assert(list != nullptr);

			randomized = 'N';
			// Fill the list with numbers from 0 to n - 1.
			for(int i = 0; i < N; i++)
				list[i] = i;
			// Print the new list and go the menu.
			printList(list, N, max_print, per_line);

			//cout << "your code here\n";

			break;

		case 'r': DPRINT(cout << "case = " << option_char << endl;)
			if (N <= 1) {
				cout << "\tSet sample size first or larger\n";
				break;
			}

			//cout << "your code here\n";
			randomize(list, N);
			// print the result.
			printList(list, N, max_print, per_line);

			break;

		case 's': DPRINT(cout << "case = " << option_char << endl;)
			if (N <= 0) {
				cout << "\tSet sample size first\n";
				break;
			}
			cout << "\tThe clock ticks and " << algorithm_list[algorithm_chosen] << " begins...\n";

			//cout << "your code here\n";
            start = clock();
            Sort(list, N);
            end = clock();
			// print the result.
			printList(list, N, max_print, per_line);

			cout << "\tDuration: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds\n";
			break;

		case 'm': DPRINT(cout << "case = " << option_char << endl;)

			//cout << "your code here\n";
			keyin = GetInt("\tEnter max sample size to display:");
			if(keyin < 1) {
				cout << "\tExpecting a number larger than 0";
				break;
			}

			max_print = keyin;

			break;
		case 'd': DPRINT(cout << "case = " << option_char << endl;)

			//cout << "your code here\n";
			keyin = GetInt("\tEnter max sample per line to diplay:");
			if(keyin < 1) {
				cout << "\tExpecting a number larger than 0";
				break;
			}

			per_line = keyin;

			break;
		default:
			break;
		}
	} while (option_char != 'q');

	if (list != NULL) free(list);
	// system("pause");
	DPRINT(cout << ">main" << endl;)
	return EXIT_SUCCESS;
}
