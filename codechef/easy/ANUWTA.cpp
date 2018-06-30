//Link: https://www.codechef.com/problems/ANUWTA

#include<bits/stdc++.h>
using namespace std;

int main() {

	unsigned long t, n;
	
	cin>>t;
	while(t--) {
		
		cin>>n;
		cout<<n + n*(n+1)/2<<endl;
	}

	return 0;
}

