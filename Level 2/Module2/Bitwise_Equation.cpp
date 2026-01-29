//**********************************************************************************
// pbm : https://www.codechef.com/problems/BITEQU
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
    Given an integer N, find four positive distinct integers A, B, C and D such that the following equation holds:

    1 <= a, b, c, d <= 10^18
    ((a & B) | c) ^ d = N
    N < 2^32

*/

/*
    Since N < 2^32 we can represent N in 32 bits.

    Consider d contains N, means all set bit in N also set in d.

    ((a & b) | c) ^ d = N (1 0 1 1 0)

    ((a & b) | c) -> 0 0 0 1 0 0 0 0 0 0 0 0 0
                d -> 0 0 0 1 0 0 0 0 1 0 1 1 0 || d having N + one extra set bit to make d distinct
              ^ (XOR)
    --------------------------------------------
                N -> 0 0 0 0 0 0 0 0 1 0 1 1 0            
    
    d = (1LL << 35) + N;

    IF n is 32 bits, then we can set bit which is > 32 to make d distinct and n will not be affected.

    In my d, all bits that were set in n will be set and additionally 35th bit is also set to make d distinct.

    Therefore, (a & b) | c = 1LL << 35;

    Because of or condition, we can set c = 1LL << 35. one bit needs to set for 1LL << 35, and numbers should be distinct.
    a & b = 0;

    we can choose 1 << 36 and 1 << 37 for a and b.

    then a, b, c, d will be distinct positive integers.

    For a case N == 0:
    we can set two bits
    ((a & b) | c) -> 0 0 1 1 0 0 0 0 0 0 0 0 0
                d -> 0 0 1 1 0 0 0 0 1 0 1 1 0 || d having N + one extra set bit to make d distinct
              ^ (XOR)
    --------------------------------------------
                N -> 0 0 0 0 0 0 0 0 1 0 1 1 0  

    d = (1LL << 35) + (1LL << 36) + n;
    (a & b) | c = (1LL << 35) + (1LL << 36);

    c = 1LL << 35;
    a & b = 1LL << 36;
*/

void solve(){
    ll n; cin >> n;

    ll a, b, c, d;
    a = (1LL << 36) + (1LL << 37);
    b = 1LL << 36;
    c = 1LL << 35;
    d = (1LL << 36) + (1LL << 35) + n;

    cout << a << " " << b << " " << c << " " << d << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
