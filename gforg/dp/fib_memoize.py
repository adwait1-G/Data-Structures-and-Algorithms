#!/usr/bin/python

#Used for memoization.
memo = []
func_call_count = 0;

def fib_memoize_wrapper(n) :
    
    memo[0] = 0
    memo[1] = 1

    print"n = " + str(n)
    print"fib(n) = " + str(fib_memoize_rec(n))
    print"Number of function calls = " + str(func_call_count)
    print"Ratio I am looking for = " + str(func_call_count / n)



def fib_memoize_rec(n) :

    func_call_count += 1

    if n == 0 :
        return memo[0]

    elif n == 1 :
        return memo[1];

    else :
        
        if memo[n-1] == -1 and memo[n-2] != -1 :
            memo[n-1] = fib_memoize_rec(n-1)

        elif memo[n-1] != -1 and memo[n-2] == -1 :
            memo[n-2] = fib_memoize_rec(n-2)

        else :
            
            memo[n-1] = fib_memoize_rec(n-1)
            memo[n-2] = fib_memoize_rec(n-2)
    
        
        return memo[n-1] + memo[n-2]


if __name__ == "__main__" :


    for i in range(0, 999999) :
        memo.append(-1)

    i = 1
    while i > 0 :
        
        fib_memoize_wrapper(i)
        print"\n"
    



