/*
 * Find a Fixed Point in a array: Given an array of n distinct integers sorted in ascending order, write a function that returns a Fixed Point in the array, if there is any Fixed Point present in array, else returns -1. Fixed Point in an array is an index i such that arr[i] is equal to i. Note that integers in array can be negative. 
 * 
 * Link: https://www.geeksforgeeks.org/find-a-fixed-point-in-a-given-array/
 */

#include<bits/stdc++.h>
using namespace std;

//O(n) algorithm. Traversing the whole array. 
int algorithm1(int arr[], int n);


//O(lg n) algorithm: Binary search based.
int algorithm2(int arr[], int n);

int main() {

	int n;
	
	cout<<"Enter n: ";
	cin>>n;

	int arr[n];

	cout<<"Enter elements: "<<endl;
	for(int i = 0 ; i < n; i++)
		cin>>arr[i];

	
	int index = algorithm1(arr, n);
	cout<<"Index(O(n) RT) = "<<index<<endl;
	
	index = algorithm2(arr, n);
	cout<<"Index(O(lg n) RT) = "<<index<<endl;

	return 0;
}


int algorithm1(int arr[], int n) {

	int i;
	for(i = 0; i < n; i++) {

		if(arr[i] == i) {
			cout<<"\nNo. of iterations = "<<i<<endl;
			return i;
		}
	}
	
	cout<<"No. of iterations = "<<i<<endl;
	return -1;
}


int algorithm2(int arr[], int n) {

	int left = 0, right = n-1, middle, count = 0;
	
	while(left < right) {

		middle = (left + right) / 2;

		if(arr[middle] == middle) 
			return middle;

		else if(arr[middle] < middle)
			left = middle + 1;

		else if(arr[middle] > middle)
			right = middle - 1;

		count++;
		cout<<"\nIteration number = "<<count<<endl;
	
	}

	return -1;
}
		













