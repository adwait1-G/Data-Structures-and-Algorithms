/*
 * Link: https://www.codechef.com/problems/HEADBOB
 */

#include<bits/stdc++.h>
using namespace std;

int decide_person_type(string arr, int n);

int main() {

	int t;
	cin>>t;

	while(t--) {

		int n;
		cin>>n;

		string arr;
		cin>>arr;
		
		int person_type = decide_person_type(arr, n);

		if(person_type == 0)
			cout<<"INDIAN"<<endl;
		else if(person_type == 1)
			cout<<"NON INDIAN"<<endl;
		else if(person_type == 2)
			cout<<"NOT SURE"<<endl;
	}

	return 0;
}


int decide_person_type(string arr, int n) {

	int yes = 0, ind = 0, no = 0;

	for(int i = 0; i < arr.length(); i++) {
		
		if(arr[i] == 'Y')
			return 1;

		else if(arr[i] == 'I')
			return 0;

		else if(arr[i] == 'N')
			no++;
	}

	if(no == n)
		return 2;
}
