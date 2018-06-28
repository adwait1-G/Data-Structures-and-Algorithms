//Link: https://www.codechef.com/problems/PCYCLE


#include<bits/stdc++.h>
using namespace std;

const bool VISITED = true;
const bool UNVISITED = false;


int find_next_unvisited(int** arr, int n);
void print_all_cycles(int** arr, int first_index);

int main() {

	int n;
	cin>>n;

	//INIT 1= Memory allocation.
	//I need to use a 1-indexed array. That is why, 2*(n+1) bytes are being allocated.
	int **arr;
	arr = (int **)malloc(sizeof(int *) * (n+1));
	for(int i = 0; i <= n; i++)
		arr[i] = (int *)malloc(sizeof(int) * 2);
	
	//INIT 2: Taking in values and marking them UNVISITED.
	for(int i = 1; i <= n; i++) {
		cin>>arr[i][0];
		arr[i][1] = UNVISITED;
	}

	
	print_all_cycles(arr, n);

	return 0;
}


void print_all_cycles(int **arr, int n) {

	vector<vector<int> > cycles;	
	int first_index, cycles_count = 0;

	while((first_index = find_next_unvisited(arr, n)) != 0) {
		
		vector<int> cycle;
		cycles.push_back(cycle);
		
		int j = first_index;

		cycles[cycles_count].push_back(j);			//I pushed the first index and then while() loop starts from next element.
		arr[j][1] = VISITED;
		j = arr[j][0];
		
		while(j != first_index) {


			cycles[cycles_count].push_back(j);		//Add the index to vector.
			arr[j][1] = VISITED;				//Mark it visited.
			j = arr[j][0];					//Then update the value.
		}

		cycles[cycles_count].push_back(first_index);		//Pushing first index again to depict it is a cycle.


		cycles_count++;
	}

	//Print total number of cycles.
	cout<<cycles_count;

	//Print all cycles in order.
	for(int i = 0; i < cycles.size(); i++) {
		cout<<endl;
		for(int j = 0; j < cycles[i].size(); j++) {
			cout<<cycles[i][j]<<" ";
		}
	}

	return ;
}


//Bad algorithm: O(n) Time complexity.I feel can do better.
int find_next_unvisited(int** arr, int n) {

	for(int i = 1; i <= n; i++) {

		if(arr[i][1] == UNVISITED) {
			return i;
		}
	}

	//If all vertices are visited, then return 0. This value is used to terminate the loop.
	return 0;
}





			
			










