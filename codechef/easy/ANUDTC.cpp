//Link: https://www.codechef.com/problems/ANUDTC


#include<bits/stdc++.h>
using namespace std;

int main() {

	unsigned int t, n;

	cin>>t;
	while(t--) {
		
		cin>>n;
		if(360 % n == 0)
			cout<<"y ";
		else
			cout<<"n ";
		
		if(n <= 360)
			cout<<"y ";
		else
			cout<<"n ";

		if(n*(n+1)/2 <= 360)
			cout<<"y";
		else
			cout<<"n";

		cout<<endl;
	}

	return 0;
}
