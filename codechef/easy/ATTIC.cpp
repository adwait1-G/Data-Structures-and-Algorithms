//Link: https://www.codechef.com/problems/ATTIC


#include<bits/stdc++.h>
using namespace std;

int find_no_days(string& path);

int main() {

	int t;
	string p;

	cin>>t;
	while(t--) {

		cin>>p;
		cout<<find_no_days(p)<<endl;
	}

	return 0;
}

int find_no_days(string& path) {

	int day_count = 0, max_len = INT_MIN, hole_init_pos = 0, hole_end_pos, hole_len;
	string::iterator iter;

	int i = 0;
	while(i < path.length()) {
		
		//Find initial position of the hole and process string till that position.
		hole_init_pos = path.find_first_of('.', i);

		//If no more holes are found, return day_count;
		if(hole_init_pos == -1)
			return day_count;

		i = hole_init_pos;
		//Parse through the hole completely to get length of hole.
		hole_len = 0;
		i = path.find_first_of('#', i) ;
		hole_len = i - 1 - hole_init_pos;

		if(max_len < hole_len) {
			//Learn to jump.
			day_count++;
			max_len = hole_len;
		}

	}

	return day_count;
}





		

