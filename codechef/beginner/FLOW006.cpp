#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;		//No. of test cases.
	cin>>t;

	int n;		//The number.
	while(t--) {
		cin>>n;
		int sum = 0;
		while(n != 0) {
			sum = sum + n%10;
			n = n/10;
		}
		cout<<sum<<endl;
	}

	return 0;
}
