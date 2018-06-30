//Link: https://www.codechef.com/problems/ALEXNUMB


#include<bits/stdc++.h>
using namespace std;

int main() {

	int t;
	unsigned long int n, value;

	cin>>t;
	while(t--) {

		cin>>n;
		for(int i = 0; i < n; i++)
			cin>>value;

		cout<<n*(n-1) / 2<<endl;
	}

	return 0;
}
