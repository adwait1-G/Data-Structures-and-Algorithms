/*
 * Representing an undirected graph in the form of an adjacency matrix.
 */

#include<bits/stdc++.h>
using namespace std;

int main() {

	system("clear");

	//Taking in |V|.
	int n;
	cout<<"Enter the number of vectices in the graph: ";
	cin>>n;

	//Initializing the adjacency matrix. 
	bool a_m[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			a_m[i][j] = -1;

	//Updating the matrix.
	for(int i = 0; i < n - 1; i++) {
		for(int j = i+1; j < n; j++) {
			cout<<"Is there an edge between vectices ("<<i<<" & "<<j<<") Yes(1) / No(0) : "<<endl;
			cin>>a_m[i][j];
		}
	}

	cout<<"Adjacency matrix: "<<endl;
	for(int i = 0; i < n; i++) {
		cout<<endl;
		for(int j = 0; j < n; j++) {
			cout<<a_m[i][j]<<" ";
		}
	}

	cout<<endl;

	return 0;
}
