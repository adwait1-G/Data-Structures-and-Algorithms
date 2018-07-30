#include<bits/stdc++.h>
using namespace std;

int main() {

	string s;
	string::iterator s_iter;
	vector<int> v;
	vector<int>::iterator v_iter;

	cin>>s;

	s_iter = s.begin();

	while(s_iter != s.end()) {

		if((*s_iter) != '+')
			v.push_back((int)(*s_iter));

		s_iter++;
	}


	s.clear();

	sort(v.begin(), v.end());

	v_iter = v.begin();

	while(v_iter != v.end()) {

		s.push_back(*v_iter);
		s.push_back('+');
		v_iter++;
	}

	s.erase(s.length() - 1);

	cout<<s<<endl;

	return 0;
}
