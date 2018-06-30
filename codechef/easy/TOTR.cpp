//Link: https://www.codechef.com/problems/TOTR


#include<bits/stdc++.h>
using namespace std;

void byte_to_eng(string& m, int t);

int main() {

	int t;
	string m;

	cin>>t>>m;

	byte_to_eng(m, t);

	return 0;
}

void byte_to_eng(string& m, int t) {

	map<char, char> byte2eng;
	string byte_str, eng_str;
	char ch;
	//Update map with bytelandian letter as key and english letter as value
	int i = 0;
	for(char ch = 'a'; ch <= 'z'; ch++) {
		byte2eng[ch] = m[i];
		byte2eng[toupper(ch)] = toupper(m[i]);
		i++;
	}
	
	byte2eng['_'] = ' ';

	for(int i = 0; i < t; i++) {

		cin>>byte_str;
		for(int j = 0; j < byte_str.length(); j++) {
			ch = byte_str[j];
			if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_') 
				eng_str.push_back(byte2eng[ch]);

			else 
				eng_str.push_back(ch);
		}

		cout<<eng_str<<endl;

		byte_str.clear();
		eng_str.clear();
	}

	return;
}

