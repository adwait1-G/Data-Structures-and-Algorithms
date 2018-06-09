/*
 * Link: https://www.codechef.com/problems/RECIPE
 */

#include<bits/stdc++.h>
using namespace std;

int gcdn(int arr[], int n);
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

		int gcd = gcdn(arr, n);

		for(int i = 0; i < n; i++)
			cout<<arr[i] / gcd<<" ";

		cout<<endl;
	}

	return 0;
}

int gcdn(int arr[], int n) {

	if(n == 2)
		return gcd2(arr[0], arr[1]);
	else
		return gcd2(gcdn(arr, n-1), arr[n-1]);
}


int gcd2(int a, int b) {

	if(a < b)
		swap(&a, &b);

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

	int temp = (*x);
	(*x) = (*y);
	(*y) = temp;
}









