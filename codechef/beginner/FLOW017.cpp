/*
 * Link: https://www.codechef.com/problems/FLOW017
 */

#include<bits/stdc++.h>
using namespace std;

int second_largest(int a, int b, int c) {

	if((a >= b && b >= c) || (c >= b && b >= a))
		return b;

	else if((b >= a && a >= c) || (c >= a && a >= b))
		return a;
	
	else if((a >= c && c >= b) || (b >= c && c >= a))
		return c;
}

int main() {

	int t;
	cin>>t;
	
	while(t--) {
		
		int a, b, c;

		cin>>a>>b>>c;
		cout<<second_largest(a, b, c)<<endl;
	}

	return 0;
}
