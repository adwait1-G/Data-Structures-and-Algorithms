#include<bits/stdc++.h>
using namespace std;

int main() {

	unsigned long k, n, w, total, mtb;
	cin>>k>>n>>w;
	
	total = k * w * (w + 1) / 2;

	//First, I had put the condition as (n - total) > 0 . But, this will overflow and shit happens.
	if(n >= total)
		cout<<0<<endl;
	else
		cout<<total - n<<endl;

	return 0;
}
	
