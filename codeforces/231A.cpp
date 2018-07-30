#include<bits/stdc++.h>
using namespace std;

int main() {

	int n, count = 0;
	bool a, b, c;

	cin>>n;

	while(n--) {
		
		cin>>a>>b>>c;

		if(a == 0) {
			if(b == 1)
				if(c == 1)
					count++;
		}
		else if(a == 1) {
			if(b == 1)
				count++;
			else if(b == 0 && c == 1)
				count++;
		}
		
	}

	cout<<count<<endl;

	return 0;
}

