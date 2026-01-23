//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1909/B
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
#include <set>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

/*

    you are given an array a1, a2, ..., an of distinct postive integers. you have to do the following operation exactly once:
    - choose a positive integer k
    - for each i (1 <= i <= n) replace ai with ai mod k.

    Find the value of k such that 1 <= k <= 10^18 and the array a1, a2, .. , an contains exactly 2 distinct values at the end of the operation.

    4, 8, 10, 12, 11, 13

    % 8 => 4, 0, 2, 4, 3, 5

    ai -- Binary --- % 8(last three bits) because 8 = 2^3

    4 -> 0 0 1 0 0 - 4
    8 -> 0 1 0 0 0 - 0
    10 -> 0 1 0 1 0 - 2
    12 -> 0 1 0 1 1 - 4
    11 -> 0 1 0 1 0 - 3
    13 -> 0 1 0 1 1 - 5

    8 -> 2^3 when modulus with 8, the last three bits will be the answer.

    if i divide a number with 2^k, then i get last k bits in binary representation of number as my remainder.

    A1 ------ 1  1 0
    A2 ------ 0  1 0
    A3 ------ 0  1 0
    A4 ------ 1  1 0

    if you divide 2^1 => last 1 bit you will get same answer or with 2^2 => last 2 bits you will get same answer.
    if you divide with 2^3 => last 3 bits you will get different answer. which will give exactly 2 distinct values.

    if you divide the array with 2^1, 2^2, 2^3, 2^4, ... 2^60
    and check when you get exactly 2 distinct values.

    2^60 = 1152921504606846976 < 10^18

    there k = some power of 2 will be the answer. start from 1 to 60 and check when you get exactly 2 distinct values.
*/


void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for(ll &x : a) cin >> x;
    ll ans = -1;
    for(int i = 0; i <= 60; i++){
        ll k = (1LL << i); // 2^i
        set<ll> s;
        for(ll x : a){
            s.insert(x % k);    
        }
        if(s.size() == 2){
            ans = k;
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
