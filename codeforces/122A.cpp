#include<bits/stdc++.h>
using namespace std;

int main() {

	int arr[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};

	bool almost_lucky = false;
	int n;
	cin>>n;

	for(int i = 0; i < 14; i++) {
		if(n % arr[i] == 0) {
			almost_lucky = true;
			break;
		}
	}

	if(almost_lucky == true)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	return 0;
}

