#include<stdio.h>
#include<stdlib.h>

int* arr;
int capacity;
int lastIdx;

void Init(int size) {
	if(arr !=NULL)
	   free(arr);
	capacity = size;
	lastIdx = 0;
	arr = (int*)malloc(sizeof(int)*capacity);
}

void ReallocateArray();
void Insert(int val) {
	if (lastIdx+1 >= capacity) 
		ReallocateArray();
	arr[lastIdx++] = val;
}

void ReallocateArray() {
	size_t duumy = (size_t)realloc(arr, sizeof(int) * capacity * 2);
	capacity *= 2;
	
}

void InsertAt(int idx, int val) {
	if (lastIdx + 1 >= capacity)
		ReallocateArray();
	for (int i = lastIdx + 1; i > idx; i--) 
		arr[i] = arr[i - 1];
	arr[idx] = val;
}

void pushBack(int val) {
	if (lastIdx + 1 >= capacity)
		ReallocateArray();
	arr[lastIdx++] = val;
}

void pushForward(int val) {
	InsertAt(0, val);
}

int RemoveAt(int idx) {
	int temp = arr[idx];
	for (int i = idx; i < lastIdx - 1; i++)
		arr[i] = arr[i + 1];
	return temp;
}

void clear() {
	for (int i = 0; i < lastIdx; i++)
		arr[i] = 0;
}

void quickSort() {
	quickSortProcedure(0, lastIdx - 1);
}

void quickSortProcedure(int left, int right) {
	int pivotValue = arr[left];
	int j;
	for (int i,j = left + 1; i <= right; i++) {
		if(pivo)
	}
}

int main() {
	Init(1);
	Insert(5);
	Insert(15);
	printf("%d \n", arr[0]);
	return 0;
}