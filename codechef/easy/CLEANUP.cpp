//Link: https://www.codechef.com/problems/CLEANUP


#include<bits/stdc++.h>
using namespace std;

//All constants required.
const int NOTDONE = 0;
const int DONE = 1;
const int CHEF = 2;
const int ASSISTANT = 3;
const int INIT = 4;
const int IGNORE = 5;

void find_cleanup(int* v, vector<int>& va, vector<int>& vc, int n);

int main() {

	system("clear");

	int t, n, m, done_index;
	cin>>t;

	//2 vectors to store indices of jobs done by assistant and chef.
	vector<int> va, vc;

	//Main array.
	int *v;

	while(t--) {

		cin>>n>>m;
		v = new int[n+1];

		v[0] = IGNORE;
		//COnsider no jobs are done.
		for(int i = 1; i <= n; i++) 
			v[i] = NOTDONE;
	
		//Mark the jobs which are done.
		for(int i = 1; i <= m; i++) {
			cin>>done_index;
			v[done_index] = DONE;
		}
		
		find_cleanup(v, va, vc, n);
		
		for(int i = 0; i < vc.size(); i++)
			cout<<vc[i]<<" ";

		cout<<endl;

		for(int i = 0; i < va.size(); i++)
			cout<<va[i]<<" ";

		cout<<endl;
		
		//Clean everything and get ready for next test case.
		va.clear();
		vc.clear();
		delete [] v;
	}

	return 0;
}

void find_cleanup(int *v, vector<int>& va, vector<int> &vc, int n) {

	//Beginning.
	int old_job = INIT;

	for(int i = 1; i <= n; i++) {

		if(v[i] != DONE) {

			if(old_job == INIT || old_job == ASSISTANT) {

				vc.push_back(i);
				old_job = CHEF;
			}
			
			else if(old_job == CHEF) {

				va.push_back(i);
				old_job = ASSISTANT;
			}
		}
	}

	return ;
}








