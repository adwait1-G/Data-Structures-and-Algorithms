/*
 * Median of 2 sorted arrays of unequal sizes.
 * Link: https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/
 *
 * 2 algorithms , one with running time complexity of O(l1 + l2) - normal merging method and other with complexity O(lg l1 + lg l2) - using divide and conquer technique.
 */


#include<bits/stdc++.h>
using namespace std;

//O(l1 + l2) algorithm. 
int method1(int arr1[], int arr2[], int l1, int l2);



int main() {

	int l1, l2;
	cout<<"Enter l1 & l2:";
	cin>>l1>>l2;

	int arr1[l1], arr2[l2];

	cout<<"Enter array 1 elements: "<<endl;
	for(int i = 0 ; i < l1; i++)
		cin>>arr1[i];

	cout<<"Enter array 2 elements: "<<endl;
	for(int i = 0 ; i < l2; i++) 
		cin>>arr2[i];

	bool choice;

	cout<<"Merging method(0) / Divide and Conquer method(1) :"<<endl;
	cin>>choice;

	if(choice == 0)
		cout<<"Median = "<<method1(arr1, arr2, l1, l2)<<endl;
	else if(choice == 1) {
		cout<<"Not thought about it yet!"<<endl;
	}
	else {
		cout<<"Invalid Choice!"<<endl;
		return -1;
	}

	return 0;
}
		
		

int method1(int arr1[], int arr2[], int l1, int l2) {

	int i = 0, j = 0,k, num1 = INT_MAX, num2 = INT_MAX;
	bool flag;

	flag = (l1+l2) % 2;

	for(k = 0; k < l1 + l2; k++) {

		if(arr1[i] <= arr2[j]) {
			
			if(flag == 1) {
				if(k == (l1 + l2)/2) {
				return arr1[i];
				}
			}
			else if(flag == 0 ) {
				
				if(k == (l1 + l2)/ 2 - 1) {
					num1 = arr1[i];
				}
				else if(k == (l1 + l2)/2 ) {
					num2 = arr1[i];
				}
			}

			i++;
		}
		else {
			if(flag == 1) {
				
				if(k == (l1 + l2)/2) {

					return arr2[j];
				}
			}
			else if(flag == 0) {

				if(k == (l1 + l2)/2 -1) {

					num1 = arr2[j];
				}
				else if(k == (l1 + l2)/2) {

					num2 = arr2[j];
				}
			}

			j++;
		}
		
		if(num1 != INT_MAX && num2 != INT_MAX)
			break;

	}

	
	cout<<"wtf is happeneing!!!Method1: Number of Iterations: "<<k<<endl;

	return (num1 + num2) / 2;

}















