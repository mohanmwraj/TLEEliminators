//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc356/tasks/abc356_d
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
    Given a number N and a mask M, find the popcount of N & M.
    Popcount is the number of set bits in a number. 

    summation of popcount of (N & M) for all k = 0 to N, 0 <= N < 2^K
    where K is the number of bits in M.

*/

/*

    if the i-th bit is set in M, --> # of numbers from 0 to N with i-th bit set
    if the i-th bit is not set in M, --> 0 contribution from i-th bit

    For any bit i, the # of numbers from 0 to N with i-th bit set can be calculated as:
    cycle = 2^(i+1)
    complete_cycles = (N + 1) / cycle
    rem = (N + 1) % cycle   

    Ex: N = 6 9 4 2 3

    if i want to place 8 in 3rd position, - - 8 - - ,
    the number of possible numbers 0 to 68 for the first tw0 digits, 10 for each 4th and 5th position.
    69 * 10^2
*/
ll mod = 998244353;
void solve(){
    ll n, m;
    cin >> n >> m;

    ll res = 0;
    for(ll i = 0; i < 60; i++){
        if((m & (1LL << i))) {
        // ll cycle = (1LL << (i + 1));
        // ll complete_cycles = (n + 1) / cycle;
        // ll rem = (n + 1) % cycle;
        // res += complete_cycles * (1LL << i);
        // res += max(0LL, rem - (1LL << i));
            ll temp = n;
            temp >>= (i + 1);
            temp *= (1LL << i);
            temp %= mod;
            if(n & (1LL << i)){
                temp += ((n % (1LL << i)) + 1);
                temp %= mod;
            }
            
            res += temp;
            res %= mod;
        }
    }
    cout << res << endl;
}

int main() {
    int T = 1;
   // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
