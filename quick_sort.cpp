#include <iostream>
 
#include <cstdlib>
using namespace std;
using std::rand;
using std::swap;
 
// pivot - "опорный" элемент
// partition - переупорядочивает элементы части массива,
// заданной отрезком [left, right), так что в начале
// следуют элементы меньшие pivot, а в конце - большие;
// возвращает место начала блока элементов, больших pivot;
int * partition(int * left, int *  right, int * pivot) {
	int * store = left; // место для вставки элементов, меньших pivot
	int inPivot = *pivot;
	swap(*pivot, *right);
	for (int * p = left; p != right; ++p)
		if (*p < inPivot)
			swap(*p, *store++);
	swap(*store, *right);
	return store;
}
 
void my_qsort(int * arr, int n) {
	if (n <= 1)
		return; // массив в 1 или 0 элементов уже упорядочен
	
	int * pivotPtr = arr + rand() % n; // случайный выбор опорного элемента
	int newPivotIdx = partition(arr, arr + n-1, pivotPtr) - arr;
	my_qsort(arr, newPivotIdx );
	my_qsort(arr + newPivotIdx + 1, n - (newPivotIdx + 1));
}

int main(){
	int a[6]{3,2,1,4,5,66};
	my_qsort(a,6);
}