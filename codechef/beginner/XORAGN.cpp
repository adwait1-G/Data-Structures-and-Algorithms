/*
 * Link: https://www.codechef.com/problems/XORAGN
 */

#include<bits/stdc++.h>
using namespace std;

unsigned long int xor_func(unsigned long int a[], int n);

int main() {

	int t;
	cin>>t;

	while(t--) {

		int n;
		cin>>n;

		unsigned long int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];

		cout<<xor_func(a, n)<<endl;

	}

	return 0;
}

unsigned long int xor_func(unsigned long int a[], int n) {

	unsigned long int xor_value = 0;

	for(int i = 0; i < n; i++) {

		xor_value ^= (2 * a[i]);
	}

	return xor_value;
}
