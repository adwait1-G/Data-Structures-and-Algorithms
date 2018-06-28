//Link: https://www.codechef.com/problems/OJUMPS


#include<bits/stdc++.h>
using namespace std;

int main() {

	unsigned long int a;
	cin>>a;

	if((a % 6 == 0) || (a % 6 == 1) || (a % 6 == 3))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;

	return 0;
}
