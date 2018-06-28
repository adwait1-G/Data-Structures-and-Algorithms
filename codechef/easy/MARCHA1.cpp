//Link: https://www.codechef.com/problems/MARCHA1


#include<bits/stdc++.h>
using namespace std;

const bool YES = true, NO = false;

bool check_sum_present(vector<int>& v, int n, int sum);

int main() {

	int t, n, m, value;
	vector<int> v;
	v.reserve(n);

	cin>>t;
	while(t--) {

		cin>>n>>m;
		for(int i = 0; i < n; i++) {
			cin>>value;
			v.push_back(value);
		}

		if(check_sum_present(v, n, m) == YES)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}

	return 0;
}

//Simple recursion.
bool check_sum_present(vector<int>& v, int n, int sum) {

	if(sum == 0)
		return YES;
	
	if(sum != 0 && n == 0)
		return NO;


	if(v[n-1] > sum)
		return check_sum_present(v, n-1, sum);
	
	else 
		return check_sum_present(v, n-1, sum) || check_sum_present(v, n-1, sum - v[n-1]);
	
}


