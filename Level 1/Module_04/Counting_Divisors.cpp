//**********************************************************************************
// pbm : https://cses.fi/problemset/task/1713
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
    int n; cin >> n;
    int ans = 0;
    // for(int i = 1; i <= n; ++i){.  ========TLE
    //     if(n % i == 0){
    //         ans++;
    //     }
    // }

    for(int i = 1; i <= sqrt(n); ++i){
        if(n % i == 0){
            ans++; 
            if(n/i != i){
                ans++;
            }
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
