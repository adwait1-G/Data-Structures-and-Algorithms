#include<bits/stdc++.h>
using namespace std;

int main() {

	char str[105];
	cin>>str;

	if(strstr(str, "1111111") != NULL || strstr(str, "0000000") != NULL)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	return 0;
}
