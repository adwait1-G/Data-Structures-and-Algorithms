#include<bits/stdc++.h>
using namespace std;


int main() {
	
	list<int> l({1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 123, 43, 90});
	int n;

	cout<<"Size of list = "<<l.size()<<endl;

	cout<<"Enter n: ";
	cin>>n;

	if(n < 0 || n >= l.size()) {
		cout<<"Invalid n"<<endl;
		return -1;
	}
	
	cout<<"\nLIST: \n"<<endl;

	list<int>::iterator it = l.begin();
	cout<<"HEAD-->";
	
	while(it != l.end()) {
		cout<<*it<<"-->";
		it++;
	}

	cout<<"NULL"<<endl;

	list<int>::iterator it1, it2;
	it1 = l.begin();
	it2 = l.begin();

	for(int i = 0; i < n; i++)
		it1++;
	
	while(it1 != l.end()) {
		it1++;
		it2++;
	}

	cout<<"\nNth node from end = "<<*it2<<endl;

	return 0;
}



