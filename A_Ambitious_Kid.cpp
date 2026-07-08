//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1866/A
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
    vector<ll> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll minimum_operations = INT_MAX;
    for(int i = 0; i < n; i++){ 
        minimum_operations = min(minimum_operations, abs(a[i]));
    }
    cout << minimum_operations << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
