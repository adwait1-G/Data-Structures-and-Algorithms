#include<bits/stdc++.h>
using namespace std;

int main() {

	short int t;
	int n;
	unsigned long int minx , maxx;
	cin>>t;

	while(t--) {
		cin>>n>>minx>>maxx;
		unsigned long int i , j;
		unsigned long int spammer_count = 0;
		unsigned long int nonspammer_count = 0;
		unsigned long int input , output;	
		unsigned long int w[n] , b[n];
		
		for(i = 0 ; i < n ; i++) {
			cin>>w[i]>>b[i];
		}

		for(i = minx; i <= maxx; i++) {
			for(j = 0 ; j < n; j++) {
				if(j == 0) {
					input = i;
					output = w[0] * input + b[0];
				}
				else {
					input = output;
					output = w[j] * input + b[j];
				}
			}

			if(output % 2 == 0) 
				nonspammer_count += 1;
			else
				spammer_count += 1;
		}

		cout<<nonspammer_count<<" "<<spammer_count<<endl;

	}

	return 0;
}
