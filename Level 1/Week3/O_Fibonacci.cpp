//**********************************************************************************
// pbm : https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/O
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
    ll n; cin >> n;

    ll fib[n];
    fib[0] = 0;
    if(n != 1) fib[1] = 1;

    for(int i = 2; i < n; ++i){
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    cout << fib[n - 1] << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
