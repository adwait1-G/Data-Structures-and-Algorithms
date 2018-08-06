#include<bits/stdc++.h>
using namespace std;

void find_max();

stack<int> s;
int max_no;

int main() {
	
	s.push(6);
	s.push(123);
	s.push(23);
	s.push(-10);
	s.push(34);
	s.push(1);
	s.push(234);

	find_max();
	cout<<max_no<<endl;

	return 0;
}

void find_max() {

	if(s.empty() == true)
		return;

	else {

		int x = s.top();
		max_no = max(max_no, x);
		s.pop();
		find_max();
		s.push(x);
	}
}


