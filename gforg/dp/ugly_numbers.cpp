#include<bits/stdc++.h>
using namespace std;


unsigned nth_ugly_number(unsigned n);
bool check_if_un(unsigned n);


int main() {

	unsigned n;
	cout<<"Enter n: ";
	cin>>n;

	cout<<n<<"th ugly number = "<<nth_ugly_number(n)<<endl;
	return 0;
}



unsigned nth_ugly_number(unsigned n) {

	unsigned count = 1, i = 1;
	while(count != n) {

		i++;
		if(check_if_un(i) == true)
			count++;

	}

	return i;
}

bool check_if_un(unsigned n) {


	while(n % 2 == 0)
		n = n / 2;

	while(n % 3 == 0)
		n = n / 3;

	while(n % 5 == 0)
		n = n / 5;

	if(n == 1)
		return true;
	else
		return false;
}
