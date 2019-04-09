// 03분반 21800179 김준현
/*
On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
Signed: 김준현 Section:  03분반 Student  Number: 21800179
*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void printList(int *list, int N, int max_print = 10, int per_line = 5);
void quickSort(int *a, int n);
int binary_search(int *list, int toFind, int size);
int _binary_search(int *list, int toFind, int start, int end);
//int binary_search(int *list, int key, int size);

int main(int argc, char *argv[]) {
	setvbuf(stdout, NULL, _IONBF, 0);		// print out immediately if any
	setvbuf(stdin,  NULL, _IONBF, 0);		// read input immediately if any

	vector<int> list;
	string line;
	int keyin;
	cout << "Enter numbers to sort(q to quit): ";
	while (cin >> keyin) {
		if(keyin == 'q')
			break;

		list.push_back(keyin);		// adding to the end
	}

	int N = list.size();
	cout << "\nUNSORTED[" << N << "]:\n";
	printList(&list[0], N);
	quickSort(&list[0], N);
	cout << "\nSORTED[" << N << "]:\n";
	printList(&list[0], N);

	srand((unsigned)time(NULL));	// comment out when debugging

	// get a random number to use as a key for testing the binary search.
	int key = rand() % (list[N-1] - list[0] + 1) + list[0];


	cout << "\n\t" << key << " To Be Found.\n";

	// invoke bineary_search to find key in the list.
	int index = binary_search(&list[0], key, N);
	// display the result
	if(index >= 0){
		cout << "\t" << key << " is @list[" << index << "]\n";
	}else {
		index = -(index + 1);
		cout << "\t" << key << " is NOT @list[" << index << "]\n";
	}

	// print a few data around a possible key index or -index to check your output.
	int extra = 6;						// a magic number

	int exam_start = index - extra/2;
	int exam_end = index + extra/2;
	if(exam_start <= 0)	exam_start = 0;
	if(exam_end > N)	exam_end = N - 1;
	for(int i = exam_start; i <= exam_end; i ++)
		cout << "\t[" << i << "] = " << list[i] << endl;

	cout << "Happy Coding~~\n";
	// system("pause");
	return EXIT_SUCCESS;
}
