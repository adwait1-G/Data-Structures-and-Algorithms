//Link: https://www.geeksforgeeks.org/friends-pairing-problem/


#include<bits/stdc++.h>
using namespace std;

int main() {

	system("clear");

	int n;
	cout<<"Enter n: ";
	cin>>n;

	int tab[n+1];
	
	//Not using it. So, invalidating.
	tab[0] = -1;

	//Init values.
	tab[1] = 1;
	tab[2] = 2;

	for(int i = 3; i <= n; i++)
		tab[i] = tab[i-1] + (i-1) * tab[i-2];

	cout<<"Number of ways = "<<tab[n]<<endl;

	return 0;
}
