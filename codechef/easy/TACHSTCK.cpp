//Link: https://www.codechef.com/problems/TACHSTCK


#include<bits/stdc++.h>
using namespace std;

unsigned long find_max_pairs(vector<unsigned long>& v, unsigned long d);

int main() {

	unsigned long n, d, value;
	vector<unsigned long> v;

	cin>>n>>d;

	for(int i = 0; i < n; i++) {
		cin>>value;
		v.push_back(value);
	}

	cout<<find_max_pairs(v, d)<<endl;

	return 0;
}

unsigned long find_max_pairs(vector<unsigned long>& v, unsigned long d) {

	unsigned long pair_count = 0, i = 0;
	
	sort(v.begin(), v.end());
	while(i < v.size() - 1) {

		if(v[i+1] - v[i] <= d) {
			pair_count++;
			i = i + 2;
		}
		else
			i = i + 1;
	}

	return pair_count;
}
