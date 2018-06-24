//Link: https://www.geeksforgeeks.org/maximum-path-sum-triangle/


#include<bits/stdc++.h>
using namespace std;

int find_max_sum(int x, int y);

int n;
int **value;
int **sum;

int main() {

	system("clear");

	cout<<"Enter n: ";
	cin>>n;

	value = (int **)malloc(sizeof(int *) * n);
	for(int i = 0; i < n; i++)
		value[i] = (int *)malloc(sizeof(int) * n);

	sum = (int **)malloc(sizeof(int *) * n);
	for(int i = 0; i < n; i++)
		sum[i] = (int *)malloc(sizeof(int) * n);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {

			sum[i][j] = -1;
			value[i][j] = -1;
		}

	cout<<"Enter the triangle : "<<endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			cin>>value[i][j];
		}
	}

	for(int j = 0; j < n; j++)
		sum[n-1][j] = value[n-1][j];
	

	for(int i = 0; i < n; i++) {
		cout<<endl;
		for(int j = 0; j <= i; j++)
			cout<<sum[i][j]<<" ";
	}

	cout<<"Maximum sum = "<<find_max_sum(0, 0)<<endl;
	
	return 0;
}


int find_max_sum(int x, int y) {
	
	//If value is already computed, just retrive and return it.
	if(sum[x][y] != -1)
		return sum[x][y];

	//Base cases. 
	if(x == n-1) 
		return sum[x][y];

	//If max_sum of cell right below is not computed already, compute it.
	if(sum[x+1][y] == -1)
		sum[x+1][y] = value[x+1][y] + find_max_sum(x+1, y);
	
	//If max_sum of cell diagonally down-right is not computed already, computer it.
	if(sum[x+1][y+1] == -1)
		sum[x+1][y+1] = value[x+1][y+1] + find_max_sum(x+1, y+1);


	sum[x][y] = value[x][y] + max(sum[x+1][y], sum[x+1][y+1]);
	return sum[x][y];
}
		
