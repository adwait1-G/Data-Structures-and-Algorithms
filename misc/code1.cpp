#include<bits/stdc++.h>
using namespace std;

int main() {

	string s = "ADWAITH VENKATESH GAUTHAM";

	cout<<s<<endl;
	cout<<"After rotations: "<<endl;
	for(int i = 0; i < s.length(); i++) {

		rotate(s.begin(), s.begin() + 1, s.end());
		cout<<s<<endl;
	}

	return 0;
}
