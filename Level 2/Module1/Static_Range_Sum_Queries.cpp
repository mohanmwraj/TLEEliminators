//**********************************************************************************
// pbm : https://www.cses.fi/problemset/task/1646
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
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    for(auto &it:a) cin >> it;

    vector<ll> pre(n+1, 0);
    for(ll i = 1; i <= n; i++){
        pre[i] = pre[i-1] + a[i-1]; // pre[i-1] + a[i-1] because pre[i] is the sum of first i elements,
        // which is pre[i-1] + a[i-1]
    }

    // for( ll i = 0; i < n; ++i){
    //     pre[i] = pre[i-1] + a[i];
    // }
    while(q--){
        ll l, r; cin >> l >> r;
        cout << pre[r] - (l > 0 ? pre[l-1] : 0) << endl;
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
