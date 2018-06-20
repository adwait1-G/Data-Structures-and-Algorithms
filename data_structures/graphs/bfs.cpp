// Writing a program to discover all vertices of an undirected graph using bfs.

#include<bits/stdc++.h>
using namespace std;

//Required constants.
const int NO_PARENT = -3;	//Applicable only for ROOT vertex.
const int ROOT = -2;
const int UNKNOWN = -1;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

class Vertex {

	public:
		int vertex_id;
		unsigned vertex_color;
		unsigned vertex_distance;
		int vertex_parent;

		list<Vertex&> adj_list;

	public:
		Vertex() {
			vertex_id = UNKNOWN;
			vertex_color = WHITE;
			vertex_distance = INT_MAX;
			vertex_parent = UNKNOWN;
		}
};


int main() {

	unsigned n, s;
	bool choice;
	cout<<"Enter number of vertices: ";
	cin>>n;

	Vertex vertex[n];

	for(int i = 0; i < n; i++) {

		vertex[i].update_id(i);
	}
	
	//Initializing a vertex as source vertex.
	cout<<"\nEnter source vertex: ";
	cin>>s;

	if(s <= 0 || s >= n) {
		cout<<"Invalid vertex entered. Exiting..."<<endl;
		return -1;
	}

	vertex[s].update_distance(0);
	vertex[s].update_color(BLACK);
	vertex[s].update_parent(NO_PARENT);

	
	//Building adjacency list.
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n;j++) {
			
			cout<<"Is there an edge between vertices "<<i<<" & "<<j<<" Yes(1) / No(0) : "<<endl;
			cin>>choice;

			if(choice == 1) {
				vertex[i].adj_list.push_back(vertex[j]);
				vertex[j].adj_list.push_back(vertex[i]);
			}
			
			else if(choice != 0) {
				cout<<"Invalid choice entered. Exiting..."<<endl;
				return -1;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		cout<<i<<"-->";

		for(vertex[i].al_iter = vertex[i].adj_list.begin(); vertex[i].al_iter != vertex[i].adj_list.end(); vertex[i].al_iter++) {
			cout<<vertex[i].al_iter.vid()<<"->";
		}

		cout<<"NULL"<<endl;
	}

	return 0;
}




