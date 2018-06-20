/*
 * Problem: 2 n-bit binary numbers are stored in 2 n-element arrays. Find the sum of these 2 numbers and store the binary form in a new (n+1)-element array.
 * CLRS. Chapter2: Getting Started.
 * Problem 2-1.4
 */

#include<bits/stdc++.h>
using namespace std;

int main() {

	bool temp, carry;
	unsigned long int n, i;
	vector<bool> a , b , c;

	cout<<"Enter n: ";
	cin>>n;

	cout<<"Enter first binary number: "<<endl;
	for(i = 0 ; i < n; i++) {
		cin>>temp;
		a.push_back(temp);
	}

	cout<<"\n\nEnter second binary number: "<<endl;
	for(i = 0 ; i < n; i++) {
		cin>>temp;
		b.push_back(temp);
	}

	//MSB is at index 0. LSB is at index n-1.

	//Algorithm starts.
	
	carry = false;		//Initially, carry = 0.

	for(i = n-1 ; i >= 0; i--) {
		temp = a[i] ^ b[i] ^ carry;
		c.push_back(temp);
		carry = ((a[i] & b[i]) | (a[i] & carry) | (b[i] & carry));
	}

	c.push_back(carry);
	
	//LSB at index 0, MSB at index n-1
	
	cout<<"Sum: ";
	for(i = 0 ; i < n+1; i++)
		cout<<c[i]<<" ";

	cout<<endl;

	return 0;
}











