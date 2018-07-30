#include<bits/stdc++.h>
using namespace std;

int main() {

	int arr[6][6];
	int move_count = 0, x, y;

	//Not using the 0-indexed row and column.
	for(int i = 0; i < 6; i++) {
		arr[0][i] = -1;
		arr[i][0] = -1;
	}

	//Taking input.
	for(int i = 1; i <= 5; i++) {
		for(int j = 1; j <= 5; j++) {
			cin>>arr[i][j];

			if(arr[i][j] == 1) {
				x = i;
				y = j;
			}
		}
	}
	
	cout<<abs(x - 3) + abs(y - 3)<<endl;

	return 0;
}
