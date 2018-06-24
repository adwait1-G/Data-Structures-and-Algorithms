/*
 * Question: Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 * Try to solve it in linear time/space.
 *
 *
 * Idea: Use radix sort to sort the given array in O(n) time. Then Iterate through the array once and get the maximum difference between 2 successive elements.
 */


#include<bits/stdc++.h>
using namespace std;

void radix_sort(vector<int>& v);
void count_sort(vector<int>& v, int x);
int find_max_element(vector<int>& v);
int find_max_diff(vector<int>& v);

int main() {

	int n, value;
	cout<<"Enter n: ";
	cin>>n;

	vector<int> v;
	v.reserve(n);

	cout<<"Enter elements: ";
	for(int i = 0;i < n; i++) {
		cin>>value;
		v.push_back(value);
	}

	cout<<"Max difference = "<<find_max_diff(v)<<endl;

	return 0;
}


//Core function: Finds maximum difference of 2 successive elements.
int find_max_diff(vector<int>& v) {

	//Edge case.
	if(v.size() < 2)
		return 0;


	int max_diff = INT_MIN;
	radix_sort(v);

	for(int i = 0; i < v.size() - 1; i++) {

		if(max_diff < abs(v[i] - v[i+1]))
				max_diff = abs(v[i] - v[i+1]);
	}

	return max_diff;
}

//Radix sort using counting sort
void radix_sort(vector<int>& v) {

	int max_element = find_max_element(v);

	for(int x = 1; max_element / x > 0; x = x*10) 
		count_sort(v, x);
}


//Finds largest element in a given array.
int find_max_element(vector<int>& v) {

	int max_element = INT_MIN;
	for(int i = 0; i < v.size(); i++) {

		if(max_element < v[i])
			max_element = v[i];
	}

	return max_element;
}

void count_sort(vector<int>& v, int x) {
	
	int n = v.size();
	int op[n], i, count[10] = {0};;


	for(int i = 0; i < v.size(); i++)
		count[ (v[i] / x)%10 ]++;

	for(int i = 1; i < 10; i++)
		count[i] += count[i-1];

	for(int i = v.size()-1;i >= 0; i--) {
		
		op[count[(v[i]/x)%10 ] - 1] = v[i];
		count[ (v[i]/x)%10 ]--;
	}

	for(int i = 0; i < v.size(); i++)
		v[i] = op[i];
}
















