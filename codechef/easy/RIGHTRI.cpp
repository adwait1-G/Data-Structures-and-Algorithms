//Link: https://www.codechef.com/problems/RIGHTRI

#include<bits/stdc++.h>
using namespace std;

bool check_right_tri(int x1, int y1, int x2, int y2, int x3, int y3);

int main() {

	int n, x1, y1, x2, y2, x3, y3, count = 0;
	double d1, d2, d3;
	cin>>n;

	while(n--) {
		
		cin>>x1>>y1>>x2>>y2>>x3>>y3;

		if(check_right_tri(x1, y1, x2, y2, x3, y3) == true)
			count++;
	}

	cout<<count<<endl;

	return 0;
}


bool check_right_tri(int x1, int y1, int x2, int y2, int x3, int y3) {

	int x = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	int y = (x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3);
	int z = (x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3);

	if((x > y && x > z) && (x == y + z))
		return true;

	else if((y > x && y > z) && (y == x + z))
		return true;

	else if((z > x && z > y) && (z == x + y))
		return true;

	else 
		return false;
}

