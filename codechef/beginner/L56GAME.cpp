/*
 * Link: https://www.codechef.com/problems/L56GAME
 */

#include<bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin>>t;

	while(t--) {

		int n, even = 0, odd = 0;
		cin>>n;

		int value;
		for(int i = 0; i < n; i++) {
			cin>>value;

			if(value % 2 == 0) 
				even++;
			else
				odd++;
		}

		if(odd % 2 != 0 && n != 1)
			cout<<2<<endl;
		else
			cout<<1<<endl;
	}

	return 0;
}
	
