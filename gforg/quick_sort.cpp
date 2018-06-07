#include<bits/stdc++.h>
using namespace std;

void qsort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *x, int *y);

int main() {

	int n;
	cin>>n;

	int a[n];
	for(int i = 0 ; i < n; i++) {
		cin>>a[i];
	}

	qsort(a, 0, n - 1);

	for(int i = 0; i < n; i++) {
		cout<<a[i]<<endl;
	}

	return 0;
}

void qsort(int arr[], int low, int high) {

	if(low < high) {

		int pivot_index = partition(arr, low, high);
		qsort(arr, low, pivot_index - 1);
		qsort(arr, pivot_index + 1, high);
	}
	
	return;
}

int partition(int arr[], int low, int high) {

	int pindex = low;
	int pivot = arr[high];

	for(int j = low; j <= high - 1; j++) {

		if(arr[j] <= pivot) {
			swap(&arr[j], &arr[pindex]);
			pindex++;
		}
	}

	swap(&arr[high], &arr[pindex]);
	return pindex;
}

void swap(int *x, int *y) {
	int temp = (*x);
	(*x) = (*y);
	(*y) = temp;
}
