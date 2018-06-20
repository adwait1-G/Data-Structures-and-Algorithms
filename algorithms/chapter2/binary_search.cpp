/*
 * Binary Search: Both recursive and iterative algorithms.
 * CLRS,Chatper2: Getting Started
 * Question 2.3-5
 */

#include<bits/stdc++.h>
using namespace std;

unsigned long int binary_search_rec(vector<int> &v, unsigned long int l, unsigned long int r, int key);
unsigned long int binary_search_iter(vector<int> &v, unsigned long int n, int key);

int main() {

	system("clear");

	int key, temp;
	unsigned long int n, i, index;
	vector<int> v;
	bool choice;

	cout<<"Enter n: ";
	cin>>n;

	cout<<"Enter elements in sorted order: "<<endl;
	for(i = 0 ; i < n; i++) {
		cin>>temp;
		v.push_back(temp);
	}

	cout<<"Enter key: ";
	cin>>key;

	cout<<"\nInterative(0) or Recursive(1) : ";
	cin>>choice;

	if(choice == 0) 
		index = binary_search_iter(v, n, key);
	else
		index = binary_search_rec(v, 0, n-1, key);

	cout<<"Index where key is found: "<<index<<endl;

	return 0;
}


unsigned long int binary_search_rec(vector<int> &v, unsigned long int l, unsigned long int r, int key) {

	if(l < r) {
		unsigned long int m = (l + r)/2;

		if(v[m] == key)
			return m;
		else if(key < v[m]) 
			binary_search_rec(v, l, m-1, key);
		else if(key > v[m])
			binary_search_rec(v, m+1, r, key);
	}
}


unsigned long int binary_search_iter(vector<int> &v, unsigned long int n, int key) {
	
	unsigned long int l = 0, r = n-1, m;

	while(l < r) {
		m = (l + r)/2;

		if(key == v[m]) 
			return m;
		else if(key < v[m]) {
			r = m - 1;
		}
		else if(key > v[m]) {
			l = m + 1;
		}
	}
}











