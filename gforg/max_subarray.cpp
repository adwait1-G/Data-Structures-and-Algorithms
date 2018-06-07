/*
 * The maximum-subarray problem: You are given a one-dimensional array that may contain both positive and negative integers. Find the sum of contiguous subarray of numbers which has the largest sum.
 */

#include<bits/stdc++.h>
using namespace std;

int method1(int arr[], int *i1, int *i2, int n);
int method2(int arr[], int low, int high);
int max_crossing_sum(int arr[], int low, int mid, int high); 
int max(int x, int y, int z);

int main() {

	int n, i1 = 0, i2 = 0, temp, sum = 0, choice;
	
	printf("Enter n: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter elements: \n");
	for(unsigned long int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("\nBrute-force algorithm(0) / Divide and Conquer Algorithm(1) : ");
	scanf("%d", &choice);

	if(choice == 0)
		sum = method1(arr, &i1, &i2, n);
	else if(choice == 1)
		sum = method2(arr, 0, n-1);
	else
		printf("\nInvalid choice!\n");



	printf("\nMaximum sum = %d\n", sum);

	printf("\n");

	return 0;
}


/*
 * Method 1 is brute-dorce algorithm. It has a worst case running time of O(n^2) ..
 */

int method1(int arr[], int *i1, int *i2, int n) {

	int  sum = -INT_MAX, old_sum = 0;

	for(int i = 0 ; i < n; i++) {
		old_sum = 0;
		for(int j = i ; j < n; j++) {
			old_sum = old_sum + arr[j];
			printf("(i = %d, j = %d)sum = %d, old_sum = %d\n", i, j, sum, old_sum);
			if(old_sum > sum) {
				sum = old_sum;
				*i1 = i;
				*i2 = j;
			}
		}
	}

	return sum;
}

/*
 * Method2: Divide and Conquer Algorithm. Wirst case running time of O(n*lgn).
 */


int method2(int arr[], int low, int high) {

	if(high == low) {
		return arr[low];
	}
	else {
		int mid = (low + high) / 2;
		
		return max(method2(arr, low, mid), method2(arr, mid+1, high), max_crossing_sum(arr, low, mid, high));
	}	

}

int max_crossing_sum(int arr[], int low, int mid, int high) {

	int left_sum = -INT_MAX, right_sum = -INT_MAX, old_sum = 0;
		
	for(int i = mid; i >= low; i--) {

		old_sum = old_sum + arr[i];
		if(old_sum > left_sum) {
			left_sum = old_sum;
		}
	}

	old_sum = 0;

	for(int i = mid+1; i <= high; i++) {

		old_sum = old_sum + arr[i];
		if(old_sum > right_sum) {
			right_sum = old_sum;
		}
	}

	return (left_sum + right_sum);
}


int max(int x, int y, int z) {
	if(x >= y && x >= z)
		return x;
	else if(y >= x && y >= z)
		return y;
	else if(z >= x && z >= y)
		return z;
}



