#include<bits/stdc++.h>
using namespace std;

int main() {

	unsigned long int n, m;
	cin>>n>>m;

	unsigned long int a[n], b[n], diff[n], a_sum = 0, b_sum = 0, count = 0;
	for(int i = 0; i < n; i++) {
		cin>>a[i]>>b[i];
		a_sum += a[i];
		b_sum += b[i];
		diff[i] = a[i] - b[i];
	}

	//Impossible case.
	if(m < b_sum) {
		cout<<-1<<endl;
		return 0;
	}
	//Perfect compression case.
	else if(m == b_sum) {
		cout<<n<<endl;
		return 0;
	}
	
	//No compression required case.
	if(a_sum <= m) {
		cout<<0<<endl;
		return 0;
	}
	
	sort(diff, diff + n);

	unsigned long int stuff_to_compress = a_sum - m, diff_sum = 0;
	unsigned long int i = n-1;


	while(diff_sum <= stuff_to_compress && i != 0) {
		cout<<"i = "<<i<<endl;
		if(diff_sum + diff[i] > stuff_to_compress)
			i--;
		else {
			diff_sum += diff[i];
			i--;
			count++;
		}
	}

	cout<<"dbg:  After while loop"<<endl;
	
	if(diff_sum == stuff_to_compress)
		cout<<count<<endl;
	else
		cout<<-1<<endl;

	return 0;
}


	
