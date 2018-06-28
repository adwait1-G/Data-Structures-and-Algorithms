//Link: htglotps://www.codechef.com/problems/LEPERMUT


#include<bits/stdc++.h>
using namespace std;

const bool YES = true;
const bool NO = false;


bool find_local_global_inv(vector<int>& v);

int main() {

	int t, n, value, local_inv, global_inv;
	vector<int> v;

	cin>>t;
	while(t--) {

		cin>>n;
		v.reserve(n);
		
		for(int i = 0; i < n; i++) {
			cin>>value;
			v.push_back(value);
		}
		
		if(find_local_global_inv(v) == YES)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

	return 0;
}
		

bool find_local_global_inv(vector<int>& v) {

	int global_count = 0, local_count = 0;
	
	for(int i = 0; i <= v.size() - 2; i++) {

		//Global Inversions.
		for(int j = i+1; j <= v.size() - 1; j++) {
			if(v[i] > v[j])
				global_count++;
		}
	
		//Local Inversions.
		if(v[i] > v[i+1])
			local_count++;
	}

	if(local_count == global_count)
		return YES;
	else
		return NO;
}
