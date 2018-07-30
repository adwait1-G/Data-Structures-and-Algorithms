#include<bits/stdc++.h>
using namespace std;

int main() {

	string s1("hello"), s2, s3, s4("olleh");
	string::iterator s1_it, s2_it;
	stack<char> stk;
	queue<char> q;

	cin>>s2;

	//If entered string is less than 5 characters.
	if(s2.length() <= 4) {
		cout<<"NO"<<endl;
		return 0;
	}
		
	s2_it = s2.begin();
	while(s2_it != s2.end()) {
		q.push(*s2_it);
		s2_it++;
	}
	
	s1_it = s1.begin();

	while(q.empty() == false) {

		cout<<q.front()<<endl;

		if(*s1_it == q.front()) {
			stk.push(q.front());
			s1_it++;
			q.pop();
		}
		
		while(q.front() == stk.top()) {}

	}

	while(stk.empty() == false) {

		s3.push_back(stk.top());
		stk.pop();
	}

	cout<<s3<<endl;


	return 0;
}
	
	

	
