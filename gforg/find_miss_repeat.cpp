/*
 * Find Missing and Repeating: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating/0/?ref=self
 *
 * This algorithm has 2 algorithms.
 *
 * The miss_repeat2 is giving floating point exception for some input. Check!
 */

#include<bits/stdc++.h>
using namespace std;

void miss_repeat1(int a[], int n, int *m, int *r);
void miss_repeat2(int a[], int n, int *m, int *r);

int main() {

	int t, n;
	cin>>t;
	while(t--) {

		cin>>n;
		int a[n+1] ,miss_no = 0, repeat_no = 0;
		for(int i = 1; i <= n; i++) {
			cin>>a[i];
		}
		
//		miss_repeat1(a, n, &miss_no, &repeat_no);	/* RT: O(n) + space: O(n) */
		miss_repeat2(a, n, &miss_no, &repeat_no);	/* RT: O(n) */
		
		cout<<repeat_no<<" "<<miss_no<<endl;
	}

	return 0;
}

void miss_repeat1(int a[], int n, int *m, int *r) {

	int count[n+1];
	for(int i = 1; i <= n; i++)
		count[i] = 0;

	for(int i = 1; i <= n; i++) {
		count[a[i]]++;
	}

	for(int i = 1; i <= n; i++) {

		if(count[i] == 0)
			*m = i;
		else if(count[i] == 2)
			*r = i;
	}

	return;
}
		

void miss_repeat2(int a[], int n, int *m, int *r) {

	int sumofn = 0, nfact = 1, s = 0, p = 1;
	for(int i = 1; i <= n; i++) {
		sumofn += i;
		nfact *= i;
		s += a[i];
		p *= a[i];
	}

	*r = (int)((sumofn - s) / ((float)nfact/p - 1));
	*m = nfact * (*r) / p;
}



