//Link: https://www.geeksforgeeks.org/delete-middle-element-stack/

#include<bits/stdc++.h>
using namespace std;

void delete_middle_element();

stack<int> s;
int stk_size = 0;

int main() {
	

	s.push(1);
	s.push(2);
	s.push(4);
	s.push(5);
	s.push(6);

	delete_middle_element();

	while(s.empty() == false) {

		cout<<s.top()<<endl;
		s.pop();
	}

	return 0;
}


void delete_middle_element() {

	static int count = 0;

	if(s.empty() == true) {
		return;
	}

	else {
		int x = s.top();
		s.pop();
		stk_size++;
		cout<<stk_size<<endl<<endl;;
		delete_middle_element();

		if((stk_size % 2 == 0) && (count == stk_size / 2 - 1)) {
			count++;
			return;
		}
		else if ((stk_size % 2 == 1) && (count == stk_size / 2)) {
			count++;
			return;
		}

		else {
			s.push(x);
			count++;
		}

		return;
	}
}


