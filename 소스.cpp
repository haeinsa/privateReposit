#include<stdio.h>
#include<stdlib.h>

int* arr;
int capacity;
int lastIdx;

void Init(int size) {
	if (arr != NULL)
		free(arr);
	capacity = size;
	lastIdx = 0;
	arr = (int*)malloc(sizeof(int) * capacity);
}

void ReallocateArray();
void Insert(int val) {
	if (lastIdx + 1 >= capacity)
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
	lastIdx++;
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
	lastIdx--;
	return temp;
}

void Reaplce(int idx, int val) {
	if (idx >= lastIdx) {
		printf("you are trying to replace with invalid index \n");
		return;
	}

	arr[idx] = val;
}

int At(int idx) {
	if (idx >= lastIdx) {
		printf("you are trying to access with invalid index \n");
		return NULL;
	}
	return arr[idx];
}

void clear() {
	for (int i = 0; i < lastIdx; i++)
		arr[i] = 0;
}

void quickSortProcedure(int left, int right);
void quickSort() {
	quickSortProcedure(0, lastIdx - 1);
}

void quickSortProcedure(int left, int right) {
	if (left >= right)
		return;
	int pivotIdx = (left + right) / 2;
	int pivotVal = arr[pivotIdx];

	int i = left;
	int j = right;
	while (i < j) {
		while (arr[i] <= pivotVal)
			i++;
		while (arr[j] >= pivotVal)
			j++;

		if (i <= j) {
			int temp = arr[j];
			arr[j] = pivotVal;
			arr[pivotIdx] = temp;

			quickSortProcedure(left, pivotIdx - 1);
			quickSortProcedure(pivotIdx + 1, right);
			break;
		}
		else {
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
}

int main() {
	Init(15);
	Insert(10);
	Insert(12);
	Insert(166);
	Insert(1);
	for (int i = 0; i < lastIdx; i++)
		printf("%d ,", At(i));
	quickSort();
	printf("\n");
	for (int i = 0; i < lastIdx; i++)
		printf("%d ,", At(i));
	return 0;
}