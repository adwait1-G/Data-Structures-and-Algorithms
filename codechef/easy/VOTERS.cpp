//Link: https://www.codechef.com/problems/VOTERS


#include<bits/stdc++.h>
using namespace std;

void update_vector(vector<int>& v, int n);
void unify_all_lists(vector<int>& v1, vector<int>& v2, vector<int>& v3);

int main() {

	int n1, n2, n3;
	vector<int> v1, v2, v3;
	
	cin>>n1>>n2>>n3;
	v1.reserve(n1);
	v2.reserve(n2);
	v3.reserve(n3);

	update_vector(v1, n1);
	update_vector(v2, n2);
	update_vector(v3, n3);

	unify_all_lists(v1, v2, v3);

	return 0;
}

void update_vector(vector<int>& v, int n) {

	int value;
	
	for(int i = 0; i < n; i++) {
		cin>>value;
		v.push_back(value);
	}

	return;
}

void unify_all_lists(vector<int>& v1, vector<int>& v2, vector<int>& v3) {

	//I need an ordered map because I want the keys in sorted order.
	map<int, int> freq;
	map<int, int>::iterator iter;
	int m = 0;
	vector<int> v;

	for(int i = 0; i < v1.size(); i++) 
		freq[v1[i]]++;

	for(int i = 0; i < v2.size(); i++)
		freq[v2[i]]++;

	for(int i = 0; i < v3.size(); i++)
		freq[v3[i]]++;

	
	iter = freq.begin();
	while(iter != freq.end()) {

		if(iter->second >= 2) {
			m++;
			v.push_back(iter->first);
		}

		iter++;
	}

	system("clear");
	cout<<m<<endl;
	for(int i = 0; i < v.size(); i++)
		cout<<v[i]<<endl;

	return;
}
