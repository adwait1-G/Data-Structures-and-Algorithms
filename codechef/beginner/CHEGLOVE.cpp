#include<bits/stdc++.h>
using namespace std;

int main() {

	int t;
	int n;
	int i;

	cin>>t;
	while(t--) {
		int front = 1 , back = 1 ;
		cin>>n;
		unsigned long int l[n] , g[n];
		for(i = 0 ; i < n; i++) {
			cin>>l[i];
		}
		for(i = 0 ; i < n; i++) {
			cin>>g[i];
		}

		for(i = 0 ; i < n ; i++) {
			if(l[i] > g[i])
				front = 0;

			if(l[i] > g[n-i-1]) 
				back = 0;
		}

		if(front == 1 && back == 1)
			cout<<"both"<<endl;
		else if(front == 1 && back == 0)
			cout<<"front"<<endl;
		else if(front == 0 && back == 1)
			cout<<"back"<<endl;
		else 
			cout<<"none"<<endl;
	}

	return 0;
}

