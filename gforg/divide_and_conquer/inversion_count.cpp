/*
 * Inversion count for an array: Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 *
 * Link: https://practice.geeksforgeeks.org/problems/inversion-of-array/0
 *
 */

#include<bits/stdc++.h>
using namespace std;
int main() {

	int t;
	cin>>t;
	while(t--) {

		int n, count = 0;
		cin>>n;

		int arr[n];
		for(int i = 0 ; i < n; i++)
			cin>>arr[n];

		for(int i = 0 ; i < n - 1; i++)
			for(int j = i + 1; j < n; j++)
				if(arr[i] > arr[j])
					count++;

		cout<<count<<endl;
	}

	return 0;
}
