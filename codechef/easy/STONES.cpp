//Link: https://www.codechef.com/problems/STONES
//This solution seems corrrect, but it is broken.


#include<bits/stdc++.h>
using namespace std;

int no_jewels_mined(string& j, string& s);

int main() {

	int t;
	string j, s;

	cin>>t;
	while(t--) {

		cin>>j;
		cin>>s;

		cout<<no_jewels_mined(j, s)<<endl;
	}

	return 0;
}

int no_jewels_mined(string& j, string& s) {

	int no_mined = 0;
	map<char, int> mapj;
	set<char> sets(s.begin(), s.end());
	set<char>::iterator iter;

	char ch1 = 'a';

	//INIT
	for(int i = 0; i < 26; i++) {

		mapj[ch1] = 0;
		mapj[ch1 + 32] = 0;

	}

	//UPDATE
	for(int i = 0; i < j.length(); i++) 
		mapj[j[i]]++;

	iter = sets.begin();
	
	//Find no. of jewels mined.
	while(iter != sets.end()) {

		if(mapj[*iter] > 0)
			no_mined++;
		
		iter++;
	}

	return no_mined;
}





