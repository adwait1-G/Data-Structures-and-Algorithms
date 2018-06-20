#include<bits/stdc++.h>
using namespace std;

int main() {
	short t;
	unsigned long int n;

	cin>>t;

	while(t--) {
		cin>>n;
		if(n == 2) {
			cout<<2<<endl;	//Special case.
		}
		else
			cout<<(n/2)+1<<endl;	//General case.
	}

	return 0;
}

