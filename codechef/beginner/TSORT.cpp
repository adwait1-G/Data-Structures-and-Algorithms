#include<bits/stdc++.h>
using namespace std;

int main() {

	unsigned int t , n;
	cin>>t;
	unsigned int arr[t];
	for(int i = 0; i < t; i++) {
		cin>>arr[i];
	}

	for(int i = 0; i < t ; i++) { 
		for(int j = 0; j < t-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	for(int i = 0 ; i < t ; i++) {
		cout<<arr[i]<<endl;
	}

	return 0;
}
