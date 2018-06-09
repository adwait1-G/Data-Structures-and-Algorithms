/*
 * Link: https://www.codechef.com/problems/CLFIBD
 *
 * This solution is broken.
 */


#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

void get_count(string& s, vector<int>& v);
bool check_dynamic(vector<int>& v);

int main() {

	int t;
	cin>>t;

	string s;
	vector<int> v;
	
	while(t--) {

		s.clear();
		cin>>s;

		v.clear();

		get_count(s, v);

		if(check_dynamic(v) == true)
			cout<<"Dynamic"<<endl;
		else
			cout<<"Not"<<endl;
	}

	return 0;
}


void get_count(string& s, vector<int>& v) {

	unordered_map<char, int> umap;

	for(int i = 0; i < s.length(); i++) {

		umap[s[i]] += 1;
	}

	for(char ch = 'a'; ch <= 'z'; ch++) {

		if(umap[ch] != 0)
			v.push_back(umap[ch]);
	}

	for(int i = 0; i < v.size(); i++) {
		cout<<v[i]<<" ";
	}

	cout<<endl;
}


bool check_dynamic(vector<int>& v) {

	//Edge case:
	if(v.size() < 3)
		return true;

	bool flag = false;

	sort(v.begin(), v.end());
	
	do {

		for(int k = 0; k < v.size(); k++)
			cout<<v[k]<<" ";
	
		cout<<endl;

		for(int i = 2; i < v.size(); i++) {
			
			if(v[i] = v[i-1] + v[i-2]) {
				flag = true;
				continue;
			}
			else {
				flag = false;
				break;
			}
		}

		if(flag == true)
			return true;

	} while(next_permutation(v.begin(), v.end()));

	return false;
}




















