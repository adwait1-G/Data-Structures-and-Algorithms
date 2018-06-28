//Link: https://www.codechef.com/problems/TOTR
//UNDONE!


#include<bits/stdc++.h>
using namespace std;

void byte_to_eng(char *byte_alp, int t);

int main() {

	int t;
	char m[27];
	cin>>t>>m;
		
	byte_to_eng(m, t);

	return 0;
}


void byte_to_eng(char *byte_alp, int t) {

	char byte_str[105];
	map<char, char> byte2eng;
	char ch = 'a';

	//Mapping bytelandian letters to proper indian letters.
	for(int i = 0; i < strlen(byte_alp); i++) {
		byte2eng[byte_alp[i]] = 'a' + i;
		byte2eng[toupper(byte_alp[i])] = 'A' + i;
	}


	//Underscore to Blank space.
	byte2eng['_'] = ' ';

	for(int i = 0; i < t; i++) {

		memset(byte_str, '\0', sizeof(byte_str));
		cin>>byte_str;

		for(int j = 0; j < strlen(byte_str); j++) {
			
			if((byte_str[j] >= 'a' && byte_str[j] <= 'z') || byte_str[j] == '_')
				cout<<byte2eng[byte_str[j]];
			else
				cout<<byte_str[j];
		}

		cout<<endl;
	}

	return ;
}















