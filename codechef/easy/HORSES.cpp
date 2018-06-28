//Link: https://www.codechef.com/problems/HORSES


#include<bits/stdc++.h>
using namespace std;

unsigned long int find_min_diff(vector<unsigned long int>& v);

int main() {

	short int t, n;
	vector<unsigned long int> v;
	unsigned long int value;
	cin>>t;

	while(t--) {

		cin>>n;
		unsigned long int value;
		v.reserve(n);

		for(unsigned long int i = 0; i < n; i++) {
			cin>>value;
			v.push_back(value);
		}

		cout<<find_min_diff(v)<<endl;
		v.clear();
	}

	return 0;
}


unsigned long int find_min_diff(vector<unsigned long int>& v) {

	sort(v.begin(), v.end());
	unsigned long int min_diff = INT_MAX;

	for(unsigned long int i = 1; i < v.size(); i++) {

		min_diff = min((double)min_diff, (double)abs(v[i] - v[i-1]));
	}

	return min_diff;
}
