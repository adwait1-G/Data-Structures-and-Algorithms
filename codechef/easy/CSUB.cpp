//Link: https://www.codechef.com/problems/CSUB


#include<bits/stdc++.h>
using namespace std;

unsigned long int count_substrings(string& s);

int main() {

	unsigned long int t, n;
	string s;

	cin>>t;
	while(t--) {

		cin>>n;
		cin>>s;

		cout<<count_substrings(s)<<endl;
	}

	return 0;
}

unsigned long int count_substrings(string& s) {

	unsigned long int i = 0, one_count = 0;
	for(i = 0; i < s.length(); i++) {

		if(s[i] == '1')
			one_count++;
	}

	return one_count * (one_count + 1) / 2;
}
