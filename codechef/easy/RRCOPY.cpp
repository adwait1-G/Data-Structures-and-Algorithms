//Link: https://www.codechef.com/problems/RRCOPY


#include<bits/stdc++.h>
using namespace std;

int find_min_op(vector<int>& v);

int main() {


	int t, n, value;
	vector<int> v;

	cin>>t;
	while(t--) {

		cin>>n;
		v.reserve(n);

		for(int i = 0; i < n; i++) {
			cin>>value;
			v.push_back(value);
		}

		set<int> s(v.begin(), v.end());

		cout<<s.size()<<endl;
		s.clear();

		v.clear();
	}

	return 0;
}


