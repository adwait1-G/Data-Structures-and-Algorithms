//Link: https://www.codechef.com/problems/RESQ

#include<bits/stdc++.h>
using namespace std;

unsigned long find_min_diff(unsigned long int n);

int main() {

	int t;
	unsigned long int n, x, y;

	cin>>t;
	while(t--) {

		cin>>n;
		cout<<find_min_diff(n)<<endl;
	}

	return 0;
}

unsigned long find_min_diff(unsigned long n) {

	unsigned long f1, f2, sqrtn;
	double int_part;

	//If n is a perfect square.
	if(modf(sqrt(n), &int_part) == 0)
		return 0;

	f1 = (unsigned long)(sqrt(n));

	while(n % f1 != 0) {
		f1--;
	}

	f2 = n / f1;

	return f2 - f1;
}
