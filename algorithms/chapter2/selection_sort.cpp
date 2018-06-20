/*
 * Selection Sort. Same algorithm, but a different understanding.
 * CLRS. Chapter2: Getting Started
 * Question 2.2-2
 */

#include<bits/stdc++.h>
using namespace std;

int find_min_index(int v[] , unsigned long int *min_index , unsigned long int n , unsigned long int i);
void swap(int *x , int *y);

int main() {

	system("clear");

	int temp, min;
	unsigned long int n, i, j, min_index;
	
	cout<<"Enter n: ";
	cin>>n;

	int v[n];

	cout<<"Enter elements: "<<endl;
	for(i = 0 ; i < n; i++) 
		cin>>v[i];

	//Input Ends. Algorithm begins.

	for(i = 0; i < n; i++) {

		min = find_min_index(v , &min_index , n , i);
		swap(&v[min_index], &v[i]);
	}

	cout<<"\nSorted: "<<endl;
	for(i = 0 ; i < n; i++) 
		cout<<v[i]<<endl;

	return 0;
}

int find_min_index(int v[] , unsigned long int *min_index , unsigned long int n , unsigned long int i) {

	int min = INT_MAX , index;
	unsigned long int j;
	for(j = i; j < n; j++) {
		if(min > v[j]) {
			min = v[j];
			*min_index = j;
		}
	}

	return min;
}

void swap(int *x , int *y) {
	int temp = (*x);
	*x = *y;
	*y = temp;
}

