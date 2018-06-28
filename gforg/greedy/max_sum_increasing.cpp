//Link: https://www.geeksforgeeks.org/maximum-sum-increasing-order-elements-n-arrays/

#include<bits/stdc++.h>
using namespace std;

int main() {

	int n, m, sum = 0, old_num;
	bool sum_present = true;
	cout<<"Enter number of arrays(n) and length of each array(m) :";
	cin>>n>>m;

	int arr[n][m];

	for(int i = 0; i < n; i++) {
		cout<<"\nArray "<<i<<" : ";
		for(int j = 0; j < m; j++) {
			cin>>arr[i][j];
		}
		cout<<endl;
		sort(arr[i], arr[i]+m, greater<int>());
	}


	for(int i = 0; i < n; i++) {
		cout<<"\nArray "<<i<<" : ";
		for(int j = 0; j < m; j++) {
			cout<<arr[i][j]<<" ";
		}
	}


	for(int i = n-1; i >= 0; i--) {
		

		if(i == n-1) {
			old_num = arr[i][0];
			sum = sum + old_num;
		}
		
		else {
			
			if(arr[i][j] < old_num) {

				old_num = arr[i][j];
				sum = sum + old_num;
			}
			else {

				int j = 0; 
				while(arr[i][j] > old_num) {
					j++;
				}
			}

			if(j == m-1) {
				sum_present = false;
				cout<<"\nNo such sum exists"<<endl;
				break;
			}

			else {
				old_num = arr[i][j-1];
				sum = sum + old_num;
			}
		}


		cout<<"\ni = "<<i<<" , Sum = "<<sum<<endl;
	}

		
	if(sum_present == true) {
		cout<<"Max Sum = "<<sum<<endl;
	}
	else
		return -1;

	return 0;
}
	
