/*
 * Find closest number in an array: Given an array of sorted integers. We need to find the closest value to the given number. Array may contain duplicate values and negative numbers. 
 *
 * Link: https://www.youtube.com/watch?v=5ENPKYvBwoc
 */

#include<bits/stdc++.h>
using namespace std;

//O(n) algorithm: Traversing the whole array.
int algorithm1(int arr[], int n, int x);

//
int algorithm2(int arr[], int n, int x);

int main() {

	int n, x;
	cout<<"Enter n(size of array) :";
	cin>>n;

	int arr[n];

	cout<<"\nEnter array elements: "<<endl;
	for(int i = 0; i < n; i++) 
		cin>>arr[i];

	cout<<"Enter x: ";
	cin>>x;

	int index = algorithm1(arr, n, x);

	cout<<"Closest Number(O(n) algo) = "<<arr[index]<<endl;

	index = algorithm2(arr, n, x);

	cout<<"\nClosest number(O(lg n)) = "<<arr[index]<<endl;


	return 0;
}


int algorithm1(int arr[], int n, int x) {


	if(x <= arr[0]) {
		cout<<"Edge case: Only 1 number checked"<<endl;
		return 0;
	}
	else if(x >= arr[n-1]) {
		cout<<"Edge case: Only 1 number checked"<<endl;
		return n-1;
	}


	int index, min = INT_MAX, count = 0;

	for(int i = 0; i < n; i++) {
		
		if(min > abs(arr[i] - x)) {
			min = abs(arr[i] - x);
			index = i;
		}
		count++;
	}

	cout<<"No. of iterations(O(n)) algo) = "<<count<<endl;
	return index;
}


int algorithm2(int arr[], int n, int x) {

	int left, right, middle, count = 0;

	//Initial values
	left = 0;
	right = n - 1;

	//Edge cases
	if(x <= arr[0]) {
		cout<<"Edge case: Only 1 number checked"<<endl;
		return 0;
	}
	else if(x >= arr[n-1]) {
		cout<<"Edge case: Only 1 number checked"<<endl;
		return n-1;
	}

	//All other cases: Binary search based.
	
	while( left < right) {

		count++;
		middle = (left + right) / 2;
		cout<<"\nmiddle = "<<middle<<", arr[middle] = "<<arr[middle]<<endl;
		if(arr[middle] == x) {
			return middle;
		}

		else if(arr[middle] > x) {

			if(arr[middle - 1] < x) {

				if(abs(x - arr[middle]) > abs(x - arr[middle - 1])) {
					cout<<"No. of iterations: "<<count<<endl;
					return middle - 1;
				}
				else {
					cout<<"No. of iterations: "<<count<<endl;
					return middle;
				}
			}

			
			right = middle;
		}

		else if(arr[middle] < x) {

			if(arr[middle + 1] > x) {

				if(abs(x - arr[middle]) > abs(x - arr[middle + 1])) {
					cout<<"No. of iterations: "<<count<<endl;
					return middle + 1;
				}
				else {
					cout<<"No. of iterations: "<<count<<endl;
					return middle;
				}
			}

			left = middle + 1;
		}
	}


	cout<<"No. of iterations(O(lg n) algo) = "<<count<<endl;
	return middle;

}































