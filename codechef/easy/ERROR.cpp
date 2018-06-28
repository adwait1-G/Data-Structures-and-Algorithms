//LInk: https://www.codechef.com/problems/ERROR


#include<bits/stdc++.h>
using namespace std;

const bool GOOD = true, BAD = false;

bool check_feedback(string& s);

int main() {

	int t;
	string s;

	cin>>t;
	while(t--) {

		cin>>s;
		if(check_feedback(s) == GOOD)
			cout<<"Good"<<endl;
		else
			cout<<"Bad"<<endl;
	}

	return 0;
}


bool check_feedback(string& s) {

	bool feedback = BAD;
	int substr_pos1, substr_pos2;
	
	substr_pos1 = s.find("101", 0);
	substr_pos2 = s.find("010", 0);

	if(substr_pos1 != s.npos || substr_pos2 != s.npos)
		feedback = GOOD;

	return feedback;
}

