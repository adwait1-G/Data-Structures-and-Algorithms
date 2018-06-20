/*
 * Linear Search - Will work for repeared elements also.
 * CLRS, Chapter2: Getting started, Qn 2.1-3
 */

#include<bits/stdc++.h>
using namespace std;

int main() {

	system("clear");

	int key, temp;
	unsigned int n, i;
	vector<int> v , index;
	
	//Inputs.

	cout<<"Enter n: ";
	cin>>n;

	cout<<"Enter key to be searched: ";
	cin>>key;
	
	cout<<"Enter elements of vector: "<<endl;
	for(i = 0 ; i < n; i++) {
		cin>>temp;
		v.push_back(temp);
	}

	//Inputs over.

	//Actual algorithm for linear search.
	
	for(i = 0; i < n; i++) {
		if(v[i] == key)
			index.push_back(i);
	}

	if(index.empty() == true)
		cout<<"Key not found in array"<<endl;
	else {
		cout<<"Key found in index(ices): "<<endl;
		for(i = 0; i < index.size(); i++) 
			cout<<index[i]<<endl;
	}

	return 0;
}

