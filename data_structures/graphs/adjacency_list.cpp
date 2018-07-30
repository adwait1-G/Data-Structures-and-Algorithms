/*
 * Adjacency List representation of undirected-graphs.
 */

#include<bits/stdc++.h>
using namespace std;

const bool YES = 1, NO = 0;

void update_adj_list(vector<vector<int> >& adj_list, int u, int v) {

	adj_list[u].push_back(v);
	adj_list[v].push_back(u);
}


int main() {

	system("clear");

	vector<vector<int> > adj_list;
	vector<int> list;
	bool yes_edge ;
	int n;

	cout<<"Enter number of edges: ";
	cin>>n;

	//List init.
	for(int i = 0; i < n; i++) 
		adj_list.push_back(list);

	for(int i = 0; i < n-2; i++) {
		for(int j = i+1; j < n; j++) {
			cout<<"\nIs there an edge between Node "<<i<<" & "<<j<<": Yes(1)/No(0)";
			cin>>yes_edge;


			if(yes_edge == YES)
				update_adj_list(adj_list, i, j);

		}
	}
	
	for(int i = 0; i < n; i++) {
		cout<<"["<<i<<"]-->";
		for(int j = 0; j < adj_list[i].size(); j++)
			cout<<adj_list[i][j]<<"-->";
		cout<<"NULL"<<endl;
	}

	return 0;
}

