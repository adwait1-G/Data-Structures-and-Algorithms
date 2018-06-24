//Link: https://www.geeksforgeeks.org/maximize-sum-arrii/

#include<bits/stdc++.h>
using namespace std;


long long find_arr_sum(vector<long long>& v , long long n);

int main() {
	
	long long n, temp, max_sum = INT_MIN, sum;
	cout<<"Enter n: ";
	cin>>n;

	vector<long long> v;

	for(long long i = 0; i < n; i++) {
		cin>>temp;
		v.push_back(temp);
	}

	bool next_per = true;

	while(next_per == true) {

		next_per = next_permutation(v.begin(), v.end());
		
		if(max_sum < (sum = find_arr_sum(v, n)))
			max_sum = sum;
	
		cout<<sum<<endl;
	}

	
	cout<<"\n\nMax sum = "<<max_sum<<endl;

	return 0;
}

long long find_arr_sum(vector<long long>&v, long long n) {

	long long sum = 0;
	for(long long i = 0; i < n; i++)
		sum = sum + v[i] * i;

	return sum;
}

