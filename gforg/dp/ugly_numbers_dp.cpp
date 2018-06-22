#include<bits/stdc++.h>
using namespace std;


unsigned long nth_ugly_number(unsigned long n);
unsigned long min(unsigned long x2, unsigned long x3, unsigned long x5);


int main() {

	unsigned long n;
	cout<<"Enter n: ";
	cin>>n;

	cout<<n<<"th ugly number = "<<nth_ugly_number(n)<<endl;
	return 0;
}



//Using Tabulation(Bottom-up) dp algorithm.
unsigned long nth_ugly_number(unsigned long n) {

	unsigned long i2 = 0, i3 = 0, i5 = 0, count = 1, dp[n];
	unsigned long next_ugly_number;
	int flag;

	//Had forgotten to do this. Havoc created!!
	dp[0] = 1;
	cout<<1<<endl;

	while(count != n) {

		next_ugly_number = min(dp[i2] * 2, dp[i3] * 3, dp[i5] * 5);
		cout<<next_ugly_number<<endl;
		dp[count] = next_ugly_number;

		
		if(next_ugly_number == dp[i2] * 2)
			i2++;
		
		else if(next_ugly_number == dp[i3] * 3)
			i3++;

		else if(next_ugly_number == dp[i5] * 5)
			i5++;

		count++;
		
	}

	return dp[n-1];
}

unsigned long min(unsigned long x2, unsigned long x3, unsigned long x5) {

	if(x2 <= x3 && x2 <= x5 ) 
		return x2;

	else if(x3 <= x2 && x3 <= x5) 
		return x3;

	else if(x5 <= x2 && x5 <= x3) 
		return x5;
}
	
