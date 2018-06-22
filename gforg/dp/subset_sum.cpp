//Link: https://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/


#include<bits/stdc++.h>
using namespace std;

bool check_subset_presence(unsigned a[], unsigned n, unsigned s);

int main() {

	unsigned n, s;
	cout<<"Enter n: ";
	cin>>n;

	unsigned a[n];

	cout<<"\nEnter set: "<<endl;
	for(unsigned i = 0; i < n; i++)
		cin>>a[i];

	cout<<"\nEnter sum: ";
	cin>>s;

	if(check_subset_presence(a, n, s) == true)
		cout<<"There is a subset"<<endl;
	else
		cout<<"There is no subset"<<endl;

	return 0;
}

bool check_subset_presence(unsigned a[], unsigned n, unsigned s) {

	if(s > 0 && n == 0)
		return false;

	if(s == 0)
		return true;

	return check_subset_presence(a, n-1, s-a[n-1]) || check_subset_presence(a, n-1, s);
}
