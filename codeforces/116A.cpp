#include<bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin>>n;

	int a[n], b[n], a_sum = 0, b_sum = 0, max_diff = -1;


	for(int i = 0; i < n; i++) {
		
		cin>>a[i]>>b[i];

		b_sum += b[i];
		a_sum += a[i];

		max_diff = max(max_diff, b_sum - a_sum);
	}

	cout<<max_diff<<endl;

	return 0;
}
