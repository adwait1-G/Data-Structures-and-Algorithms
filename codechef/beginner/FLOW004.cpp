#include<bits/stdc++.h>
using namespace std;

int main() {
	
	unsigned short int t;		//No. of test cases.
	unsigned int n;			//The number.

	cin>>t;

	while(t--) {
		cin>>n;
		int count = 0;		//Number of digits in 'n'.
		unsigned int temp = n;
		while(temp != 0) {
			temp = temp / 10;
			count++;
		}

		cout<<(n%10) + (n/(int)pow(10 , count - 1))<<endl;
	}

	return 0;
}
