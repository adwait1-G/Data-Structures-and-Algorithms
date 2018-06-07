/*
 * Calculate pow(x, n);
 * Link: https://practice.geeksforgeeks.org/problems/power-of-numbers/0
 */


#include<bits/stdc++.h>
using namespace std;

int method2_count = 0, method1_count = 0;

void method1(unsigned long int x, unsigned long int n);
int method2(unsigned long int x, unsigned long int n);

int main() {

	unsigned long int n, x;
	
	cin>>x>>n;

	method1(x, n);
	cout<<"Number of function calls(d&c) = "<< method2(x, n)<<endl;

	return 0;
}

/*
 * method1() is simple multiplication: O(n) running time, n = Exponent.
 */

void method1(unsigned long int x, unsigned long int n) {

	unsigned long int p = 1, count = 0;
	for(unsigned long int i = 1; i <= n; i++) {
		p = p * x;
		method1_count++;
	}
	cout<<"pow() = "<<p<<", Number of iterations = "<<method1_count<<endl;

	return;
}

int method2(unsigned long int x, unsigned long int n) {

	method2_count++;
	cout<<"n = "<<n<<endl;
	if(n == 0) {
		return 1;
	}
	else {
		if(n % 2 == 0)
			return (method2(x, n/2) * method2(x, n/2));
		else
			return (x * method2(x, n/2) * method2(x, n/2));
	}

}

