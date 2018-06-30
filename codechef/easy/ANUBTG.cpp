//Link: https://www.codechef.com/problems/ANUBTG


#include<bits/stdc++.h>
using namespace std;

int main() {

	unsigned int t, n, end, left_over, cost, total;
	
	cin>>t;
	while(t--) {

		cost = 0;

		cin>>n;
		int c[n+1];

		for(int i = 1; i <= n; i++)
			cin>>c[i];

		sort(c+1, c+n+1);

		while(n >= 4) {
			cost = c[n] + c[n-1];
			n = n - 4;
		}

		if(n == 1)
			cost = cost + c[1];

		else if(n == 2)
			cost = cost + c[1] + c[2];

		else if(n == 3)
			cost = cost + c[2] + c[3];	//c[1] is free.

		cout<<cost<<endl;
	}

	return 0;
}






