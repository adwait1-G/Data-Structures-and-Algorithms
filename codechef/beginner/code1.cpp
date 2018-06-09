/*
 * Testing!!
 */

#include<bits/stdc++.h>
using namespace std;

int main() {

	vector<int> v;

	for(int i = 0; i < 8; i++) {
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	do {

		for(int i = 0; i < v.size(); i++)
			cout<<v[i]<<" ";

		cout<<endl;

	
	} while(next_permutation(v.begin(), v.end()));

	return 0;
}
