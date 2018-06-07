/*
 * Sum of Prime: Given a number ( greater than 2 ), Print two prime numbers whose sum will be equal to given number, else print -1 if no such number exists.
 * Link: https://practice.geeksforgeeks.org/problems/sum-of-prime/0/?ref=self
 */

#include<bits/stdc++.h>
using namespace std;

bool checkprime(int n) {
	
	for(int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return 0;
	}

	return 1;
}

int main() {

	int t, n, i;
	cin>>t;
	while(t--) {
		cin>>n;
		bool flag = 0;
		for(i = 2; i < n-1; i++) {
			if(checkprime(i) == 1 && checkprime(n-i) == 1) {
				flag = true;
				break;
			}
		}

		if(flag == true)
			cout<<i<<" "<<n-i<<endl;
		else 
			cout<<-1<<endl;
	}

	return 0;
}
	
