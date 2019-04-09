/*On my honor, I pledge that I have neither received
 nor provided improper assistance in the completion
  of this assignment.
  Signed: JunHyeon Kim   Section: 03   Student Number: 21800179*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

int ascending(int a, int b); //{ return a - b; }
int descending(int a, int b); //{ return b - a; }

void selectionSort(int *list, int n, int (*comp)(int, int) = ascending) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (comp(list[min], list[j]) > 0)
				min = j;
		// Swap min found with the first one of unsorted
		temp = list[i];
		list[i] = list[min];
		list[min] = temp;
	}
}


#if 0
void selectionSort(int[], int);

int main(void) {
    int N;
    int* list;

    cout << "Enter the number of samples: ";
    cin >> N;
    if(N < 1) {
        cout << "Improper value of N" << endl;
        return EXIT_FAILURE;
    }

    list = new (nothrow) int[N];
    assert(list != nullptr);

    srand(time(NULL));

    cout << "\nUnSorted array:\n";
    for(int i = 0; i < N; i++) {
        list[i] = rand() % 1000 + 1;
        cout << list[i] << " ";
    }

    selectionSort(list, N);

    cout << "\nSorted array:\n";
    for(int i = 0; i < N; i++) {
        cout << list[i] << " ";
    }
    cout << endl;


    delete list;

    return EXIT_SUCCESS;

}
#endif
