//Link: https://www.codechef.com/problems/CHEFZOT

#include<bits/stdc++.h>
using namespace std;

int main() {

	int n, value, pos1, pos2, max_len;
	vector<int> v;
	
	//Init values;
	pos1 = -1;
	pos2 = -1;
	max_len = -1;

	cin>>n;
	for(int i = 0; i < n; i++) {
		cin>>value;
		v.push_back(value);
	}

	int i = 0; 
	while(i < v.size()) {
	
		if(pos == -1) {
			pos1 = v.find_first_of(0, i);
			max_len = pos1;
		}
		else {
			pos1 = v.find_first_of(0, i);
			i = i + pos1 + 1;
			pos2 = v.find_first_of(0, i);
			






	cout<<max_len<<endl;

	return 0;
}
