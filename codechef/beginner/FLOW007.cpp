#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	int n;

	cin>>t;
	while(t--) {
		cin>>n;
		int rev_no = 0;
		while(n != 0) {
			rev_no = rev_no * 10 + n%10;
			n = n / 10;
		}

		cout<<rev_no<<endl;
	}

	return 0;
}
