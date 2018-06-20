/*
 * Link: https://www.codechef.com/problems/ONP
 * Link to STL Stack tutorial: https://www.studytonight.com/cpp/stl/stl-container-stack
 */


#include<bits/stdc++.h>
using namespace std;

void infix_to_postfix(string infix_string, string& postfix_string);

int main() {
	
	int t;
	cin>>t;

	string infix_string, postfix_string;

	while(t--) {

		infix_string.clear();
		postfix_string.clear();

		cin>>infix_string;
		infix_to_postfix(infix_string, postfix_string);
		cout<<postfix_string<<endl;
	}

	return 0;
}


void infix_to_postfix(string infix_string, string& postfix_string) {

	stack<char> s;
	int i = 0;


	while(i < infix_string.length()) {
		
		char ch = infix_string[i];

		if(ch == '(')
			s.push(ch);
		
		else if(ch >= 97 && ch <= 122)
			postfix_string.push_back(ch);
			
		else if(ch == '%' || ch == '*' || ch == '+' || ch == '-' || ch == '/' || ch == '^')
			s.push(ch);

		else if(ch == ')') {

			while(s.top() != '(') {

				postfix_string.push_back(s.top());
				s.pop();
			}

			s.pop();	//Pop the '(' .
		}

		i++;
	}

}










