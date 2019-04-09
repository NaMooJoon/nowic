/**
* Author:		Youngsup Kim
* Description:	This program is written to run and test some recursion algorithms.
*
* On my honour, I pledge that I have neither received nor provided improper
* assistance in the completion of this assignment. Signed: ____YOUR NAME______
*
* To build this program:
*  g++ recursionDriver.cpp recursion.cpp binsearch.cpp quicksort.cpp
*      -I../include -L../lib -lnowic -o recursion
*
* History:
* 2018/02/10	Created
* 2019/02/02	C++ Conversion
*/

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

#include <iostream>
#include <cassert>
using namespace std;

#include "nowic.h"

long long factorial(int N);
long long fibonacci(int N);
int gcd(int a, int b);
int bunnyEars(int a);
int funnyEars(int a);
int triangle(int a);
int sumDigits(int n);
int count8(int n);
long long powerN(int base, int n);
void quickSort(int *list, int N);
int binary_search(int *list, int key, int size);

int main(int argc, char *argv[]) {
	int option;
	int N;

	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdout, NULL, _IONBF, 0);

	while(1) {
		cout << "\n\tRecursive Algorithms:\n"
			"\t1. Factorial\n"
			"\t2. GCD(Great Common Divisor)\n"
			"\t3. Fibonacci\n"
			"\t4. Bunny Ears\n"
			"\t5. Funny Ears\n"
			"\t6. Triangle\n"
			"\t7. Sum of digits\n"
			"\t8. Count 8\n"
			"\t9. Power N\n"
			"\t10. Recursive Binary Search\n";

		switch (option = GetInt("\tCommand(0 to quit): ")) {
		case 0:
			cout << "Happy Coding~~\n";
			exit(EXIT_SUCCESS);

		case 1:
			cout << "\tFactorial Examples:\n";
			cout << "\tfactorial(1) = 1\n";
			cout << "\tfactorial(2) = 2\n";
			cout << "\tfactorial(3) = 6\n";
			cout << "\tfactorial(8) = 40320\n";
			cout << "\tfactorial(12) = 479001600\n";

			while (1) {
				N = GetInt("\tEnter a number to compute N factorial(0 to quit): ");
				if (N <= 0) break;
				cout << "\tfactorial(" << N << ") = " << factorial(N) << endl;
			}
			break;
		case 2:
			cout << "\tGCD Examples:\n";
			cout << "\tgcd(27, 9) = 9\n";
			cout << "\tgcd(111, 259) = 37\n";

			while (1) {
				int x = GetInt("\tEnter 1st number to compute GCD(0 to quit): ");
				if (x == 0) break;
				int y = GetInt("\tEnter 2nd number to compute GCD(0 to quit): ");
				if (y == 0) break;
				cout << "\tgcd(" << x << ", " << y << ") = " << gcd(x, y) << endl;
			}
			break;

		case 3:
			cout << "\tFibonacci Examples:\n";
			cout << "\tfibonacci(0) = 0\n";
			cout << "\tfibonacci(1) = 1\n";
			cout << "\tfibonacci(2) = 1\n";
			cout << "\tfibonacci(3) = 2\n";
			cout << "\tfibonacci(4) = 3\n";
			cout << "\tfibonacci(5) = 5\n";
			cout << "\tfibonacci(6) = 8\n";
			while (1) {
				N = GetInt("\tEnter a number to compute N fibonacci(0 to quit): ");
				if (N <= 0) break;
				cout << "\tfibonacci(" << N << ") = " << fibonacci(N) << endl;
			}
			break;
		case 4:
			cout << "\tbunnyEars(0) = 0\n";
			cout << "\tbunnyEars(1) = 2\n";
			cout << "\tbunnyEars(2) = 4\n";
			cout << "\tbunnyEars(3) = 6\n";
			cout << "\tbunnyEars(234) = 468\n";
			while (1) {
				N = GetInt("\tEnter a number of bunnies(0 to quit): ");
				if (N <= 0) break;
				cout << "\tbunnyEars(" << N << ") = " << bunnyEars(N) << endl;
			}
			break;
		case 5:
			cout << "\tfunnyEars(0) ¡æ 0\n";
			cout << "\tfunnyEars(1) ¡æ 2\n";
			cout << "\tfunnyEars(2) ¡æ 5\n";
			cout << "\tfunnyEars(3) ¡æ 7\n";
			cout << "\tfunnyEars(4) ¡æ 10\n";
			cout << "\tfunnyEars(9) ¡æ 22\n";
			while (1) {
				N = GetInt("\tEnter a number of funnyEars(0 to quit): ");
				if (N <= 0) break;
				cout << "\tfunnyEars(" << N << ") = " << funnyEars(N) << endl;
			}
			break;
		case 6:
			cout << "\ttriangle(0) ¡æ 0\n";
			cout << "\ttriangle(1) ¡æ 1\n";
			cout << "\ttriangle(2) ¡æ 3\n";
			cout << "\ttriangle(3) ¡æ 6\n";
			cout << "\ttriangle(4) ¡æ 10\n";
			cout << "\ttriangle(7) ¡æ 28\n";

			while (1) {
				N = GetInt("\tEnter a number of triangle(0 to quit): ");
				if (N <= 0) break;
				cout << "\ttriangle(" << N << ") = " << triangle(N) << endl;
			}
			break;
		case 7:
			cout << "\tsumDigits(126) = 9\n";
			cout << "\tsumDigits(12) = 3\n";
			cout << "\tsumDigits(1) = 1\n";
			cout << "\tsumDigits(10110) = 3\n";
			cout << "\tsumDigits(235) = 10\n";
			while(1)
			{
				N = GetInt("\tEnter a number of triangle(0 to quit): ");
				if(N <= 0) break;
				cout << "\tsumDigits(" << N << ") = " << sumDigits(N) << endl;
			}
			break;
		case 8:
			cout << "\tcount8(818) ¡æ 2" << endl;
			cout << "\tcount8(8) ¡æ 1" << endl;
			cout << "\tcount8(123) ¡æ 0" << endl;
			cout << "\tcount8(881238) ¡æ 3" << endl;
			cout << "\tcount8(48581) ¡æ 2" << endl;
			cout << "\tcount8(888586198) ¡æ 5" << endl;
			cout << "\tcount8(99899) ¡æ 1" << endl;
			while(1)
			{
				N = GetInt("\tEnter a number of count8(0 to quit): ");
				if(N <= 0) break;
				cout << "\tcount8(" << N << ") = " << count8(N) << endl;
			}
			break;
		case 9:
			cout << "\tpowerN(2, 5) -> 32\n";
			cout << "\tpowerN(3, 1) -> 3\n";
			cout << "\tpowerN(5, 3) -> 125\n";
			cout << "\tpowerN(10, 3) -> 1000\n";
			cout << "\tpowerN(2, 10) -> 1024\n";
			while(1)
			{
				int base = GetInt("\tEnter a number of base(0 to quit: ");
				if(base == 0) break;
				N = GetInt("\tEnter a number of powerN(0 to quit): ");

				if(N <= 0) break;
				cout << "\tpowerN(" << base << "," << N << ") = " << powerN(base, N) << endl;
			}
			break;

		case 10:
			cout << "\tRecursive Binary Search\n ";
			while (1) {
				N = GetInt("\tEnter a list size to generate(0 to quit) : ");
				if (N <= 0) break;

				int *list = new (nothrow) int[N];
				assert(list != nullptr);

				for (int i = 0; i < N; i++)
					list[i] = rand() % N;

				quickSort(list, N);
				for (int i = 0; i < N; i++)
					cout << list[i] << " ";
				cout << endl;

				int key = GetInt("\tEnter a number to search: ");
				int index = binary_search(list, key, N);

				if(index >= 0){
					cout << "\t" << key << '\t' << "is @[" << index << "]\n";
				}else {
					index = -(index + 1);
					cout << "\t" << key << '\t' << "is not @[" << index << "]\n";
				}

				delete[] list;
			}
		default:
			break;
		}
	}

	cout << "Happy Coding~~\n";
	return EXIT_SUCCESS;
}
