/*
 * Link: https://www.codechef.com/problems/AMR15A
 */

#include<bits/stdc++.h>
using namespace std;

bool readiness(int arr[], int n);

int main() {

	int n;
	cin>>n;

	int arr[n];

	for(int i = 0; i < n; i++)
		cin>>arr[i];

	if(readiness(arr, n) == true)
		cout<<"READY FOR BATTLE"<<endl;
	else
		cout<<"NOT READY"<<endl;

	return 0;
}


bool readiness(int arr[], int n) {

	int even = 0, odd = 0;
	for(int i = 0; i < n; i++) {

		if(arr[i] % 2 == 0)
			even++;
		else
			odd++;

	}

	if(even > odd)
		return true;
	else
		return false;
}
