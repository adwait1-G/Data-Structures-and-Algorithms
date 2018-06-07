/*
 * Number of Occurances: Given a sorted array C[] and a number X, write a function that counts the occurrences of X in C[].
 * Link: https://practice.geeksforgeeks.org/problems/number-of-occurrence/0/?ref=self
 */

#include<bits/stdc++.h>
using namespace std;

int no_of_occur(int c[], int x, int n) {

	int count = 0;
	for(int i = 1 ; i <= n; i++) {
		if(c[i] == x)
			count++;
	}

	if(count == 0)
		return -1;
	else
		return count;
}


int main() {

	int t, n, x;
	cin>>t;
	while(t--) {
		cin>>n>>x;
		int c[n+1];
		for(int i = 1 ; i <= n; i++)
			cin>>c[i];

		cout<<no_of_occur(c, x, n)<<endl;
	}

	return 0;
}
