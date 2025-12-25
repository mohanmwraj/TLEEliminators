//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc169/tasks/abc169_b
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

// 1_000_000_000_000_000_001

void solve(){
    int n; cin >> n;
    ll result = 1;
    for(int i = 0; i < n; ++i){
        ll temp; cin >> temp;
        result *= temp;
    }

    if(result > 1e18) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
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
