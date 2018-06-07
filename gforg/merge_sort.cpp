/*
 * Merge Sort
 * CLRS.Chapter2: Getting Started
 */

#include<bits/stdc++.h>
using namespace std;


void merge_sort(vector<int> &v, unsigned long int l, unsigned long int r);
void merge_with_sentinels(vector<int> &v, unsigned long int l, unsigned long int m, unsigned long int r);
void merge_without_sentinels(vector<int> &v, unsigned long int l, unsigned long int m, unsigned long int r);

int main() {
	
	system("clear");
	
	int temp;
	unsigned long int n, i;
	vector<int> v;

	cout<<"Enter n: ";
	cin>>n;

	cout<<"\nEnter elements: "<<endl;
	for(i = 0 ; i < n; i++) {
		cin>>temp;
		v.push_back(temp);
	}

	merge_sort(v , 0 , n-1);

	cout<<"\nSorted: "<<endl;
	for(i = 0 ; i < n; i++) 
		cout<<v[i]<<endl;

	return 0;
}

void merge_sort(vector<int> &v, unsigned long int l, unsigned long int r) {

	if(l < r) {
		unsigned long int m = (l + r)/2;
		merge_sort(v, l, m);
		merge_sort(v, m+1, r);
		merge_without_sentinels(v, l, m, r);
	}
}


void merge_with_sentinels(vector<int> &v, unsigned long int l, unsigned long int m, unsigned long int r) {

	unsigned long int n1, n2, i, j;
	n1 = m - l + 1;
	n2 = r - m;

	vector<int> vl , vr;

	for(i = l; i <= m; i++) {
		vl.push_back(v[i]);
	}

	vl.push_back(INT_MAX);

	for(i = m+1; i <= r; i++) {
		vr.push_back(v[i]);
	}

	vr.push_back(INT_MAX);

	i = 0;
	j = 0;
	unsigned long int k = l;

	while(k <= r) {
		if(vl[i] >= vr[j]) {
			v[k] = vr[j];
			j++;
		}
		else {
			v[k] = vl[i];
			i++;
		}
		
		k++;
	}
}


void merge_without_sentinels(vector<int> &v, unsigned long int l, unsigned long int m, unsigned long int r) {

	unsigned long int n1, n2, i, j;
	n1 = m - l + 1;
	n2 = r - m;

	vector<int> vl , vr;
	for(i = l; i <= m; i++) 
		vl.push_back(v[i]);

	for(i = m+1; i <= r; i++) 
		vr.push_back(v[i]);

	i = 0;
	j = 0;

	unsigned long int k = l;

	while(i < n1 && j < n2) {
		if(vl[i] >= vr[j]) {
			v[k] = vr[j];
			j++;
		}
		else {
			v[k] = vl[i];
			i++;
		}

		k++;
	}

	while(i < n1) {
		v[k] = vl[i];
		i++;
		k++;
	}

	while(j < n2) {
		v[k] = vr[j];
		j++;
		k++;
	}
}

