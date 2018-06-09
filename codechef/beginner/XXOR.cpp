#include<bits/stdc++.h>
using namespace std;

int  main() {

	int n , q , i , j;
	cin>>n>>q;
	unsigned long int a[n];
	for(i = 0 ; i < n ; i++ ) {
		cin>>a[i];
	}
	
	while(q--) {
		cin>>l>>r;
		unsigned long int sum = 0 , x = 1;
		for(i = l-1; i <= r-1; i++ ) {
			sum = sum + a[i] ^ 1;


		
