//Link: https://www.codechef.com/problems/WALK


#include<bits/stdc++.h>
using namespace std;

int main() {

	unsigned int t, n, w, v;

	cin>>t;
	while(t--) {
		
		cin>>n;

		v = 0;
		for(int i = 0; i < n; i++) {
			cin>>w;
			v = max(v, w+i);
		}

		cout<<v<<endl;
	}

	return 0;
}
