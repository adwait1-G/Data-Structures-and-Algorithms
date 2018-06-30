//Link: https://www.codechef.com/problems/TAVISUAL
//Solution correct. TLE. Accepted solution in TAVISUAL1.cpp


#include<bits/stdc++.h>
using namespace std;

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

	for(int i = 0; i < q; i++) {
		if(c >= pair[i][0] && c <= pair[i][1])
			c = pair[i][0] + pair[i][1] - c;
	}

	return c;
}
