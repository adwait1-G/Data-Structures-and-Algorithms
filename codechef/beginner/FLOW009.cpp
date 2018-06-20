/*
 * Link: https://www.codechef.com/problems/FLOW009
 */

#include<bits/stdc++.h>
using namespace std;

double calculate_price(int q, int p);

int main() {

	int t;
	cin>>t;

	while(t--) {

		int q, p;
		cin>>q>>p;
		
		printf("%f\n", calculate_price(q, p));
	}

	return 0;
}

double calculate_price(int q, int p) {

	double price;

	if(q > 1000)
		price = 0.9 * q * p;
	else
		price = q * p;

	return price;
}
