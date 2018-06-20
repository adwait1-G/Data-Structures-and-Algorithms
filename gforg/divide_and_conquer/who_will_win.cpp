/*
 * Geeks for Geeks problem: https://practice.geeksforgeeks.org/problems/who-will-win/0
 */

#include<bits/stdc++.h>
using namespace std;

int binary_search(int n, int m, int s) {

	int left = 1, right = n, total = 0;
	while(left < right) {
		int mid = (left + right)/2;
		total += s;

		if(mid == m)
			return total;
		else if(m < mid)
			right = mid;
		else if(m > mid)
			left = mid + 1;
	}
	
	return total;
}

int main() {

	int t, n, m, g, s;
	cin>>t;
	while(t--) {
		cin>>n>>m>>g>>s;
		
		if(binary_search(n, m, s) < m * g)
			cout<<2<<endl;
		else if(binary_search(n, m, s) > m * g)
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}

	return 0;
}
