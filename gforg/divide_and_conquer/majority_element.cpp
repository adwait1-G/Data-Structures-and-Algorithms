/*
 * Check for Majority Element in a sorted array: Question: Write a C function to find if a given integer x appears more than n/2 times in a sorted array of n integers
 *
 * Link: https://www.geeksforgeeks.org/check-for-majority-element-in-a-sorted-array
 */

#include<bits/stdc++.h>
using namespace std;

//O(n) algorithm: Linear Traversal.
bool algorithm1(int arr[], int n, int x);

//O(lg n) algorithm.
bool algorithm2(int arr[], int n, int x);


int main() {

	int n, x;
	cout<<"Enter n: ";
	cin>>n;

	int arr[n];
	for(int i = 0; i < n; i++)
		cin>>arr[i];

	cout<<"\nEnter x: ";
	cin>>x;

	cout<<"\nO(n) algorithm: "<<endl;
	bool presence = algorithm1(arr, n, x);

	if(presence == 1)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;


	cout<<"\nO(lg n) algorithm: "<<endl;
	presence = algorithm2(arr, n, x);

	if(presence == 1)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;

	return 0;
}

bool algorithm1(int arr[], int n, int x) {

	int index_first;

	//Init checks. Important!
	if(arr[n/2] != x)
		return false;
	else if(arr[n/2] == x && arr[n/2 + 1] != x)
		return false;


	//Linear traversal, to know the index of first occurance of x.
	for(int i = 0; i < n; i++) {

		if(arr[i] == x) {
			
			index_first = i;
			break;
		}

		if(i >= n/2) {
			index_first = INT_MAX;
			break;
		}
	}

	if(index_first == INT_MAX)
		return false;


	if(index_first + n/2 <= n-1 && arr[index_first + n/2] == x)
		return true;
	else 
		false;
}


bool algorithm2(int arr[], int n, int x) {

	int index_first;

	//Easy and must Checks for the while loop to work properly.
	if(x != arr[n/2])
		return false;
	
	else if(x == arr[n/2] && x != arr[n/2 + 1])
		return false;


	int left = 0, right = n-1, middle;

	//This will give the index of first occurance of x. 
	while(left < right) {

		middle = (left + right)/2;

		cout<<"middle = "<<middle<<", middle element = "<<arr[middle]<<", middle-1 element = "<<arr[middle-1]<<endl;

		cout<<"middle = "<<middle<<endl;
		
		if(arr[middle - 1]  < x) {

			index_first = middle;
			break;
		}
		else if(arr[middle - 1] == x) {

			right = middle - 1;
		}

	}

	//Using the index of first occurance, it is easy to decide if x is a majority element or not.
	if((arr[index_first + n/2]) != x && (index_first + n/2 <= n-1))
		return false;
	else
		return true;

}
		







