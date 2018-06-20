#include<bits/stdc++.h>
using namespace std;

int main() {

	int n;		//NUmber of Test cases.
	int nol;	//Number of lines in each triangle/test case.

	cin>>n;

	while(n--) {

		cin>>nol;
		unsigned short int a[nol*(nol+1)/2];	//To store the input values.
		unsigned short int t[(int)(pow(2 , nol)) -1];	//The tree of sums.

		for(i = 0; i < nol; i++) {
			cin>>a[i];
		}


		
