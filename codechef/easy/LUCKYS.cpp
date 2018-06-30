//LInk: https://www.codechef.com/problems/LUCKY5


#include<bits/stdc++.h>
using namespace std;

int main() {

	char num[100000];
	int t, count;

	cin>>t;
	while(t--) {

		cin>>num;
		for(int i = 0; i < strlen(num); i++) {

			if(num[i] != '4' && num[i] != '7')
				count++;
		}
	
		cout<<count<<endl;
		count = 0;
	}

	return 0;
}

