#include<bits/stdc++.h>
using namespace std;

stack<int> s;
int prev = INT_MAX, x, stk_size, old_top;

void reverse();
void storeinstack();
void display_stack_stub();
void display_stack();

int main() {

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	
	stk_size = s.size();

	cout<<"In main before reverse: "<<endl;
	display_stack_stub();

	reverse();


	cout<<"In main after reverse"<<endl;
	display_stack_stub();


	return 0;
}


void reverse() {

	x = s.top();
	s.pop();

	storeinstack();
	
	return;
}

void storeinstack() {

	if((prev == INT_MAX && s.empty() == true) || s.top() == prev) {
		s.push(x);
		prev = x;
		return;
	}
	
	else {
		int y = s.top();
		s.pop();
		
		storeinstack();
		s.push(y);
	}

	if(s.size() == stk_size) {
		reverse();
	}
}


void display_stack_stub() {

	cout<<"\nTOP: "<<endl;
	display_stack();
	cout<<"\n"<<endl;

}

void display_stack() {

	if(s.empty() == true)
		return;
	else {

		int x = s.top();
		s.pop();
		cout<<x<<endl;
		display_stack();
		s.push(x);
	}
	
	return;
}
		









