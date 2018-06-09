//

#include<bits/stdc++.h>
using namespace std;

int main(void) {

	unsigned long int n , k , number , count = 0;
	cin>>n>>k;

	for(int i = 0; i < n ; i++) {
		cin>>number;
		if(number%k == 0) 
			count++;
	}
	cout<<count<<endl;

	return 0;
}
