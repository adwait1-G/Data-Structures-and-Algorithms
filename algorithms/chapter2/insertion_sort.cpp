/*
 * CLRS
 * Chapter2: Getting Started
 * Insertion sort
 *
 * Qn 2.1-2 (Insertion sort, sorting in descending order)
 *
 *
 */


#include<bits/stdc++.h>
using namespace std;

void insertion_sort_asc_iter(vector<int> &v, unsigned long int n);
void insertion_sort_asc_rec(vector<int> &v, unsigned long int n);
void insertion_sort_desc_iter(vector<int> &v, unsigned long int n);

int main() {
	
	system("clear");

	vector<int> v;
	unsigned long int n;
	int value;
	bool order , iterec;

	cout<<"Enter n: ";
	cin>>n;
	cout<<"\nEnter the elements: "<<endl;
	for(unsigned long int i = 0 ; i < n; i++) {
		cin>>value;
		v.push_back(value);
	}

	cout<<"Sort in ascending(0) / descending(1) order: ";
	cin>>order;

	if(order == 0) {
		cout<<"Use Iterative(0) / Recursive(1) algorithm: ";
		cin>>iterec;
		if(iterec == 0)
			insertion_sort_asc_iter(v, n);
		else
			insertion_sort_asc_rec(v, n);
	}
	else
		insertion_sort_desc_iter(v, n);

	cout<<"Sorted: "<<endl;
	for(unsigned long int i = 0; i < n; i++) {
		cout<<v[i]<<endl;
	}

	return 0;
}

void insertion_sort_asc_iter(vector<int> &v, unsigned long int n) {

	unsigned long int i , j;
	int key;

	for(i = 1; i < n; i++) {
		key = v[i];
		j = i - 1;
		while(j >= 0 && key < v[j]) {
			v[j+1] = v[j];
			j -= 1;
		}
		v[j+1] = key;
	}
}
	
void insertion_sort_desc_iter(vector<int> &v, unsigned long int n) {
	
	printf("Inside insertion sort desc\n");

	unsigned long int i , j;
	int key;

	for(i = n-2; i >= 0; i--) {
		key = v[i];
		j = i+1;
		while(j <= n-1 && key < v[j]) {
			v[j-1] = v[j];
			j += 1;
		}
		v[j-1] = key;
	}
}

void insertion_sort_asc_rec(vector<int> &v, unsigned long int n) {

	if(n == 0) 
		return;

	else {
		insertion_sort_asc_rec(v, n-1);
		int key = v[n-1];
		int i = n - 2;
		
		while(i >= 0 && key < v[i]) {
			v[i+1] = v[i];
			i = i - 1;
		}

		v[i+1] = key;
	
	}
}
