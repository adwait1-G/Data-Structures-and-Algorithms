//This was not accepted, but I think it is correct.

#include<bits/stdc++.h>
using namespace std;

int main() {

	string s1, s2;
	s1.reserve(105);

	string::iterator iter;

	cin>>s1;

	bool upper_first_letter = isupper(*(s1.begin())), yes_accident = false;
	s2.push_back(toupper(s1[0]));
	
	iter = s1.begin() + 1;

	while(iter != s1.end()) {

		if(isupper(*iter)) {
			s2.push_back(tolower(*iter));
			yes_accident = true;
		}
		else {
			yes_accident = false;
			break;
		}

		iter++;
	}

	if(yes_accident == true) {
		cout<<s2<<endl;
	}
	else
		cout<<s1<<endl;

	return 0;
}




