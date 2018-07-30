#include<bits/stdc++.h>
using namespace std;

int main() {

	vector<int> v;
	vector<int>::iterator p1, p2;
	//Constraint on the array.
	v.reserve(100010);
	int max = 4, n, value, count = 0, partial_sum = 0;

	cin>>n;

	for(int i = 0; i < n; i++) {
		cin>>value;
		v.push_back(value);
	}

	//Sorting is an important step.
	sort(v.begin(), v.end());

	p1 = v.begin();
	p2 = v.end() - 1;

	while((*p2) == max) {
		count++;
		p2--;
	}

	while(p1 <= p2) {
		partial_sum = 0;
		
		while(max - partial_sum >= *p2) {
			partial_sum += (*p2);
			p2--;

		}

		while(max - partial_sum >= (*p1)) {
			partial_sum += (*p1);
			p1++;
		}

		count++;
	}

	cout<<count<<endl;
	
	return 0;
}
