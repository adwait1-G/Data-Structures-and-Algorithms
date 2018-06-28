//Link: https://www.codechef.com/problems/NUMGAME2


#include<bits/stdc++.h>
using namespace std;

int main() {

	int t, n;
	
	cin>>t;
	while(t--) {

		cin>>n;
		
		//An observation.
		if(n % 4 == 1)
			cout<<"ALICE"<<endl;
		else
			cout<<"BOB"<<endl;
	}

	return 0;
}
