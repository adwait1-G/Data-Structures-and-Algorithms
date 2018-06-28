//Link: https://www.codechef.com/problems/SPCANDY


#include<bits/stdc++.h>
using namespace std;

int main() {

	int t;
	unsigned long int n, k;

	cin>>t;
	while(t--) {

		cin>>n>>k;

		//I had not considered these edge cases before.Got SIGFPE.
		if(n == 0) 
			cout<<"0 0"<<endl;
		
		else if(n > 0 && k == 0)
			cout<<0<<" "<<n<<endl;
		else
			cout<<n/k<<" "<<n%k<<endl;
	}

	return 0;
}
