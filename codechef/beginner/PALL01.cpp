/*
 * Link: https://www.codechef.com/submit/PALL01
 */

#include<bits/stdc++.h>
using namespace std;

bool check_palin(int n);
int reverse_me(int n);

int main() {

	int t;
	cin>>t;

	while(t--) {

		int n;
		cin>>n;

		if(check_palin(n) == true)
			cout<<"wins"<<endl;
		else
			cout<<"losses"<<endl;

	}
	
	return 0;
}

bool check_palin(int n) {

	if(n == reverse_me(n))
		return true;
	else
		return false;
}


int reverse_me(int n) {
	
	int rev = 0;
	while(n != 0) {

		rev = rev * 10 + n % 10;
		n = n / 10;
	}

	return rev;
}
