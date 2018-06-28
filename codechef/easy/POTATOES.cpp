//Link: https://www.codechef.com/problems/POTATOES


#include<bits/stdc++.h>
using namespace std;

bool is_prime(int p);
int find_first_prime(int x, int y);

int main() {

	int t, x, y;

	cin>>t;
	while(t--) {

		cin>>x>>y;
		cout<<find_first_prime(x, y)<<endl;
	}

	return 0;
}


int find_first_prime(int x, int y) {

	int num = 1;

	while(is_prime(x+y+num) != true) {

		num++;
	}

	return num;

}

bool is_prime(int p) {

	bool p_is_prime = true;

	for(int i = 2; i <= sqrt(p); i++) {

		if(p % i == 0) {
			p_is_prime = false;
			break;
		}
	}

	return p_is_prime;
}
