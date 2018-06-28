//Link: https://www.codechef.com/problems/LAPIN


#include<bits/stdc++.h>
using namespace std;

const bool YES = true;
const bool NO = false;

bool check_lapin(string& s);

int main() {

	int t;
	string s;

	cin>>t;
	while(t--) {

		cin>>s;
		if(check_lapin(s) == YES)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}

	return 0;
}


bool check_lapin(string& s) {
	
	map<char, int> map1, map2;
	bool yes_lapin;

	//INIT
	for(char ch = 'a'; ch <= 'z'; ch++) {
		map1[ch] = 0;
		map2[ch] = 0;
	}

	//UPDATE
	for(int i = 0; i < s.length()/2; i++) {
		map1[s[i]]++;
		map2[s[s.length()-i-1]]++;
	}

	//CHECK
	for(char ch = 'a'; ch <= 'z'; ch++) {

		if(map1[ch] != map2[ch]) 
			return NO;
	}

	return YES;

}

	
