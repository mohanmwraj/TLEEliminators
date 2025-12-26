//**********************************************************************************
// pbm : https://atcoder.jp/contests/caddi2018b/tasks/caddi2018_a
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
#include<numeric>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

/*
    2^31 ~ 2*10^9
    2^64 ~ 2*10^18

    2^64 > 10^12

    N --- P
    1 --- P
    2 --- [1, 10^6]
    3 --- [1, 10^4]
    4 --- [1, 10^3]
    5 --- [1, 10^2]

    40 --- 1

    because g^N must divide P, any possible gcd g satisfies g^N ≤ P, so g ≤ P^(1/N). 
    Using the problem bound P_max (here 10^12 used in the code), the maximal possible g is floor(P_max^(1/N)). 
    Numeric examples (P_max = 10^12):

N=1: g ≤ 10^12 (trivial, g = P possible).
N=2: g ≤ (10^12)^(1/2) = 10^6.
N=3: g ≤ (10^12)^(1/3) = 10^4.
N=4: g ≤ (10^12)^(1/4) = 10^3.
N=5: g ≤ (10^12)^(1/5) = 10^(12/5) = 10^2.4 ≈ 251 (the comment’s 10^2 is a rough power-of-10 shorthand).
N=40: g ≤ (10^12)^(1/40) = 10^(12/40) = 10^0.3 ≈ 1.995 → floor = 1, so only g = 1 is possible.
N=45: g ≤ (10^12)^(1/45) = 10^(12/45) = 10^0.2666... ≈ 1.844 → floor = 1, so only g = 1 is possible.

we need to check for N > 45, because for N > 45, the maximum possible g is 1.
we can check from 40, for safer side we take 45.

*/


/*
    Given two integers N and P, are not less than 1.
    The values of a1, a2, ..., aN are not known, but it is known that the product of these N integers is P.
    Find the maximum possible value of gcd(a1, a2, ..., aN).

    a1, a2, ..., aN
    g = greatest common divisor of a1, a2, ..., aN all integers.
    p = product of a1, a2, ..., aN
    then g^n divides p.

    then a1, a2, ..., aN can be expressed as:
    a1 = g * b1
    a2 = g * b2
    .
    aN = g * bN

    ai = ci * g for i = 1 to N

    then product of a1, a2, ..., aN
    p = a1 * a2 * ... * aN
      = (c1 * g) * (c2 * g) * ... * (cN * g)
      = (c1 * c2 * ... * cN) * g^N

    2 4 10 6 18
    g = 2

    1(2) 2(2) 5(2) 3(2) 9(2)

    c1 = 1
    c2 = 2
    c3 = 5          
    c4 = 3
    c5 = 9
    c1 * c2 * ... * cN = 1 * 2 * 5 * 3 * 9 = 270

    -------
    gcd(a, b) = g
    g <= min(a, b)

 Problem (in one line):
     Given integers N >= 1 and P >= 1, find the maximum possible value of
     g = gcd(a1, a2, ..., aN) over all integer sequences (a1..aN) whose product
     is P.

 Math trick / insight:
     If g is the gcd of the N numbers, write ai = g * bi. Then
         P = a1 * a2 * ... * aN = (g * b1) * (g * b2) * ... * (g * bN) = g^N * (b1*b2*...*bN).
     Therefore g^N must divide P. Conversely, any integer g with g^N | P can be
     realized (take the bi so that their product is P / g^N and split factors as needed).

     So the maximum g is the largest integer whose N-th power divides P.
     Equivalent (prime-factor view): if P = \prod p_i^{e_i}, then
         g = \prod p_i^{floor(e_i / N)}.

 Code approach used here:
     - Handle small/special cases: if N == 1, answer is P. If N is large (here
         > 45) then even 2^N exceeds the working limit so only g = 1 is possible.
     - Brute-force candidate g from 2 upward. For each g compute g^N using a
         guarded `power()` that returns -1 on overflow (we stop when g^N becomes
         larger than P). If g^N divides P, record g as a valid answer.
     - Finally print the largest valid g found (default 1).

 Why the N>45 check? Because the smallest possible base >1 is 2, and 2^46 is
     already larger than the typical problem bound on P used here; therefore for
     N>45 no g>=2 can satisfy g^N <= P, so the answer is 1.

 Complexity / notes:
     - The brute-force loop checks g up to a point where g^N exceeds P; in many
         inputs this stops early. A faster method is to factor P and compute
         floor(e_i/N) per prime (deterministic and faster for large P).

 Example:
     N = 5, numbers = [2,4,10,6,18] -> product P = 2*4*10*6*18
     gcd of those numbers is 2. Using prime-factor trick on P gives the same
     result by taking floor(exponent / 5) for each prime.

*/
ll power(ll base, ll exp){
    ll result = 1;
    for(ll i = 1; i <= exp; ++i){
        result *= base;
        if(result > ll(1e12 + 5)){
            return -1;
        }
    }
    return result;
}
void solve(){
    ll n, p; cin >> n >> p;

    if(n == 1){
        cout << p << endl;
        return;
    } else if (n > 45){
        cout << 1 << endl;
        return;
    } else {
        ll ans = 1;
        for(ll g = 2; g <= 1e6; ++g){
            ll pow = power(g, n);

            if(pow == -1){
                break;
            }

            if(p % pow == 0){
                ans = g;
            }

        }
        cout << ans << endl;
    }
}


int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
