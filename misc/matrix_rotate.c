#include<stdio.h>

int main() {

	int n;
	printf("Enter n: ");
	scanf("%d", &n);

	int a[n][n];

	printf("Enter elements of matrix: \n");

	for(int i = 0 ; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}



	for(int i = 0 ; i < n/2; i++) {                 /* Cover all the n/2 squares present in a matrix */
                for(int j = i; j < n - i - 1; j++) {    /* j ranging from first element of square (i) to last element (n - i - 1) */

                        int temp = a[i][j];		/* top to temp */
                        a[i][j] = a[n - j - 1][i];	/* Left element to top */
                        a[n - j - 1][i] = a[n - i - 1][n - j - 1];	/* Bottom to Left */
                        a[n - i - 1][n - j - 1] = a[j][n - i - 1];	/* Right to Bottom */
                        a[j][n - i - 1] = temp;				/* temp to right */
                }
        }

	for(int i = 0; i < n; i++) {
		printf("\n");
		for(int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
	}

	return 0;
}

