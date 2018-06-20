#include<bits/stdc++.h>
using namespace std;

int main() {

	unsigned int x ;
	float y;

	scanf("%d , %f" , &x , &y);

	if(x % 5 == 0 && x != 0) {
		if(x+0.5 <= y) {
			printf("%0.2f\n" , y-x-0.5);
		}
		else {
			printf("%0.2f\n" , y);
		}
	}
	else {
		printf("%0.2f\n" , y);
	}

	return 0;
}
