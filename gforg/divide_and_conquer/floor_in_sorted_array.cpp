/*
 * Floor of a number in a sorted array: Given a sorted array and a value x, the floor of x is the largest element in array smaller than or equal to x. Write efficient functions to find floor of x.
 *
 * Link: https://www.geeksforgeeks.org/floor-in-a-sorted-array/
 */


#include<bits/stdc++.h>
using namespace std;

//O(n) algorithm: Traverse the array once and get the number.
int algorithm1(int arr[], int n, int x);

//O(lg n) algorithm: Binary search based.
int algorithm2(int arr[], int n, int x);


int main() {

	int n, x, floor, index;
	cout<<"Enter n(size of the array): ";
	cin>>n;

	int arr[n];

	cout<<"Enter elements: "<<endl;
	for(int i = 0; i < n; i++) 
		cin>>arr[i];

	cout<<"Enter x: ";
	cin>>x;
	
	bool choice;
	cout<<"Linear traversal method(0) / Binary Search based(1) :";
	cin>>choice;

	if(choice == 0) {
	
		floor = algorithm1(arr, n, x);
	}
	else if(choice == 1) {
		
		if((index = algorithm2(arr, n, x)) == -1) {
			cout<<"Floor = "<<index<<endl;
			return 0;
		}
		
		else 
			floor = arr[index];
	}
	else {
		cout<<"Invalid Choice!"<<endl;
		return -1;
	}

	cout<<"Floor = "<<floor<<endl;

	return 0;
}

int algorithm1(int arr[], int n, int x) {

	int floor = INT_MAX;

	if(x >= arr[n-1])
		return arr[n-1];

	for(int i = 0; i < n; i++) {

		if(arr[i] <= x && arr[i+1] > x) {

			floor = arr[i];
			break;
		}
	}

	if(floor == INT_MAX)
		return -1;
	else
		return floor;

}
	
int algorithm2(int arr[], int n, int x) {

	int left, right, middle;
	

	//Edge case: If x is greater than all the elements, then floor = largest element = last element.
	if(x >= arr[n-1]) 
		return n-1;
	else if(x < arr[0])
		return -1;

	//Initial values.
	left = 0;
	right = n-1;
	
	while(left < right) {

		middle = (left + right)/2;

		cout<<"left = "<<left<<", right = "<<right<<", a[middle] = "<<arr[middle]<<endl;

		if(arr[middle] == x ) 
			return middle;
		
		else if(arr[middle] < x && arr[middle + 1] > x)
			return middle;
		
		else if(arr[middle] > x && arr[middle - 1] < x)
			return (middle - 1);
		
		else if(arr[middle] < x && arr[middle + 1] < x)
			left = middle + 1;

		else if(arr[middle - 1] > x )
			right = middle - 2;

	}
	
}
	
