// 3 methods to find fib(n).


#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

//Memoized recursion method.
void fib_memoize_wrapper(unsigned n);
unsigned long fib_memoize_rec(unsigned n);

unsigned long *memo;

//Used by all methods.
unsigned long func_call_count = 0;


int main() {

	unsigned long n;
	cout<<"Enter n: ";
	cin>>n;

	for(unsigned long i = 1; i > 0; i++) {


		sleep(0.70);
		fib_memoize_wrapper(i);
		cout<<"\n"<<endl;
	}

	return 0;
}


void fib_memoize_wrapper(unsigned n) {

	memo = new unsigned long [n];
	for(unsigned i = 0; i < n; i++)
		memo[i] = -1;

	//Seed values.
	memo[0] = 0;
	memo[1] = 1;

	cout<<"n = "<<n<<endl;
	cout<<"fib(n) = "<<fib_memoize_rec(n)<<endl;
	cout<<"Number of function calls = "<<func_call_count<<endl;
	cout<<"Ratio I am looking for: "<<(double)n / (double)func_call_count<<endl;
}


unsigned long fib_memoize_rec(unsigned n) {

	func_call_count++;
	
	if(n == 0)
		return memo[0];
	
	else if(n == 1)
		return memo[1];

	else {

		if(memo[n-1] == -1 && memo[n-2] != -1) 
			memo[n-1] = fib_memoize_rec(n-1);

		else if(memo[n-1] != -1 && memo[n-2] == -1) 
			memo[n-2] = fib_memoize_rec(n-2);

		else if(memo[n-1] == -1 && memo[n-2] == -1) {

			memo[n-1] = fib_memoize_rec(n-1);
			memo[n-2] = fib_memoize_rec(n-2);
		}

		return memo[n-1] + memo[n-2];
	}
}
