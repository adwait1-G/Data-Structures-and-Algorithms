/*
 * Question: Due to the constant factors in insertion sort, it can be faster in practice for small problem sizes that merge sort. It makes sense to coarsen the leaves of the recursion by usinng insertion sort within nerge sort when subproblems become sufficiently small. COnsider a modification to merge sort in whicb n/k sublists of length k are sorted using insertiion sort and then merged using the standard merging mechanism, where k is the valye to be determined.
 *
 * CLRS, Chapter 2: Getting started
 * Problems 2-1.
 */


#include<bits/stdc++.h>
using namespace std;

void merge_sort(vector<int> &v, unsigned int l, unsigned int r, unsigned int k);
void merge(vector<int> &v, unsigned int l, unsigned int m, unsigned int r, unsigned int k);
void insertion_sort(vector<int> &v, unsigned int l, unsigned int r);

int main() {

	int temp;
	unsigned int n, i, k;
	vector<int> v;

	cout<<"Enter n: ";
	cin>>n;

	cout<<"\nEnter elements: "<<endl;
	for(i = 0 ; i < n; i++) {
		cin>>temp;
		v.push_back(temp);
	}

	cout<<"Enter k: ";
	cin>>k;

	merge_sort(v, 0, n-1);

	cout<<"\nSorted: "<<endl;
	for(i = 0 ; i < n; i++) 
		cout<<v[i]<<endl;

	return 0;
}


void merge_sort(vector<int> &v, unsigned int l, unsigned int r, unsigned int k) {

	if(r - l + 1 > k) {
		unsigned int m = (r + l)/2;
		merge_sort(v, l, m, k);
		merge_sort(v, m+1, r, k);
	}

	insertion_merge(v, l, m, r, k);

}











