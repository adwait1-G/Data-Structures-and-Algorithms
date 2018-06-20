#include<bits/stdc++.h>
using namespace std;

int main() {

	unsigned short int t;		//No. of test cases.
	cin>>t;
	unsigned short int w;
	string s;

	while(t--) {
		cin>>w>>s;		//Take input.
		short int count[7] = {0 , 0 , 0 , 0 , 0 , 0 , 0};	
		int first_day;
		if(s == "mon")
			first_day = 0;
		else if(s == "tues")
			first_day = 1;
		else if(s == "wed") 
			first_day = 2;
		else if(s == "thurs") 
			first_day = 3;
		else if(s == "fri")
			first_day = 4;
		else if(s == "sat")
			first_day = 5;
		else if(s == "sun")
			first_day = 6;

		if(w == 28) {
			for(int i = 0; i < 7; i++) {
				count[i] = 4;
			}
		}
		else if(w == 29) {
			for(int i = 0 ; i < 7; i++) {
				if(i == first_day) {
					count[i] = 5;
				}
				else count[i] = 4;
			}
		}
		else if(w == 30) {
			for(int i = 0 ; i < 7; i++) {
				if(i != first_day && i != (first_day+1)%7) {
					count[i] = 4;
				}
				else if(i == first_day) {
					count[i] = 5;
					count[(i+1)%7] = 5;
				}
			}
		}
		else if(w == 31) {
			for(int i = 0 ; i < 7; i++) {
				if(i != first_day && i != (first_day+1)%7 && i != (first_day+2)%7) {
					count[i] = 4;
				}
				else if(i == first_day) {
					count[i] = 5;
					count[(i+1)%7] = 5;
					count[(i+2)%7] = 5;
				}
			}
		}

		for(int i = 0 ; i < 7; i++) {
			cout<<count[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
























