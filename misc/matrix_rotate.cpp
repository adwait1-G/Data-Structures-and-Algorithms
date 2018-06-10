#include<stdio.h>

int main() {

	int n;
	printf("Enter n: ");
	scanf("%d", &n);

	int a[n][n];

	printf("Enter elements of matrix: \n");

	for(int i = 0 ; i < n; i++) {
		printf("\nRow %d: ", i);
		for(int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}



	for(int i = 0 ; i < n/2; i++) {                 /* Cover all the n/2 squares present in a matrix */
                for(int j = i; j < n - i - 1; j++) {    /* j ranging from first element of square (i) to last element (n - i - 1) */

                        int temp = a[i][j];
                        a[i][j] = a[n - i - 1][j];
                        a[n - i - 1][j] = a[n - i - 1][n - j - 1];
                        a[n - i - 1][n - j - 1] = a[i][n - j - 1];
                        a[i][n - j - 1] = temp;
                }
        }

	for(int i = 0; i < n; i++) {
		printf("\n");
		for(int j = 0; j < n; j++) {
			printf("%d  ", a[i][j]);
		}
	}

	return 0;
}

