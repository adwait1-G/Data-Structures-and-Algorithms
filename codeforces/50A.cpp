#include<bits/stdc++.h>
using namespace std;

int find_no_dominos(int m, int n);

int main() {

	int m, n;
	cin>>m>>n;

	if(m > n) {
		int temp = m;
		m = n;
		n = temp;
	}

	//m is always smaller than n.
	cout<<find_no_dominos(m, n)<<endl;
	return 0;
}

int find_no_dominos(int m, int n) {

	if(m == 1 && n == 1)
		return 0;
	
	else if(m == 1 && n == 2)
		return 1;

	else if(m == 1 && n > 2) 
		return n/2;

	else  {
		if(m % 2 == 0)
			return n * (m/2);

		else
			return (m/2) * n + find_no_dominos(m - 2*(m/2), n);
	}
}
		
