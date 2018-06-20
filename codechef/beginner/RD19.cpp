/*
 * Link: https://www.codechef.com/problems/RD19#
 *
 *
 * To find the gcd, I have written both recursive and iterative functions for the same algorithm. 
 */

#include<bits/stdc++.h>
using namespace std;

int gcdn_rec(int arr[], int n);
int gcd2(int a, int b);
void swap(int *x, int *y);

int main() {

	int t;
	cin>>t;

	while(t--) {

		int n;
		cin>>n;

		int arr[n];
		for(int i = 0; i < n; i++) 
			cin>>arr[i];


		if(gcdn_rec(arr, n) == 1)
			cout<<0<<endl;
		else
			cout<<-1<<endl;

	}
	

	return 0;
}

int gcdn_rec(int arr[], int n) {

	if(n == 2) {
		return gcd2(arr[0], arr[1]);
	}
	else {
		return gcd2(gcdn_rec(arr, n-1), arr[n-1]);
	}
}

//int gcdn_iter(int arr[], int n) 



int gcd2(int a, int b) {

	if(a < b) {
		swap(&a, &b);
	}

	if(a % b == 0)
		return b;

	while(b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}


void swap(int *x, int *y) {

	int temp;
	temp = (*x);
	(*x) = (*y);
	(*y) = temp;
}





