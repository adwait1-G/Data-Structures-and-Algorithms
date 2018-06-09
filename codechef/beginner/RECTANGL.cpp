#include<bits/stdc++.h>
using namespace std;

int main() {

	short int t;
	short int a , b , c , d;

	cin>>t;

	while(t--) {
		cin>>a>>b>>c>>d;
		if((a == b && c == d) || (a == c && b == d) || (a == d && b == c))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

	return 0;
}
