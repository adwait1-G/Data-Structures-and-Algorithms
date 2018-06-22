//Link: https://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/

#include<bits/stdc++.h>
using namespace std;

unsigned coin_change_count(int s[], int m, int n);

unsigned func_call_count = 0;

int main() {

	int m, n;
	cout<<"Enter m and n: ";
	cin>>m>>n;

	int s[m];

	for(int i = 0; i < m; i++)
		cin>>s[i];

	cout<<"Number of ways = "<<coin_change_count(s, m, n)<<endl;
	cout<<"NUmber of function calls = "<<func_call_count<<endl;

	return 0;
}


unsigned coin_change_count(int s[], int m, int n) {

	func_call_count++;

	if(n == 0)
		return 1;

	if(n < 0)
		return 0;

	if(m <= 0 && n >= 1)
		return 0;

	return coin_change_count(s, m-1, n) + coin_change_count(s, m, n-s[m-1]);

}
