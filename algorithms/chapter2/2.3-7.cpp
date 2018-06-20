/*
 * Problem: Dwscribe a Theta(nlgn)-time algorithm that , given a set S of n integers and another integer x, determinne whether or not there exists 2 elements in S whose sum is exactly x.
 * CLRS, Getting Started, Question 2.3-7
 */


#include<bits/stdc++.h>
using namespace std;

bool algorithm1(vector<int> &v, int x, unsigned int n);
bool algorithm2(vector<int> &v, int x, unsigned int n);

int main() {

	int temp, x;
	unsigned int n, i;
	vector<int> v;
	bool flag = false, choice;
	
	cout<<"Enter n: ";
	cin>>n;

	cout<<"Enter the array of integers: "<<endl;
	for(i = 0; i < n; i++) {
		cin>>temp;
		v.push_back(temp);
	}

	cout<<"\nEnter x: ";
	cin>>x;

	cout<<"Which algorithm to use: O(n^2)-time (0) / O(nlgn)-time (1) ";
	cin>>choice;

	if(choice == false) 
		flag = algorithm1(v, x, n);
	else
		flag = algorithm2(v, x, n);


	if(flag == true)
		cout<<"There exists a pair!!"<<endl;
	else
		cout<<"There exists no pair:("<<endl;

	return 0;
}


bool algorithm1(vector<int> &v, int x, unsigned int n) {

	unsigned int i , j;
	bool flag = false;

	for(i = 0 ; i < n; i++) {
		for(j = 0; j < n; j++) {
			
			if(i == j)
				continue;
			else {
				if(v[i] + v[j] == x) {
					flag = true;
					break;
				}
			}
		}

		if(flag == true)
			break;
	}

	return flag;
}

bool algorithm2(vector<int> &v, int x, unsigned int n) {
	
	unsigned int l = 0, r = n - 1;

	sort(v.begin(), v.end());

	while(l < r) {

		if(v[l] + v[r] == x) {
			return true;
		}

		l++;
		r--;
	}
	
	return false;
}






















