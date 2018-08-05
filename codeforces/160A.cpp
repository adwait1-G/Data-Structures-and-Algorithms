#include<bits/stdc++.h>
using namespace std;

int sum(int *a, int start, int end);

int main() {

	int n, total = 0, my_sum = 0, count = 0, sum_left, sum_right = 0;
	bool found_min = false;
	cin>>n;

	int a[n];

	for(int i = 0; i < n; i++) {
		cin>>a[i];
		total += a[i];
	}

	sum_left = total;

	sort(a, a + n);

	int i = n - 1;

	while(i >= 0) {

		sum_right += a[i];
		sum_left -= a[i];
		count++;
			
		if(sum_right > sum_left) {
			found_min = true;
			break;
		}
	
//Old method: Very inefficient because of that sum() function.
/*
		my_sum += a[i];
		count++;

		if(sum(a, i, n-1) > sum(a, 0, i-1)) {
			found_min = true;
			break;
		}
*/		
		i--;
	}

	if(found_min == true)
		cout<<count<<endl;

	return 0;
}

int sum(int *a, int start, int end) {

	int s = 0;
	for(int i = start; i <= end; i++)
		s += a[i];

	return s;
}
