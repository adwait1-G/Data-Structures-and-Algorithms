/*
 * Link: https://www.codechef.com/problems/TRACE
 */

#include<bits/stdc++.h>
using namespace std;

//Recursive algorithm - O(n^3) complexity.
void find_all_trace1(int **mat, int n, int x, int y);

//O(n^2) algorithm.
void find_all_trace2(int **mat, int n, int x, int y);

void find_all_trace3(int **mat, int n, int x, int y);

vector<int> v;	//To store all the traces.




void trace_of_biggest(int **mat, int n);
int find_max(vector<int>& v);


int main() {

	int t;
	cin>>t;

	while(t--) {

		v.clear();

		int n, **mat;
		cin>>n;

		//n * n Matrix : Dynamically allocated.
		mat = (int **)malloc(sizeof(int *) * n);
		for(int i = 0; i < n; i++)
			mat[i] = (int *)malloc(sizeof(int) * n);

		//Taking input of n X n Matrix.
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin>>mat[i][j];

		
		find_all_trace3(mat, n-1, 1, 0);
		find_all_trace3(mat, n-1, 0, 1);
		trace_of_biggest(mat, n);

		cout<<find_max(v)<<endl;

	}

	return 0;
}

/*
 * find_all_trace1() : The  first thing I could think is the brute force solution. Consider all the submatrices and get the answer. I felt it is beautiful, but it is a bad algorithm - O(n^3) algo.
 *
 * 

void find_all_trace1(int **mat, int n, int x, int y) {

	if(n == 2) 
		v.push_back(mat[x][y] + mat[x+1][y+1]);
	else {

		int trace = 0;
		int i = x, j = y;
		
		while(i < x + n && j < y + n) {
			trace = trace + mat[i][j];
			i++;
			j++;
		}

		v.push_back(trace);

		find_all_trace(mat, n-1, x, y);		//Top left submatrix.
		find_all_trace(mat, n-1, x+1, y);	//Bottom left submatrix.
		find_all_trace(mat, n-1, x, y+1);	//Top right submatrix.
		find_all_trace(mat, n-1, x+1, y+1);	//Bottom right submatrix.
	}

	return;
}

*/

/*
 * I got TLE for the recursive solution. Obvious!
 * I observed a property of the problem which helped in getting to this algorithm - O(n^2) complexity and it is recursive solution.
 *
 * Even this is giving TLE :)
 */


/*

void find_all_trace2(int **mat, int n, int x, int y) {

	if(n == 1)
		v.push_back(mat[x][y]);
	else {

		int trace = 0, i = x, j = y, k = 0;

		while(k < n) {

			trace += mat[i][j];
			i++;
			j++;
			k++;
		}

		v.push_back(trace);

		find_all_trace2(mat, n-1, x + 1, 0);
		find_all_trace2(mat, n-1, 0, y + 1);
	}

	return;
}

*/

/*
 * find_all_trace3(): This is the iterative alternative for the above algorithm. All the function call overhead is removed. Iterative alternative is more cache aware. 
 *
 * And it worked!. 
 */


void find_all_trace3(int **mat, int n, int x, int y) {

	int n_it = n, trace = 0, i, j, k;

	while(n_it > 0) {

		if(n_it == 1) {
			v.push_back(mat[x][y]);
			break;
		}
		else { 

			trace = 0;
			i = x;
			j = y;
			k = 0;

			while(k < n_it) {

				trace += mat[i][j];
				i++;
				j++;
				k++;
			}

			v.push_back(trace);

			n_it--;
			if(x == 0 && y != 0)
				y++;
			else if(x != 0 && y == 0)
				x++;
		}
	}

	return;
}


void trace_of_biggest(int **mat, int n) {

	int trace = 0;
	for(int i = 0; i < n; i++)
		trace += mat[i][i];

	v.push_back(trace);

	return;
}

int find_max(vector<int>& v) {

	int max = -INT_MAX;

	for(int i = 0; i < v.size(); i++) {

		if(v[i] > max)
			max = v[i];
	}

	return max;
}










