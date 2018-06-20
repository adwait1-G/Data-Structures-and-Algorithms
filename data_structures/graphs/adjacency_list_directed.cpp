// Representation of an directed in the form of adjacency list.
// Using stl list to get the job done. But I dont see why I cant use a vector for thi job.

#include<bits/stdc++.h>
using namespace std;


int main() {

	system("clear");

	unsigned int n;
	cout<<"Enter number of vertices: ";
	cin>>n;

	//Initializing an array of lists, each list for each vertex.
	list<int> vertex[n+1];
	list<int>::iterator iter;

	bool choice;

	for(unsigned i = 1; i < n+1; i++) {
		for(unsigned j = 1; j < n+1 ; j++) {
			
			cout<<"Is there an edge from vertex "<<i<<" to "<<j<<" [Yes(1) / No(0)] : "<<endl;
			cin>>choice;

			if(choice == 1) {
				vertex[i].push_back(j);
			}

			else if(choice != 0) {
				cout<<"Invalid choice!"<<endl;
				cout<<"Exiting..."<<endl;
				return -1;
			}
				
		}
	}

	for(int i = 1; i < n+1; i++) {
		iter = vertex[i].begin();
		
		cout<<"["<<i<<"]"<<"-->";

		while(iter != vertex[i].end()) {

			cout<<*iter<<"-->";
			iter++;
		}
			
		cout<<"NULL"<<endl;
	}

	return 0;
}
