//Link: https://www.codechef.com/problems/TAVISUAL
//Solution correct. TLE. Accepted solution in TAVISUAL1.cpp


#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b);
int find_final_pos(int **pair, int n, int c, int q);

int main() {

	int t, n, c, q, left, right, **pair;

	cin>>t;
	while(t--) {

		cin>>n>>c>>q;
		
		//Allocating memory for storing pairs.
		pair = (int **)malloc(sizeof(int *) * q);
		for(int i = 0; i < q; i++) 
			pair[i] = (int *)malloc(sizeof(int) * 2);


		for(int i = 0; i < q; i++) {
			cin>>pair[i][0];
			cin>>pair[i][1];
		}

		cout<<find_final_pos(pair, n, c, q)<<endl;
		for(int i = 0; i < q; i++)
			free(pair[i]);
		free(pair);
	}

	return 0;
}


int find_final_pos(int **pair, int n, int c, int q) {


	int arr[n+1], *ball_ptr, left, right;

	//Initializing array.
	for(int i = 0; i <= n; i++) {

		if(i == 0)
			arr[0] = -1;
		else
			arr[i] = i;
	}

	ball_ptr = &arr[c];	

	for(int i = 0; i < q; i++) {

		left = pair[i][0];
		right = pair[i][1];

		if(*ball_ptr < left)
			continue;
		
		else if(*ball_ptr > right)
			continue;

		else {

			while(left <= right) {
				swap(&arr[left], &arr[right]);
				left++;
				right--;
			}

			if(arr[*ball_ptr] == *ball_ptr)
				continue;

			else {
				ball_ptr = &arr[*ball_ptr];
			}
		}
	}

	return *ball_ptr;
}

void swap(int *a, int *b) {

	int temp = (*a);
	(*a) = (*b);
	(*b) = temp;
}
