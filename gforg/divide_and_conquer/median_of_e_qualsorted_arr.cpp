/*
 * Median of 2 sorted arrays of same size: There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length 2n). The complexity should be O(log(n)). 
 * Link: https://www.geeksforgeeks.org/median-of-two-sorted-arrays/
 */

#include<bits/stdc++.h>
using namespace std;

//O(n) algorithm, n = length of each sorted array.
int method1(int arr1[], int arr2[], int n);

//O(lg n) algorithm: Divide and Conqueer technique.
void method2(int n);
int median, *top1, *bottom1, *top2, *bottom2;


//Helper function:
int find_median(int *top, int n);


int main() {

	int n;
	cout<<"Enter n: ";
	cin>>n;

	int arr1[n], arr2[n];

	cout<<"Enter array1 elements: "<<endl;
	for(int i = 0 ; i < n; i++) 
		cin>>arr1[i];

	cout<<"\nEnter array2 elements: "<<endl;
	for(int i = 0; i < n; i++)
		cin>>arr2[i];

	
	bool choice;
	cout<<"Merging arrays(0) / Divide and Conquer(1) ";
	cin>>choice;

	if(choice == 0)
		median = method1(arr1, arr2, n);
	else if(choice == 1) {
		top1 = &arr1[0];
		bottom1 = &arr1[n-1];

		top2 = &arr2[0];
		bottom2 = &arr2[n-1];

		method2(n);
	}
	else {
		cout<<"Invalid choice!"<<endl;
		return -1;
	}
		
	cout<<"\nMedian = "<<median<<endl;

	return 0;
}


int method1(int arr1[], int arr2[], int n) {

	int num1, num2, i = 0, j = 0, k;
	for(k = 0; k < 2 * n; k++) {

		if(arr1[i] <= arr2[j]) {
			
			if(k == n-1)
				num1 = arr1[i];
			else if(k == n) {
				num2 = arr1[i];
				break;
			}

			i++;
			
		}
		else {
			
			if(k == n-1)
				num1 = arr2[j];
			else if(k == n) {
				num2 = arr2[j];
				break;
			}

			j++;
		}
		
	}

	/*
	 * The below output statement informs how many iterations it took to find the median. It is printed  to correlate it with the conplexity of algorithm used.
	 */

	cout<<"Method1: Number of iterations: "<<k<<endl;

	float median = (num1 + num2) / 2.0;

	return median;
}
void method2(int n) {

	static int call_count = 0;
	call_count++;

	if(n == 2) {

		/*
		 * Number of function calls made is a direct indication of complexity of algorithm used. Note that for this algorithm, the  number of function calls made will be very close to lg n value.
		 */

		cout<<"No. of function calls = "<<call_count<<endl;
		median = (max(*top1, *top2) + min(*bottom1, *bottom2)) / 2;
		return;
	}
	else {
		if(find_median(top1, n) > find_median(top2, n)) {

			top1 = top1 + n/2;
			bottom2 = bottom2 - n/2;
			n = n / 2;
		
			method2(n);
		}

		else {
			bottom1 = bottom1 - n/2;
			top2 = top2 + n/2;
			n = n/2;

			method2(n);
		}

		return;
	}
}


int find_median(int *top, int n) {

	if(n % 2 == 1) {
		return *(top + n/2);
	}
	else if(n % 2 == 0) {
		return ( *(top + n/2) + *(top + n/2 -1)) / 2;
	}
}





