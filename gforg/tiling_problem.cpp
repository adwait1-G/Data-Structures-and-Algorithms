/*
 * Tiling Problem: Given a n by n board where n is of form 2k where k >= 1 (Basically n is a power of 2 with minimum value as 2). The board has one missing cell (of size 1 x 1). Fill the board using L shaped tiles. A L shaped tile is a 2 x 2 square with one cell of size 1×1 missing.
 *
 * Link1: https://www.geeksforgeeks.org/divide-and-conquer-set-6-tiling-problem/
 *
 * Link2: https://www.youtube.com/watch?v=lQhNiv3w45w
 *
 * Link2 is amazing!
 */


#include<bits/stdc++.h>
using namespace std;


int tiling_no = 1, n_orig;

int find_defective_quadrant(int dx, int dy, int n, int x, int y);
void produce_defect(int def_quad, int **mat, int n, int x, int y);
void tile_it_up(int **mat, int n, int x, int y);
void find_xy_of_defective_cell(int **mat, int n, int x, int y, int *dx, int *dy);
void display_board(int **mat, int n_orig);

int main() {

	int n, **mat, dx, dy, def_quad;
	cout<<"Enter n:(Should be a power of 2) ";
	cin>>n;

	n_orig = n;
	//Initializing a 2-D matrix.
	mat = (int **)malloc(sizeof(int *) * n);
	for(int i = 0 ; i < n; i++) {
		mat[i] = (int *)malloc(sizeof(int) * n);
	}

	//Setting each element to 0.
	for(int i = 0 ; i < n; i++) 
		for(int j = 0 ; j < n; j++)
			mat[i][j] = 0;

	
	cout<<"\nEnter the co-ordinates of the defective cell:(x , y) ";
	cin>>dx>>dy;

	//Sanity check of the coordinates entered.
	if(dx < 0 || dx >= n) {
		cout<<"\nInvalid x-coordinate"<<endl;
		return -1;
	}
	if(dy < 0 || dy >= n) {
		cout<<"\nInvalid y-coordinate"<<endl;
		return -1;
	}

	//Setting the value of defective cell to -1.
	display_board(mat, n_orig);
	mat[dx][dy] = -1;	

	display_board(mat, n_orig);

	tile_it_up(mat, n, 0, 0);

	display_board(mat, n_orig);

	return 0;
}


/*
 * find_defective_quadrant() returns the quadrant number which has the defect cell.
 */

int find_defective_quadrant(int dx, int dy, int n, int x, int y) {
	
	if(dx < x + n/2 && dy < y + n/2)
		return 0;
	else if(dx < x + n/2 && dy >= y + n/2)
		return 1;
	else if(dx >= x + n/2 && dy >= y + n/2)
		return 2;
	else if(dx >= x + n/2 && dy < y + n/2)
		return 3;
}

/*
 * After finding the defective quadrant, we have to produce defects in other 3 non-defective quadrants so that we can use the same recursion to solve them.
 */


void produce_defect(int def_quad, int **mat, int n, int x, int y) {

	if(n == 2)
		return;

	if(def_quad == 0) {

		mat[x + n/2 -1][y + n/2] = -2;		//Quadrant 1 
		mat[x + n/2][y + n/2] = -2;		//Quadrant 2
		mat[x + n/2][y + n/2 - 1] = -2;		//Quadrant 3
	}
	else if(def_quad == 1) {

		mat[x + n/2 - 1][y + n/2 - 1] = -2;	//Quadrant 0
		mat[x + n/2][y + n/2] = -2;		//Quadrant 2
		mat[x + n/2][y + n/2 - 1] = -2;		//Quadrant 3
	}
	else if(def_quad == 2) {

		mat[x + n/2 - 1][y + n/2 - 1] = -2;	//Quadrant 0
		mat[x + n/2 -1][y + n/2] = -2;		//Quadrant 1 
		mat[x + n/2][y + n/2 - 1] = -2;		//Quadrant 3
	}
	else if(def_quad == 3) {

		mat[x + n/2 - 1][y + n/2 - 1] = -2;	//Quadrant 0
		mat[x + n/2 -1][y + n/2] = -2;		//Quadrant 1 
		mat[x + n/2][y + n/2] = -2;		//Quadrant 2
	}

}

/*
 * display_board() : Displays the whole board. Can observe the changes in the board.
 */

void display_board(int **mat, int n) {

	cout<<endl;
	for(int i = 0; i < n; i++) {
		cout<<endl;
		for(int j = 0 ; j < n; j++)
			cout<<mat[i][j]<<"\t";
	}

	return;
}

/*
 * tile_it_up() : The main function. It is called recursively.
 */

void tile_it_up(int **mat, int n, int x, int y) {

	if(n == 2) {
		for(int i = x; i < x + n; i++ ) {
			for(int j = y; j < y + n; j++) {
				if(mat[i][j] != -1 && mat[i][j] != -2)
					mat[i][j] = tiling_no;
			}
		
		}
		display_board(mat, n_orig);
		tiling_no++;
	}

	else {
		int dx, dy, def_quad;
		find_xy_of_defective_cell(mat, n, x, y, &dx, &dy);

		def_quad = find_defective_quadrant(dx, dy, n, x, y);
		produce_defect(def_quad, mat, n, x, y);

		tile_it_up(mat, n/2, x, y);		//Quadrant0
		tile_it_up(mat, n/2, x, y + n/2);	//Quadrant1
		tile_it_up(mat, n/2, x + n/2, y + n/2);	//Wuadrant2
		tile_it_up(mat, n/2, x + n/2, y);	//Quadrant3

	}
}

/*
 * Finding the co-ordinates of the defective cell. This has to be combined with find_defective_quadrant.
 */


void find_xy_of_defective_cell(int **mat, int n, int x, int y, int *dx, int *dy) {

	for(int i = x; i < x + n; i++)
		for(int j = y; j < y + n; j++) {
			if(mat[i][j] == -1 || mat[i][j] == -2) {

				*dx = i;
				*dy = j;
			}
		}
}

