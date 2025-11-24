//**********************************************************************************
// pbm : 
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
    int n, k; cin >> n >> k;

    vector<string> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];

    int ans = 1;
    for(int i = 1; i < n; ++i){
        ans += v[0] == v[i];
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
