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

	sort(v.begin(), v.end());
	
	max_sum = find_arr_sum(v, n);

	cout<<"\n\nMax sum = "<<max_sum<<endl;

	return 0;
}

long long find_arr_sum(vector<long long>&v, long long n) {

	long long sum = 0;
	for(long long i = 0; i < n; i++)
		sum = sum + v[i] * i;

	return sum;
}

