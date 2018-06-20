#include<bits/stdc++.h>
using namespace std;

int main() {

	short int t;		//No. of test cases.
	short int n;		//Size of array.
	unsigned int a , b;
	cin>>t;

	while(t > 0) {
		cin>>n;
		unsigned int arr[n] , b[n];
		for(int i = 0; i < n; i++) {
			cin>>arr[i];
			b[i] = arr[i] >> 0x10;
			arr[i] = arr[i] & 0xffff;
		}

		cout<<"Case "<<t<<":"<<endl;
		for(int i = 0 ; i < n; i++) {
			cout<<arr[i]<<" ";
		}
		cout<<endl;

		for(int i = 0; i < n; i++) {
			cout<<b[i]<<" ";
		}

		cout<<endl;
		t--;
	}

	return 0;
}
