/*
 * Link: https://www.codechef.com/problems/FLOW005
 */

#include<bits/stdc++.h>
using namespace std;

int find_smallest(int n);

int main() {

	int t, n;
	cin>>t;

	while(t--) {
		
		cin>>n;

		cout<<find_smallest(n)<<endl;
	}

	return 0;
}


int find_smallest(int n) {

	int no_of_notes;

	no_of_notes = n/100 + (n%100)/50 + ((n%100)%50)/10 + (((n%100)%50)%10)/5 + ((((n%100)%50)%10)%5) / 2 + (((((n%100)%50)%10)%5)%2);

	return no_of_notes;
}
