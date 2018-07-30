#include<bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin>>s;
	set<char> char_set;

	for(int i = 0; i < s.length(); i++) 
		char_set.insert(s[i]);

	if(char_set.size() % 2 == 0)
		cout<<"CHAT WITH HER!"<<endl;
	else
		cout<<"IGNORE HIM!"<<endl;

	return 0;
}


