/*
 *
 * Question: Given 2 strings, check whether one of the strings is a rotation of the other.
 */

#include<bits/stdc++.h>
using namespace std;

bool string_rotate(string& s1, string s2);

int main() {

	string s1, s2;
	cout<<"Enter 2 strings: "<<endl;
	cin>>s1>>s2;

	if(string_rotate(s1, s2) == true) {

		cout<<"TRUE"<<endl;
	}
	else
		cout<<"FALSE"<<endl;
	
	return 0;
}



bool string_rotate(string& s1, string s2) {

	
	if(s2.length() != s2.length())
		return false;


	bool flag = false;

	for(int i = 1; i < s2.length(); i++) {

		cout<<s1<<" "<<s2<<endl;
		
		if(s1 == s2) {

			flag = true;
			break;
		}
	}

	return flag;
}
