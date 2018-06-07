/*
 * Randomized Binary Search: Instead of taking the middle index, take some random index and do the same.
 * Link: https://www.geeksforgeeks.org/randomized-binary-search-algorithm
 *
 * This program is buggy!!. Have to check.
 */

#include<bits/stdc++.h>
using namespace std;

int rand_binary_search(int arr[], int left, int right, int key) {
	
	int rand_pivot = -1;
	srand(time(NULL));
	bool flag = false;

	while(left < right) {
		cout<<"left = "<<left<<", right = "<<right<<", randint = "<<rand_pivot<<endl;
		rand_pivot = rand() % (right - left + 1);


		if(key == arr[rand_pivot]) {
			flag = true;
			return rand_pivot;
		}
		else if(key > arr[rand_pivot]) {
			left = rand_pivot + 1;
		}
		else if(key < arr[rand_pivot]) {
			right = rand_pivot - 1;
		}
	}

	if(flag == false)
		return -1;
}

int main() {

	int n;
	cin>>n;

	int arr[n], key;

	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	
	cout<<"\nKey: ";
	cin>>key;

	cout<<rand_binary_search(arr, 0, n - 1, key)<<endl;

	return 0;
}












	
