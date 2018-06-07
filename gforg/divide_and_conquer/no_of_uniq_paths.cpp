/*
 * Number of Unique paths: Given a M X N matrix with initial position at top-left corner, find the number of possible unique paths to reach the bottom right corner of the grid from the initial position.
 *
 * NOTE: Possible moves can be either down or right at any point in time, i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].
 *
 * Link: https://practice.geeksforgeeks.org/problems/number-of-unique-paths/0/?ref=self
 */

#include<bits/stdc++.h>
using namespace std;

/*calculating the number of function calls to compare between Naive recursion and memoized Recursion */

int no_of_calls_naive_rec = 0;
int no_of_calls_dp = 0;

int find_path_count1(int i, int j, int m, int n);
int find_path_count2(int i, int j, int m, int n, int **memo);

int main() {

	int m, n;
	bool choice;

		cin>>m>>n;
		
		cout<<"Naive recursion(0) / Memoization(1) : ";
		cin>>choice;

		if(choice == false) {
			cout<<"\nNumber of paths = "<<find_path_count1(0, 0, m, n)<<endl;
			cout<<"Number of function calls = "<<no_of_calls_naive_rec<<endl;
		}
		else if(choice == true) {

			int **memo = (int **)malloc(sizeof(int *) * m);
			for(int i = 0; i < m; i++)
				memo[i] = (int *)malloc(n * sizeof(int));

			for(int i = 0; i < m; i++) {
				for(int j = 0; j < n; j++) {
					memo[i][j] = -1;
				}
			}
			cout<<"\nNumber of paths = "<<find_path_count2(0, 0, m, n, memo)<<endl;
			cout<<"Number of function calls = "<<no_of_calls_dp<<endl;
		}
		else
			cout<<"\nInvalid choice!"<<endl;
	

	return 0;
}

/*
 * find_path_count1() is naive recursion, which is not efficient at all.
 */


int find_path_count1(int i, int j, int m, int n) {

	no_of_calls_naive_rec++;

	if((i == m - 1 && j == n - 2) || (i == m - 2 && j == n - 1)) {
		return 1;
	}
	else if(i == m-1 )
		return 1;
	else if(j == n-1)
		return 1;

	else
		return (find_path_count1(i, j+1, m, n) + find_path_count1(i+1, j, m, n));
}

/*
 * find_path_count2() : Recursion, but uses Memoization. 
 */


int find_path_count2(int i, int j, int m, int n, int **memo) {

	no_of_calls_dp++;
	
	if(memo[i][j] == -1) {
		if((i == m - 1 && j == n - 2) || (i == m - 2 && j == n - 1)) {
			memo[i][j] = 1;
			return 1;
		}
		else if(i == m - 1) {
			for(int col = 0;  col <= n - 2; col++)
				memo[i][col] = 1;
			
			return 1;
		}
		else if(j == n-1) {
			for(int row = 0; row <= m - 2; row++) {
				memo[row][j] = 1;
			}

			return 1;
		}

		else{
			memo[i][j] = find_path_count2(i, j+1, m, n, memo) + find_path_count2(i+1, j, m, n, memo);
			return memo[i][j];
		}

	}
	else 
		return memo[i][j];
}
		























