/*
 * This is a way more structured code of SPAMCLAS problem. But I have used unnecessary memory by using a neuron class. All shit!
 * Look into SPAMCLAS1.cpp.
 *
 * But the limit is still exceeding :(
 */



#include<bits/stdc++.h>
using namespace std;

class neuron {
	private:
		unsigned long int input;	//Input to the neuron.
		unsigned long int output;	//Output of the neuron.
		unsigned long int w , b;	//w = Weight. b = Bias.
	
	public:
		void enter_input(unsigned long int i) {
			input = i;
		}
		
		void update_info() {
			cin>>w>>b;
		}
		
		unsigned long int return_output() {
			unsigned long int out = w * input + b;
			return out;
		}

};


int main() {
	short int t;		//No. of test cases.
	int n;			//Number of layers.
	unsigned long int minx , maxx;	//Minimum and maximum User_IDs.
	cin>>t;

	while(t--) {
		cin>>n>>minx>>maxx;
		unsigned long int i , j;		//Loop variables.
		unsigned long int spammer_count = 0;	//No. of spammers.	
		unsigned long int nonspammer_count = 0;	//No. of spammers.	
		neuron nrn[n];
		for(i = 0; i < n ; i++ ) {
			nrn[i].update_info();
		}

		for(i = minx; i <= maxx; i++) {
			nrn[0].enter_input(i);
			for(j = 1; j < n; j++) {
				nrn[j].enter_input(nrn[j-1].return_output());
			}
			
			if(nrn[n-1].return_output() % 2 == 0)
				nonspammer_count += 1;
			else
				spammer_count +=1;
		}

		cout<<nonspammer_count<<" "<<spammer_count<<endl;

	}

	return 0;
}



