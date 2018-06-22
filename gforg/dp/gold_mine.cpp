//Link: https://www.geeksforgeeks.org/gold-mine-problem/


#include<bits/stdc++.h>
using namespace std;

long long find_max_gold(long long x, long long y);

long long m, n;
long long func_call_count = 0;

//required for memoization.
long long **gold;

//Required to store amount of gold in each field.
long long **g;

int main() {

	system("clear");

	cout<<"Enter n and m : ";
	cin>>n>>m;

	//Allocating required memory.
	g = (long long **)malloc(sizeof(long long *) * n);
	for(long long i = 0; i < n; i++)
		g[i] = (long long *)malloc(sizeof(long long) * m);

	gold = (long long **)malloc(sizeof(long long *) * n);
	for(long i = 0; i < n; i++)
		gold[i] = (long long *)malloc(sizeof(long long ) * m);


	//Taking in amount of gold in each field and initializing each cell in memopad to -1.
	cout<<"Enter amount of gold: ";
	for(long long i = 0; i < n; i++) {
		cout<<"Row "<<i<<": ";
	
		for(long long j = 0; j < m; j++) {
			cin>>g[i][j];
			gold[i][j] = -1;

		}
	}


	for(long long i = 0; i < n; i++)
		gold[i][m-1] = g[i][m-1];

	
	long long max_gold = INT_MIN;

	for(long long i = 0; i < n; i++) {

		gold[i][0] = find_max_gold(i, 0);
		
		if(max_gold < gold[i][0])
			max_gold = gold[i][0];
	}


	for(long long i = 0; i < n; i++) {
		cout<<endl;
		for(long long j = 0; j < m; j++) {
			cout<<gold[i][j]<<" ";
		}
	}

	cout<<"Max gold = "<<max_gold<<endl;
	cout<<"Number of function calls = "<<func_call_count<<endl;


	//Deallocating memory from heap.
	for(long long i = 0; i < n; i++) {
		free(gold[i]);
		free(g[i]);
	}
	
	free(gold);
	free(g);
	
	return 0;
}


long long find_max_gold(long long x, long long y) {
	
	func_call_count++;

	//If value is already computed, just retrive it and return it.
	if(gold[x][y] != -1)
		return gold[x][y];


	//These blocks are executed only if gold[x][y] == -1 => Value has never been computed ever before.
	
	//All base cases.
	if(y == m-2) {

		if(x == 0) 
			gold[x][y] = g[x][y] + max(g[x][y+1], g[x+1][y+1]);
	

		else if(x != 0 && x != n-1) 
			gold[x][y] = g[x][y] + max(g[x][y+1], max(g[x+1][y+1], g[x-1][y+1]));
	
		else if(x == n-1)
			gold[x][y] = g[x][y] + max(g[x][y+1], g[x-1][y+1]);
	
	
		return gold[x][y];
		
	}
	//All other cases.
	else {
		//First compute value and memoize it.
		gold[x][y+1] = find_max_gold(x, y+1);

		if(x != n-1) {
			gold[x+1][y+1] = find_max_gold(x+1, y+1);
		}

		if(x != 0) {
			gold[x-1][y+1] = find_max_gold(x-1, y+1);
		}

		if(x == 0) 
			gold[x][y] = g[x][y] + max(gold[x][y+1], gold[x+1][y+1]);
		
		else if(x > 0 && x < n-1)
			gold[x][y] = g[x][y] + max(gold[x][y+1], max(gold[x+1][y+1], gold[x-1][y+1]));

		else if(x == n-1)
			gold[x][y] = g[x][y] + max(gold[x][y+1], gold[x-1][y+1]);

				
		return gold[x][y];
	}

}

