#include<bits/stdc++.h>
using namespace std;

int main() {

	unsigned long n, m, a;

	cin>>n>>m>>a;
	cout<<(n/a + 1&&(n%a)) * (m/a + 1&&(m%a))<<endl;

	return 0;
}
