//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc251/tasks/abc251_b
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

bool cnt[3000001];

void solve(){
    int n, w; cin >> n >> w;

    int arr[n]; 
    for(int i = 0; i < n; ++i) cin >> arr[i];

    for(int i = 0; i < 3000001; ++i) cnt[i] = false;
    for(int i = 0; i < n; ++i){
        cnt[arr[i]] = true;;
    }

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            cnt[arr[i] + arr[j]] = true;
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            for(int k = j + 1; k < n; ++k){
                cnt[arr[i] + arr[j] + arr[k]] = true;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= w; ++i){
        if(cnt[i] == true) ans++;
    }

    cout << ans << endl;
}

int main() {
    int T = 1;
   // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
