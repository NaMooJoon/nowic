// quicksort.cpp by idebtor@gmail.com
// A typical recursive implementation of quick sort
// 2018.12.15

#include <iostream>
#include <cstdlib>
#include <cmath>

#include "listds.h"
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

/* This function takes last element as pivot, places the pivot element at its
correct position in sorted array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right of pivot */
Node* partition(Node* lo, Node* hi) {
	int x = hi->item;     // set pivot as hi value
	Node* i = lo->prev;   // Index of smaller element

	for (Node* j = lo; j != hi; j = j->next) {
		// If current element is smaller than or equal to pivot
		if (j->item <= x) {
			i = (i == nullptr) ? lo : i->next;    // increment index of smaller element
			swap(i->item, j->item);               // Swap current element with index
		}
	}
	i = (i == nullptr) ? lo : i->next;
	swap(i->item, hi->item);
	return i;
}

// QuickSort helper function for recursive operation
// list[]: array to be sorted, lo: Starting index, h: Ending index
// N is added only for debugging or DPRINT
void _quickSort(Node* lo, Node* hi) {
	if (lo != nullptr && lo != hi && lo != hi->next) {
		Node* p = partition(lo, hi); // Partitioning index
		_quickSort(lo, p->prev);
		_quickSort(p->next, hi);
	}
}

// quick sort algorithm, comp() is not implemented yet.
void quickSort(List* head, int(*comp)(int, int)) {
	_quickSort(begin(head), last(head));
}

void bubbleSort(List* p, int(*comp)(int, int)) {
	bool swapped = true;
	DPRINT(cout << ">bubbleSort N=" << size(p) << endl;);
	if (sorted(p)) return reverse(p);

	Node* tail = end(p);
	Node* curr;
	for (Node* i = begin(p); i != end(p) && swapped; i = i->next) {
		swapped = false;
		for (curr = begin(p); curr->next != tail; curr = curr->next) {
			if (comp(curr->item, curr->next->item) > 0) {
				swap(curr->item, curr->next->item);
				swapped = true;
			}
		}
		DPRINT(show(p, false););
		tail = curr;
	}
	DPRINT(cout << "<bubbleSort N=" << size(p) << endl;);
}


void bubbleSort2(List* p, int(*comp)(int, int)) {
	bool swapped;
	DPRINT(cout << ">bubleSort2 N=" << size(p) << endl;);
	if (sorted(p)) return reverse(p);

	Node* tail = end(p);
	do {
		swapped = false;
		Node* curr = begin(p);
		while (curr->next != tail) {
			if (comp(curr->item, curr->next->item) > 0) {
				swap(curr->item, curr->next->item);
				swapped = true;
			}
			curr = curr->next;
		}
		DPRINT(show(p, false););
		tail = curr;
	} while (swapped);
	DPRINT(cout << "<bubbleSort N=" << size(p) << endl;);
}

void selectionSort(List* p, int(*comp)(int, int)) {
	DPRINT(cout << ">selectionSort N=" << size(p) << endl;);

	cout << "your code here\n";

	DPRINT(cout << "<selctionSort N=" << size(p) << endl;);
}

/** for your reference
void selectionSort(int *list, int n) {
	int min;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		// Swap min found with the first one of unsorted
		swap(list[i], list[min]);
		DPRINT(for (int x = 0; x < n; x++) cout << list[x] << " "; cout << endl;);
	}
}
*/
