//**********************************************************************************
// pbm : https://codeforces.com/contest/1549/problem/A
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

/*
    For a prime number p, we can always represent it as the sum of two co-prime numbers 2 and p-1.
    because gcd(2, p-1) = 1 for any odd number p-1.
    since all prime numbers except 2 are odd.

    For a number N, n1, n2, n3, n4 ... which are greater than 1 and are the divisors of N.
    let's consider the number N + 1.

    (N + 1) % N = X1
    (N + 1) % n1 = X2
    (N + 1) % n2 = X3
    (N + 1) % n3 = X4
    ...
    ...
    (N + 1) % nk = Xk+1 
    
    where X1, X2, X3, X4 ... Xk+1 are all equal to 1.

    x1 == x2 == x3 == x4 ... == xk+1 == 1

    Ex: N = 6 -> divisors are 2, 3
    N + 1 = 7
    7 % 6 = 1
    7 % 2 = 1
    7 % 3 = 1       

    For a number N, gives the same remainder when dividing with divisors of N - 1.

    For a prime number p, we need to find two numbers a and b such that:
    remainders of a and b when divided by p are equal.

    5 >= P <= 10^9 => we can always represent p as the sum of two co-prime numbers 2 and p-1.
    because gcd(2, p-1) = 1 for any odd number p-1.
    since all prime numbers except 2 are odd.

*/


void solve(){
    int p; cin >> p;
    cout << 2 << " " << p - 1 << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
