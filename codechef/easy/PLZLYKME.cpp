//Link: https://www.codechef.com/problems/PLZLYKME

#include<bits/stdc++.h>
using namespace std;

int main() {

	unsigned long int t, l, d, s, c;

	cin>>t;
	while(t--) {

		cin>>l>>d>>s>>c;
		
		if(((d-1) * (log(c+1)) + log(s)) >= log(l))
			cout<<"ALIVE AND KICKING"<<endl;
		else
			cout<<"DEAD AND ROTTING"<<endl;
	}

	return 0;
}
