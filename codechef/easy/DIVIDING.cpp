//Link: https://www.codechef.com/problems/DIVIDING


#include<bits/stdc++.h>
using namespace std;

int main() {

	int n;
	double value, sum = 0, int_part;
	vector<int> v;

	cin>>n;
	v.reserve(n);

	for(int i = 0; i < n; i++) {
		cin>>value;
		sum = sum + value;
		v.push_back(value);
	}
	
	double x = (sqrt(1 + 8 * sum) -1)/ 2.0;

	if(modf(x, &int_part) != 0)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;

	return 0;
}

