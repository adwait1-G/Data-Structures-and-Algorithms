//Link: https://www.codechef.com/problems/BUYING2


#include<bits/stdc++.h>
using namespace std;

int check_banknotes(vector<int>& v, int x);

int main() {

	int t, n, x, value;
	vector<int> v;

	cin>>t;
	while(t--) {

		cin>>n>>x;
		v.reserve(n);

		for(int i = 0; i < n; i++) {
			cin>>value;
			v.push_back(value);
		}

		cout<<check_banknotes(v, x)<<endl;

		v.clear();
	}

	return 0;
}

int check_banknotes(vector<int>& v, int x) {

	int sum = 0;
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < v.size(); i++)
		sum = sum + v[i];


	if((sum / x == (sum - v[0]) / x) || (sum / x == 0))
		return -1;

	return sum / x;
}






		

