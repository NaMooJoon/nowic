// 03분반 21800179 김준현
/*
On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
Signed: 김준현 Section:  03분반 Student  Number: 21800179
*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

int _binary_search(int *data, int key, int lo, int hi) {
	DPRINT(cout << "key=" << key << " lo=" << lo << " hi=" << hi << endl;);
	int index = (lo + hi) / 2;

	if(lo > hi) {
		index = -lo - 1;
		return index;
	}

	if(data[index] == key){
		return index;
	}else if(data[index] < key){
		lo = index + 1;
	}else {
		hi = index - 1;
	}

	return _binary_search(data, key, lo, hi);

}

int binary_search(int *list, int key, int size) {
	DPRINT(cout << ">binary_search: key=" << key << " size=" << size << endl;);
	int answer = _binary_search(list, key, 0, size);
	DPRINT(cout << "<binary_search: answer=" << answer << endl;);
	return answer;
}

#if 0
int main(int argc, char *argv[]) {
	int list[] = { 3, 5, 6, 9, 11, 12, 15, 16, 18, 19, 20 };
	int size = sizeof(list) / sizeof(list[0]);
	int key;

	cout << "list: ";
	for (int i = 0; i < size; i++)
		cout << list[i] << " ";
	cout << endl;


	// randomly generate numbers to search between
	srand(time(nullptr));
	// list[0] = 3 and list[size-1] = 20, inclusviely.
	// do this by 'size' times.
	// print the results as shown in binsearchx.exe.
	for(int i = 0; i < size; i ++) {
		key = rand() % (list[size - 1] - list[0] + 1)+ list[0];

		int index = binary_search(list, key, size);
		if(index >= 0){
			cout << "\t" << key << '\t' << "is @[" << index << "]\n";
		}else {
			index = -(index + 1);
			cout << "\t" << key << '\t' << "is not @[" << index << "]\n";
		}
	}
}
#endif
