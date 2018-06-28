//Link: https://www.codechef.com/problems/AMSGAME1

#include<bits/stdc++.h>
using namespace std;

unsigned long int gcdn(vector<int>& v, int n);
unsigned long int gcd2(unsigned long int a, unsigned long int b);
void swap(unsigned long *x, unsigned long *y);

int main() {

	int t, n;
	vector<int> v;
	unsigned long int value;

	cin>>t;
	while(t--) {

		cin>>n;
		v.reserve(n);
		
		for(int i = 0; i < n; i++) {
			cin>>value;
			v.push_back(value);
		}

		cout<<gcdn(v, n)<<endl;

		v.clear();
	}

	return 0;
}

unsigned long int gcdn(vector<int>& v, int n) {

	if(n == 2) 
		return gcd2(v[0], v[1]);
	else 
		return gcd2(v[n-1], gcdn(v, n-1));
}

unsigned long int gcd2(unsigned long a, unsigned long  b) {

	if(b > a)
		swap(&a, &b);

	if(a % b == 0)
		return b;

	while(b != 0) {

		unsigned long temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

void swap(unsigned long int *x, unsigned long int *y) {

	unsigned long temp = (*x);
	(*x) = (*y);
	(*y) = temp;
}
