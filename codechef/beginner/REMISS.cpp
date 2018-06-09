#include<bits/stdc++.h>
using namespace std;

int main() {

	short int t;
	int a , b;

	cin>>t;

	while(t--) {
		cin>>a>>b;
		if(a > b) {
			cout<<a<<" "<<a+b<<endl;
		}
		else
			cout<<b<<" "<<a+b<<endl;
	}

	return 0;
}
