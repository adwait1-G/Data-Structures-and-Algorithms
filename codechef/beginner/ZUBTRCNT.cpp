/*
 * Link: https://www.codechef.com/problems/ZUBTRCNT
 */

#include<bits/stdc++.h>
using namespace std;

int calculate_valid_no(int l, int k);

int main() {

	int t;
	cin>>t;

	while(t--) {

		int l, k;
		cin>>l>>k;

		cout<<"Case "<<t<<":"<<" "<<calculate_valid_no(l, k)<<endl;
	}

	return 0;
}

int calculate_valid_no(int l, int k) {

	if(l == 1 && k == 1)
		return 1;

	else if(l == 2) {

		if(k == 1)
			return 4;
		else if(k == 2) 
			return 1;
	}

	else if(l >= 3 && k == 1) {

		return ((l * k) - (l/2 + 1) * (l/2 + 1));
	}

	else
		return -1;
}
