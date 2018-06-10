#include<bits/stdc++.h>
using namespace std;
int main() {

	int n1, n2;
	cin>>n1>>n2;

	while(n1 != 0) {

		int c = n1&n2;	/* Carry is anding 2 bits */
		n2 = n1 ^ n2;	/* Sum is the xoring of 2 bits */
		n1 =  c << 1;	/* Carry is left shifted by 1 to calculate the sum */
	}

	cout<<n2<<endl;

	return 0;
}
