/*
 * This solution is perfectly correct . But
 * It is a brute-force method.
 * So , I got the Time Limit Exceeded error.
 * Not the optimal solution.
 */


#include<bits/stdc++.h>
using namespace std;

int main() {

	int t;
	int n;
	unsigned long int h;
	int i , j;
	cin>>t;

	while(t--) {
		cin>>n>>h;

		unsigned long int a[n];
		for(i = 0 ;i < n; i++) {
			cin>>a[i];
		}
		sort(a , a+n);
		j = 0;
		unsigned long int count = 0;
		unsigned long int key;
		while(count != h) {
			count = 0;			
			
			if(j == 0) {
				key = a[0];
				j = 9999;
			}
			else
				key = key + 1;

			for(i = 0 ; i < n ; i++ ) {
				if(a[i]%key == 0)
					count += a[i]/key;
				else
					count += a[i]/key + 1;
			}
		}
		cout<<key<<endl;
	}

	return 0;
}




		
