#include<bits/stdc++.h>
using namespace std;

int main() {

	string s1, s2;
	string::iterator iter;
	cin>>s1;

	iter = s1.begin();

	while(iter != s1.end()) {

		if(*iter == 'A' || *iter == 'E' || *iter == 'I' || *iter == 'O' || *iter == 'U' || *iter == 'Y' || *iter == 'a' || *iter == 'e' || *iter == 'i' || *iter == 'o' || *iter == 'u' || *iter == 'y') {}

		else {
			s2.push_back('.');
			s2.push_back(tolower(*iter));
		}

		iter++;
	}

	cout<<s2<<endl;

	return 0;
}
