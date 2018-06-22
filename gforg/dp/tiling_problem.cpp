//Link: https://www.geeksforgeeks.org/tiling-problem/

#include<bits/stdc++.h>
using namespace std;


unsigned long find_count(unsigned n);
vector<unsigned long> memo;

int main() {
	
	unsigned n;
	cout<<"Enter n: ";
	cin>>n;

	for(unsigned i = 0; i <= n; i++)
		vector.push_back(0);

	//Invalidating vector[0]
	vector[0] = -1;

	//Init values
	
	cout<<find_count(n)<<endl;

	return 0;
}

unsigned long find_count(unsigned n) {



