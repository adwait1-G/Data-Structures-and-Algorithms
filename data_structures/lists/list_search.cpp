//Link: https://www.geeksforgeeks.org/search-an-element-in-a-linked-list-iterative-and-recursive/

#include<bits/stdc++.h>
using namespace std;

void display_list();
int search_list_iterative(int x);
int search_list_recursive(list<int>::iterator iter);

list<int> l;
int x, ndx = 0;

int main() {

	int choice;

	while(1) {

		cout<<"Options: "<<endl;
		cout<<"0. Insert node"<<endl;
		cout<<"1. Search for element - iterative"<<endl;
		cout<<"2. Search for element - recursive"<<endl;
		cout<<"3. Display List"<<endl;
		cout<<"4. Clear Screen"<<endl;
		cout<<"5. Exit"<<endl;

		cin>>choice;
			
		switch(choice) {

			case 0:
				cout<<"\nEnter element: ";
				cin>>x;

				l.push_front(x);
				display_list();
				break;
			
			case 1:
				cout<<"Enter element to search: "<<endl;
				cin>>x;
				cout<<"Index where element is found = "<<search_list_iterative(x)<<endl;
				break;
			
			case 2:
				cout<<"Enter element to search: "<<endl;
				cin>>x;
				cout<<"Index where element is found = "<<search_list_recursive(l.begin())<<endl;
				ndx = 0;
				break;
			
			case 3:
				display_list();
				break;

			case 4:
				system("clear");
				break;
			
			case 5:
				return -1;

		}

	}

	return 0;
}

void display_list() {

	list<int>::iterator iter = l.begin();
	
	cout<<"LIST"<<endl;
	while(iter != l.end()) {
		cout<<*iter<<"-->";
		iter++;
	}

	cout<<"NULL"<<endl;

	return;
}


int search_list_iterative(int x) {

	list<int>::iterator iter = l.begin();
	int i = 0;
	
	while(iter != l.end()) {
		if(x == *iter)
			return i;

		i++;
		iter++;
	}

	if(iter == l.end())
		return -1;
}

int search_list_recursive(list<int>::iterator iter) {

	if(iter == l.end())
		return -1;
	
	if(*iter == x)
		return ndx;

	else {
		ndx++;
		return search_list_recursive((++iter));
	}
}


















