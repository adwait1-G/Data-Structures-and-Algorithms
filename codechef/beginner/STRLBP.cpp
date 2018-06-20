#include<bits/stdc++.h>
using namespace std;

int main() {

	int t;
	string s;

	cin>>t;
	while(t--) {
		short int count = 0;
		cin>>s;
		int i = 0;
		while( i < 8) {
			if((s[i] == '0' && s[(i+1)%8] == '1') || (s[i] == '1' && s[(i+1)%8] == '0'))
				count++;
			i++;
		}
		if(count <= 2) 
			cout<<"uniform"<<endl;
		else if(count > 2) 
			cout<<"non-uniform"<<endl;
	}

	return 0;
}
