#include<bits/stdc++.h>
using namespace std;

stack<int> s, s1;

void sort();
void pushinplace(int x);

int main() {

	s.push(1);
	s.push(123);
	s.push(-1);
	s.push(-123);
	s.push(2);
	s.push(23);

	sort();

	while(s1.empty() == false) {
		cout<<s1.top()<<endl;
		s1.pop();
	}

	return 0;
}


void sort() {

	while(s.empty() == false) {

		int x = s.top();
		s.pop();

		if(s1.empty() == true)
			s1.push(x);
		else
			pushinplace(x);
	}

	return;
}

void pushinplace(int x) {

	if(s1.empty() == true) {
		s1.push(x);
		return;
	}
	else {

		int y = s1.top();
		if(y > x)
			s1.push(x);
		else {
			s1.pop();
			pushinplace(x);
			s1.push(y);
		}
	}

	return;
}










