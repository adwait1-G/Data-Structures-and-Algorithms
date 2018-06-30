//Link: https://www.codechef.com/problems/SUBGCD


#include<bits/stdc++.h>
using namespace std;

int gcd2(int a, int b);

int main() {

	int t, n, gcd, value;
	bool gcd_one = false;

	cin>>t;
	while(t--) {

		cin>>n;

		int a[n];

		cin>>gcd;		//Taking in the first element.
		for(int i = 1; i < n; i++) {
			cin>>value;
			if((gcd = gcd2(gcd, value)) == 1)
				gcd_one = true;
		}


		if(gcd_one == true) {
			cout<<n<<endl;
		}
		else
			cout<<-1<<endl;

		gcd_one = false;
	}

	return 0;
}

int gcd2(int a, int b) {

	if(a < b) {
		int temp = a;
		a = b;
		b = temp;
	}

	if(a % b == 0)
		return b;

	while(b != 0) {

		int temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}



