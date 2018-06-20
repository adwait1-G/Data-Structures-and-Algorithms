/*
 * Find a peak element in the array: Given an array of integers. Find a peak element in it. An array element is peak if it is NOT smaller than its neighbors. For corner elements, we need to consider only one neighbor. For example, for input array {5, 10, 20, 15}, 20 is the only peak element. For input array {10, 20, 15, 2, 23, 90, 67}, there are two peak elements: 20 and 90. Note that we need to return any one peak element.
 *
 * Link: https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/
 *
 */


#include<bits/stdc++.h>
using namespace std;

//O(n) RT algorithm. Traversing the whole array.
int algorithm1(int arr[], int n);
//Helper global variables.
vector<int> index_of_peak;

int main() {

	int t, n, index;
	cin>>t;

	while(t--) {

		cin>>n;
		int arr[n];
		for(int i = 0; i < n; i++)
			cin>>arr[i];

		index = algorithm1(arr, n);

		cout<<arr[index]<<endl;
	}

	return 0;
}


int algorithm1(int arr[], int n) {

	int index;
	for(int i = 0; i < n; i++) {

		if(i == 0) {

			if(arr[i] >= arr[i+1])
				return arr[0];
		}
		else if(i == n-1) {

			if(arr[n-1] >= arr[n-2])
				return arr[n-1];
		}
		else {
			if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1])
				return arr[i];
		}
	}

	return -1;
}















