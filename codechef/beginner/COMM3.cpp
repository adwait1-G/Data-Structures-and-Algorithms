/*
 * Link: https://www.codechef.com/problems/COMM3
 */

#include<bits/stdc++.h>
using namespace std;

float distance(int x1, int y1, int x2, int y2) {

	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {

	int t;
	cin>>t;

	while(t--) {

		int r, count = 0;
		cin>>r;

		int x1, y1, x2, y2, x3, y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;

		if(distance(x1, y1, x2, y2) <= r)
			count++;
		
		if(distance(x2, y2, x3, y3) <= r)
			count++;

		if(distance(x1, y1, x3, y3) <= r)
			count++;

		if(count >= 2)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	
	}	

	return 0;
}
