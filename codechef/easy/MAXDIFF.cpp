//Link: https://www.codechef.com/problems/MAXDIFF


#include<bits/stdc++.h>
using namespace std;

int find_max_diff(vector<int>& v, int n, int k);

int main() {

	int t, n, k, value;
	vector<int> v;

	cin>>t;
	while(t--) {

		cin>>n>>k;
		v.reserve(n);

		for(int i = 0; i < n; i++) {
			cin>>value;
			v.push_back(value);
		}

		cout<<find_max_diff(v, n, k)<<endl;

		v.clear();
	}

	return 0;
}

int find_max_diff(vector<int>& v, int n, int k) {

	int max_diff, sum = 0, sum_of_first = 0, sum_of_last = 0;

	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++) {

		sum = sum + v[i];

		if(i < k) {
			sum_of_first += v[i];
		}
		else if(i > n-k-1) {
			sum_of_last += v[i];
		}
	}

	max_diff = max(abs(sum_of_first - (sum - sum_of_first)), abs(sum_of_last - (sum - sum_of_last)));

	return max_diff;

}
