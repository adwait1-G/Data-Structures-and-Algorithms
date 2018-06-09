#include<bits/stdc++.h>
using namespace std;

struct recipe {
	double q;
	double p;
	double d;
};

int main() {

	int t;
	int n;
	
	cin>>t;
	while(t--) {
		cin>>n;
		struct recipe r[n];
		double total_loss = 0;
		for(int i = 0 ;i < n ; i++ ) {
			cin>>r[i].p>>r[i].q>>r[i].d;
			
			total_loss += (r[i].q)*(r[i].d)*(r[i].d)*(r[i].p)/10000.00000000;
		}
		
		printf("%lf\n" , total_loss);
	}

	return 0;
}
