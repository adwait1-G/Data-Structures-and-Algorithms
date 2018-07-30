#include<bits/stdc++.h>
using namespace std;

int main() {

	string s, ab;
	stack<int> stk;
	int n;
	cin>>n;

	while(n--) {

		cin>>s;
	
		if(s.length() <= 10)
			cout<<s<<endl;
		else {
			//First character.
			ab.push_back(s[0]);
			int x = s.length() - 2;
			
			while(x != 0) {
				stk.push(x%10);
				x = x / 10;
			}
			
			while(stk.empty() == false) {
				ab.push_back((char)(stk.top()+48));
				stk.pop();
			}

			ab.push_back(s[s.length() - 1]);
		}

		cout<<ab<<endl;
		ab.clear();

	}

	return 0;
}
