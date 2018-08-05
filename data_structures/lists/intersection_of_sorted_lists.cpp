#include<bits/stdc++.h>
using namespace std;

void display_list(list<int>& l);

int main() {

	system("clear");

	list<int> l1, l2, l3;
	int x;

	cout<<"Insert nodes to list 1: "<<endl;
	cout<<"Enter a number to add it to the list1 or type 'x' to end adding to list1"<<endl;
	while(1) {
		
		scanf("%d", &x);
		if(x == -1)
			break;
		l1.push_back(x);
	}

	fflush(stdin);

	cout<<"Enter a number to add it to list2 or type 'x' to end adding to list2"<<endl;
	while(1) {

		scanf("%d", &x);
		
		if(x == -1)
			break;
		
		l2.push_back(x);
	}
	
	fflush(stdin);

	list<int>::iterator it1, it2;
	it1 = l1.begin();
	it2 = l2.begin();


	while(it1 != l1.end() && it2 != l2.end()) {
			
		if(*it1 == *it2)
			l3.push_back(*it1);
		
		else if(*it1 < *it2)
			it1++;

		else
			it2++;
	}


	cout<<"LIST1: "<<endl;
	display_list(l1);
	cout<<"\nLIST2: "<<endl;
	display_list(l2);
	cout<<"\nIntersection List: "<<endl;
	display_list(l3);

	return 0;
}

void display_list(list<int>& l) {

	list<int>::iterator it;

	cout<<"HEAD-->";
	for(it = l.begin(); it != l.end(); it++) {
		cout<<*it<<"-->";
	}

	cout<<"NULL\n"<<endl;
	
}






