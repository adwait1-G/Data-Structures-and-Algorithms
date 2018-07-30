#include<bits/stdc++.h>
using namespace std;

int main() {

	string s1, s2;
	int lex_order, i;
	cin>>s1>>s2;

	i = 0;

	while(i < s1.length()) {

		s1[i] = tolower(s1[i]);
		s2[i] = tolower(s2[i]);

		if(s1[i] < s2[i]) {
			lex_order = -1;
			break;
		}
		else if(s1[i] > s2[i]) {
			lex_order = 1;
			break;
		}
		else 
			lex_order = 0;
		
		i++;
	}

	cout<<lex_order<<endl;
	return 0;
}
