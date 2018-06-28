#!/usr/bin/python

#Link: https://www.codechef.com/problems/GCD2


def gcd2(x, y) :

    if y == 0 :
        return x
    else :
        return gcd2(y, x%y)



if __name__ == "__main__" :

    t = int(raw_input());

    while t > 0 :

        a, b = raw_input().split()
        a, b = [int(a), int(b)]
    
        print gcd2(b, a)
    
        t = t - 1


