#include<bits/stdc++.h>
using namespace std;

int main() {

	short int t;	//Number of test cases.
	int p;		
	int count = 0;	//Minimum number of menus.
	cin>>t;

	while(t--) {
		count = 0;
		cin>>p;

		while(p > 0) {
			while((int)(log2(p)) > 11) {
				p = p - pow(2 , 11);
				count++;
			}

			p = p - pow(2 , (int)(log2(p)));
			count++;
		}
		cout<<count<<endl;
	}

	return 0;
}
		
