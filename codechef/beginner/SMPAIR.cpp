/*
 * Link: https://www.codechef.com/problems/SMPAIR
 */

#include<bits/stdc++.h>
using namespace std;

int find_smpair(int arr[], int n);

int main() {

	int t;
	cin>>t;

	while(t--) {

		int n;
		cin>>n;

		int arr[n];

		for(int i = 0; i < n; i++)
			cin>>arr[i];

		cout<<find_smpair(arr, n)<<endl;
	}

	return 0;
}

/*

int find_smpair(int arr[], int n) {

	int min = INT_MAX;

	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++) {

			if(arr[i] + arr[j] < min)
				min = arr[i] + arr[j];
		}
	
	return min;
}

*/



int find_smpair(int arr[], int n) {

	sort(arr, arr + n);

	return arr[0] + arr[1];
}

