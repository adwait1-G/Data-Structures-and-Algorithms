//Link: https://www.geeksforgeeks.org/program-nth-catalan-number/

#include<bits/stdc++.h>
using namespace std;

//DP solution using tabulation.
unsigned long catalan(unsigned n);

unsigned count_iterations = 0;
vector<unsigned> memo;

int main() {

	system("clear");

	unsigned n;
	cout<<"Enter n: ";
	cin>>n;

	for(unsigned i = 0; i <= n; i++)
		memo.push_back(0);

	memo[0] = 1;
	memo[1] = 1;

	cout<<"Catalan(n) = "<<catalan(n)<<endl;
	cout<<"Number of function calls = "<<count_iterations<<endl;

	return 0;
}


unsigned long catalan(unsigned n) {


	if(n == 0) 
		return memo[0];
	
	else if(n == 1)
		return memo[1];

	else {

		for(unsigned i = 2; i < n; i++) {
			for(unsigned j = 0; j < i; j++) {
				
				count_iterations++;
				memo[i] = memo[i] + memo[j] * memo[i-j-1];
			}
		}

		return memo[n-1];
	}
}
