#include<bits/stdc++.h>
using namespace std;

int main() {
	
	short int t;
	int n;

	cin>>t;

	while(t--) {
		cin>>n;
		unsigned long int a[n];

		unsigned long int cost = 1;
		for(int i = 0; i < n; i++ ) {
			cin>>a[i];
			cost = cost | a[i];
		}	
		cout<<cost<<endl;
	}

	return 0;
}
