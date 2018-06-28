//Link: https://www.codechef.com/problems/NAME2


#include<bits/stdc++.h>
using namespace std;

bool check_if_subsequence(string& s1, string& s2);

int main() {

	int t;
	string m, w,temp;
	bool answer;

	cin>>t;
	while(t--) {

		cin>>m;
		cin>>w;
		
		if(m.length() < w.length())
			answer = check_if_subsequence(m, w);
		else
			answer = check_if_subsequence(w, m);


		if(answer == true)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

	return 0;
}

bool check_if_subsequence(string& s1, string& s2) {

	int j = 0, i = 0;
	while(j < s1.length() && i < s2.length()) {

		if(s2[j] == s1[i] && j < s1.length()) {
			j++;
		}

		i++;
	}

	if(j == s1.length())
		return true;
	else 
		return false;
}
