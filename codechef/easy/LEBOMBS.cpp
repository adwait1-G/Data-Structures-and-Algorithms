//Link: https://www.codechef.com/problems/LEBOMBS


#include<bits/stdc++.h>
using namespace std;

const int SAFE = 0, DESTROYED = 1;
const char BOMB = '1', NOBOMB = '0';

int find_no_safe(string& s, int safe[], int n);

int main() {

	int t, n;
	string s;
	cin>>t;
	while(t--) {

		cin>>n;
		cin>>s;

		int safe[n];
		for(int i = 0; i < n; i++)
			safe[i] = SAFE;

		cout<<find_no_safe(s, safe, n)<<endl;
		
	}

	return 0;
}

//Find number of safe buildings.
int find_no_safe(string& s, int safe[], int n) {
	
	int safe_count = 0;

	//Make note.
	for(int i = 0; i < n; i++) {

		if(i == 0 && s[i] == BOMB) {
			safe[i] = DESTROYED;
			safe[i+1] = DESTROYED;
		}
		else if(i == n-1 && s[i] == BOMB) {
			safe[i] = DESTROYED;
			safe[i-1]= DESTROYED;
		}
		else if(i > 0 && i < n-1 && s[i] == BOMB) {
			safe[i] = DESTROYED;
			safe[i-1] = DESTROYED;
			safe[i+1] = DESTROYED;
		}

	}

	//Count!
	for(int i = 0; i < n; i++) {

		if(safe[i] == SAFE)
			safe_count++;
	}

	return safe_count;
}

		
