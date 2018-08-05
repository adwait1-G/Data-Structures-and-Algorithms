#include<bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin>>n>>m;

	int arr[n+1][2], count = 0;
	vector<int> v;

	for(int i = 0; i <= m; i++)
		v.push_back(i);

	for(int i = 1; i <= n; i++)
		cin>>arr[i][0]>>arr[i][1];

	//0 is left, 1 is right.
	
	for(int i = 1; i <= n; i++) {
		for(int j = arr[i][0]; j <= arr[i][1]; j++)
			v[j] = -1;
	}

	for(int i = 1; i <= m; i++)
		if(v[i] != -1)
			count++;

	cout<<count<<endl;

	for(int i = 1; i <= m; i++)
		if(v[i] != -1)
			cout<<v[i]<<" ";

	cout<<endl;

	return 0;
}
	
