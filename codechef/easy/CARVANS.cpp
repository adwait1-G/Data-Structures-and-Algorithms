//Link: https://www.codechef.com/problems/CARVANS


#include<bits/stdc++.h>
using namespace std;

int find_no_max_speed(vector<int>& v);

int main() {

	int t, n, value;
	vector<int> v;

	scanf("%d", &t);

	while(t--) {

		scanf("%d", &n);
		v.reserve(n);

		for(int i = 0; i < n; i++) {
			scanf("%d", &value);
			v.push_back(value);
		}

		cout<<find_no_max_speed(v)<<endl;

		v.clear();
	}

	return 0;
}


int find_no_max_speed(vector<int>& v) {
	
	int count = 0;

	for(int i = 0; i < v.size(); i++) {

		//First car is obviously at max speed.
		if(i == 0) {
			count++;
		}

		else {
			//If max speed of car behind is less than max speed of my car, car behind will go at max speed.
			if(v[i] <= v[i-1])
				count++;
			//Else, car behind will go at my car's speed. 
			else {
				v[i] = v[i-1];
			}
		}
	}

	return count;
}
