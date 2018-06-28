//Link: https://www.codechef.com/problems/CONFLIP


#include<bits/stdc++.h>
using namespace std;

int main() {

	int t, g, i, q, n_h, n_t;
	const int HEAD = 1, TAIL = 2;
	unsigned long int n;

	cin>>t;
	while(t--) {

		cin>>g;
		while(g--) {

			cin>>i>>n>>q;
			if(n % 2 == 1) {
				
				if(i == HEAD) {
					n_h = n/2;
					n_t = n/2 + 1;
				}
				
				else if(i == TAIL) {

					n_t = n/2;
					n_h = n/2 + 1;
				}
			}
			else {
				n_t = n/2;
				n_h = n/2;
			}
			
			if(q == HEAD)
				cout<<n_h<<endl;
			else
				cout<<n_t<<endl;
		}
	}

	return 0;
}
