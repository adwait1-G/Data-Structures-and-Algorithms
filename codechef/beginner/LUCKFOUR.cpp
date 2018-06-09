#include<bits/stdc++.h>
using namespace std;

int main() {

	int t;		//No. of test cases.		
	cin>>t;

	unsigned long int n;		//The number.
	int count;			//Count of 4s.
	while(t--) {
		count = 0;
		cin>>n;
		while(n != 0) {
			if(n % 10 == 4) {
				count++;
			}
			n = n / 10;
		}
		cout<<count<<endl;
	}

	return 0;
}

