//Link: https://www.codechef.com/problems/RRSUM


#include<bits/stdc++.h>
using namespace std;

int main() {

	unsigned long int n, m, q;

	cin>>n>>m;

	while(m--) {

		cin>>q;

		if(q <= n+1)
			cout<<0<<endl;
		
		else if(q > n+1 && q <= 2*n)
			cout<<q-n-1<<endl;
		
		else if(q > 2*n && q < 3 * n)
			cout<<3*n - q + 1<<endl;

		else if(q == 3*n)
			cout<<1<<endl;
	}

	return 0;
}
