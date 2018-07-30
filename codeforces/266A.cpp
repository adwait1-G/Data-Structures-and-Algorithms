#include<bits/stdc++.h>
using namespace std;

int main() {

	string s;
	int n, p1, p2, count = 0;
	
	cin>>n;
	cin>>s;
	
	p1 = 0;
	p2 = 1;

	while(p2 < s.length()) {

		if(s[p1] == s[p2])
			count++;

		p1++;
		p2++;
	}

	cout<<count<<endl;
	
	return 0;
}
	
