// 3 methods to find fib(n).


#include<bits/stdc++.h>
using namespace std;


//Naive recursion method. Least efficient.
void fib_naive_rec_wrapper(unsigned n);
unsigned long fib_naive_rec(unsigned n);

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

	fib_memoize_wrapper(n);
	cout<<"\n"<<endl;

	fib_naive_rec_wrapper(n);
	cout<<"\n"<<endl;

	return 0;
}

void fib_naive_rec_wrapper(unsigned n) {
	
	cout<<"Naive recursion: "<<endl;
        cout<<"fib(n) = "<<fib_naive_rec(n)<<endl;
        cout<<"Number of function calls = "<<func_call_count<<endl;
        cout<<"2 ^ n = "<<pow((double)2, (double)n)<<endl;

	func_call_count = 0;
}

void fib_memoize_wrapper(unsigned n) {

	memo = new unsigned long [n];
	for(unsigned i = 0; i < n; i++)
		memo[i] = -1;

	//Seed values.
	memo[0] = 0;
	memo[1] = 1;

	cout<<"Memoized recursion: "<<endl;
	cout<<"fib(n) = "<<fib_memoize_rec(n)<<endl;
	cout<<"Number of function calls = "<<func_call_count<<endl;
}



unsigned long fib_naive_rec(unsigned n) {

	func_call_count++;

	if(n == 0)
		return 0;

	else if(n == 1)
		return 1;

	else 
		return fib_naive_rec(n-1) + fib_naive_rec(n-2);
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
