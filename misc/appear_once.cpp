/*
 * Question: Given an array of integers, every element appears thrice except for one which occurs once.
 * Find that element which does not appear thrice.
 * Note: Your algorithm should have a linear runtime complexity.
 */


#include<bits/stdc++.h>
using namespace std;


int main() {

	//sum_of_array will have sum of all elements entered.
	
	int n, value, sum_of_array = 0, sum_of_set_form = 0;
	cin>>n;

	//Store the entries in a set => Only 1 copy of each element is stored.
	set<int> set_form;
	set<int>::iterator iter;


	for(int i = 0; i < n; i++) {
		cin>>value;
		sum_of_array += value;
		set_form.insert(value);
	}

	//sum_of_array will have sum of all elements entered.
	//Elements are being stored directly into the set. 

	for(iter = set_form.begin(); iter != set_form.end(); iter++)
		sum_of_set_form += (*iter);

	int no_once = (3 * sum_of_set_form - sum_of_array) / 2;

	cout<<"Number appeared once = "<<no_once<<endl;

	return 0;
}
	



