//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc103/tasks/abc103_c
//**********************************************************************************
#include "bits/stdc++.h"

//#include<iostream>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

/*
    a1, a2, a3, ..., an

    f(m) = m%a1 + m%a2 + m%a3 + ... + m%an
    We need to find the maximum value of f(m).

    a%b = range will be from 0 to b-1. max value of a%b is b-1.

    m%a1 range : 0 to a1 - 1
    m%a2 range : 0 to a2 - 1
    m%a3 range : 0 to a3 - 1
    ...
    m%an range : 0 to an - 1

    max value of f(m) = (a1 - 1) + (a2 - 1) + (a3 - 1) + ... + (an - 1)
            = (a1 + a2 + a3 + ... + an) - n
 
           = sum of all elements - n
            n
           ∑ ai - n
            i=1
    ----------------------------------
    min value of f(m) = 0 + 0 + 0 + ... + 0 = 0
*/

void solve(){
    ll n; cin >> n;
    ll arr[n];
    ll sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    for(int i = 0; i < n; ++i){
        sum += (arr[i] - 1);
    }
    cout << sum << endl;
}   

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
