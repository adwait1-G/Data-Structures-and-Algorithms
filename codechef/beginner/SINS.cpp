/*
 * Link: https://www.codechef.com/problems/SINS
 */

#include<bits/stdc++.h>
using namespace std;


int main() {

	int t;
	cin>>t;

	while(t--) {

		unsigned long int x, y, result;
		cin>>x>>y;
		
		while((x != y) && ((x > 0) && (y > 0))) {

                	if(x > y) {
                        	x = x%y;
				if(x == 0)
					x = x + y;
			}
        
      	        	else if(y > x) {
                        	y = y%x;
        			if(y == 0)
					y = y + x;
			}
       		}       
        
        	if(x == y)
                	result = x + y;
        
        	else if(x == 0 && y > 0)
                	result = y;
        	else if(y == 0 && x > 0)
                	result = x;

		cout<<result<<endl;
	}

	return 0;
}
