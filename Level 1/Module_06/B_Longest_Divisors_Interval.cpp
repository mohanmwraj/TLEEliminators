//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1855/B
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

void solve(){

    // 

    // ll a = 1;
    // for(ll i = 2; i <= 50; ++i){
    //     a = lcm(a, i);
    // }
    // cout << a << endl;

    ll n; cin >> n;

    int i = 1;
    while(n % i == 0) i++;

    cout << i - 1 << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
