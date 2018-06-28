//Link: https://www.codechef.com/problems/JOHNY


#include<bits/stdc++.h>
using namespace std;

int search_johny(vector<unsigned long int>& v, unsigned long length_johny);

int main() {

	int t, n, k;
	unsigned long int value, length_johny;
	cin>>t;

	while(t--) {

		cin>>n;
		vector<unsigned long int> v;
		v.reserve(n);

		v.push_back(-1);

		for(int i = 1; i <= n; i++) {
			cin>>value;
			v.push_back(value);
		}

		cin>>k;
		length_johny = v[k];
		
		sort(v.begin() + 1, v.end());
		cout<<search_johny(v, length_johny)<<endl;
		
		v.clear();
	}

	return 0;
}

int search_johny(vector<unsigned long int>& v, unsigned long length_johny) {

	int left = 1, right = v.size() - 1;

	while(left < right) {

		int mid = (left + right) / 2;

		if(length_johny == v[mid])
			return mid;

		else if(length_johny > v[mid])
			left = mid + 1;

		else
			right = mid - 1;
	}
}







