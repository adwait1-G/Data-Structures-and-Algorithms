/*
 * Link: https://www.codechef.com/problems/CHEFWORK
 */

#include<bits/stdc++.h>
using namespace std;


vector<int> a, tr, at;

int main() {

	int n;
	cin>>n;

	int c[n], t[n];
	for(int i = 0; i < n; i++)
		cin>>c[i];

	for(int i = 0; i < n; i++) {
		cin>>t[i];
	}

	
	for(int i = 0; i < n; i++) {
		
		if(t[i] == 1)
			tr.push_back(c[i]);
		
		else if(t[i] == 2) 
			a.push_back(c[i]);

		else if(t[i] == 3) 
			at.push_back(c[i]);
	
	}


	sort(a.begin(), a.end());
	sort(tr.begin(), tr.end());
	sort(at.begin(), at.end());

	if(a[0] + tr[0] < at[0])
		cout<<a[0] + tr[0]<<endl;
	else
		cout<<at[0]<<endl;

	return 0;
}


	
