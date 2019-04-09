#ifndef __SORT_H__
#define __SORT_H__

int ascending(int a, int b);
int descending(int a, int b);

void bubbleSort(int *list, int n, int (*comp)(int, int) = ascending);
void insertionSort(int *list, int n, int (*comp)(int, int) = ascending);
void quickSort(int *list, int n, int (*comp)(int, int) = ascending);
void selectionSort(int *list, int n, int (*comp)(int, int) = ascending);

#endif
