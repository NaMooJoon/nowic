/*On my honor, I pledge that I have neither received
 nor provided improper assistance in the completion
  of this assignment.
  Signed: JunHyeon Kim   Section: 03   Student Number: 21800179*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <sstream>
using namespace std;

#if 0
void selectionSort(int[], int);

int main(void) {
    int N;
    int* list;
    string line;
    // List ���� �Է¹ޱ�
    cout << "Enter the number of samples: ";
    getline(cin, line);
    stringstream ss(line);
    ss >> N;

    if(N < 1) {
        cout << "Improper value of N" << endl;
        return EXIT_FAILURE;
    }
    // ����Ʈ ����
    list = new (nothrow) int[N];
    assert(list != nullptr);

    srand(time(NULL));

    cout << "\nUnSorted array:\n";
    for(int i = 0; i < N; i++) {
        list[i] = rand() % 1000 + 1;
        cout << list[i] << " ";
    }
    // Sorting
    selectionSort(list, N);

    cout << "\nSorted array:\n";
    for(int i = 0; i < N; i++) {
        cout << list[i] << " ";
    }
    cout << endl;


    delete[] list;

    return EXIT_SUCCESS;

}
#endif

void selectionSort(int list[], int N) {
    int i, j, min, temp;
    for(i = 0; i < N - 1; i++) {
        min = i;
        for(j = i + 1; j < N; j++)
            if(list[j] < list[min])
                min = j;
        temp = list[i];
        list[i] = list[min];
        list[min] = temp;
    }
}
