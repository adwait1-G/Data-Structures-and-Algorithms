#include<bits/stdc++.h>
using namespace std;

int main() {

	short int n;	//Number of rounds.
	short int p1 , p2;//p1 = Score of player1 , p2 = Score of player2 at some iTH round.
	int t1 = 0, t2 = 0;	//t1 = Total score of player1 , t2 = Total score of player2 at some iTH round.

	int w , present_lead , lead;//w = 1 or 2. lead = abs(t1-t2). Who is leading depends on value of w.

	cin>>n;

	for(int i = 0; i < n; i++) {
		cin>>p1>>p2;
		t1 = t1 + p1;
		t2 = t2 + p2;
	
		present_lead = abs(t1 - t2);
		if(i == 0) lead = present_lead;

		if(present_lead >= lead) {
			lead = present_lead;
			if(t1 > t2) w = 1;
			else if (t1 < t2) w = 2;
		}
	}

	cout<<w<<" "<<lead<<endl;

	return 0;
}
