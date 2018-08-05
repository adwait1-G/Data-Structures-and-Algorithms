#include<bits/stdc++.h>
using namespace std;

void print_reverse_list(list<int>::iterator it);

list<int> l({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11});

int main() {

	print_reverse_list(l.begin());

	return 0;
}
	
void print_reverse_list(list<int>::iterator it) {

	if(it == l.end()) {
		return;
	}
	
	print_reverse_list(++it);
	cout<<*it<<endl;

	return;
}

