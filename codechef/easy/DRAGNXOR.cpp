//Link: https://www.codechef.com/problems/DRAGNXOR


#include<bits/stdc++.h>
using namespace std;

const bool ONE = 1;
const bool ZERO = 0;

unsigned find_no_ones(unsigned int x);
unsigned find_max_value(unsigned n1, unsigned n2, unsigned n);
void swap(unsigned int *a, unsigned int *b);

int main() {

	unsigned int t, n, a, b;
	
	cin>>t;
	while(t--) {

		cin>>n>>a>>b;
		cout<<find_max_value(find_no_ones(a), find_no_ones(b), n)<<endl;
	}

	return 0;
}


unsigned find_no_ones(unsigned int x) {

	unsigned count = 0;

	while(x != 0) {

		if(x & 0x00000001 == 1)
			count++;

		x = x >> 1;
	}

	return count;
}

unsigned find_max_value(unsigned n1, unsigned n2, unsigned n) {

	unsigned num1 = 0, num2 = 0;

	if(n1 < n2)
		swap(&n1, &n2);

	cout<<"n1 = "<<n1<<", n2 = "<<n2<<endl;

	//Bigger number.
	for(int i = n-1; i >= n-n1; i--) {
		cout<<"pow(2, i) = "<<pow(2, i)<<endl;
		num2 += pow(2, i);
	}
	
	cout<<endl;

	//Smaller number.
	for(int i = 0; i <= n2-1; i++) {
		cout<<"pow(2, i) = "<<pow(2, i)<<endl;
		num2 += pow(2, i);
	}

	cout<<"num1 = "<<num1<<", num2 = "<<num2<<endl;

	return num1^num2;
}

void swap(unsigned *a, unsigned *b) {

	unsigned temp = (*a);
	(*a) = (*b);
	(*b) = temp;
}




















