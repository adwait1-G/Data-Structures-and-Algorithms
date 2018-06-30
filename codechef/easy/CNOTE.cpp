//Link: https://www.codechef.com/problems/CNOTE


#include<bits/stdc++.h>
using namespace std;

int main() {

	unsigned int t, x, y, budget, n, p, c, i;
	bool yes_lucky;
	cin>>t;
	while(t--) {

		yes_lucky = false;		//Reseting this variable is important.
		
		cin>>x>>y>>budget>>n;
		unsigned int pages = x - y;
		
		for(i = 0; i < n; i++) {

			cin>>p>>c;
			
			if(c <= budget && p >= pages) {
				yes_lucky = true;
			}
		}

		if(yes_lucky == true)
			cout<<"LuckyChef"<<endl;
		else
			cout<<"UnluckyChef"<<endl;

		yes_lucky = false;		//Reseting this variable is important.
	}

	return 0;
}


	

	
