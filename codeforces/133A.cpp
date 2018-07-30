#include<bits/stdc++.h>
using namespace std;

int main() {

	string p;
	p.reserve(105);

	cin>>p;

	if(find(p.begin(), p.end(), 'H') != p.end()) 
		cout<<"YES"<<endl;

	else if(find(p.begin(), p.end(), 'Q') != p.end()) 
		cout<<"YES"<<endl;
	
	else if(find(p.begin(), p.end(), '9') != p.end()) 
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;


	return 0;
}
		
