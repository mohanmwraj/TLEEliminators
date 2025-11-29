//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1714/A
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
    int n, h, m; cin >> n >> h >> m;

    int sleepTime = h * 60 + m;
    int ans = 1e7;

    for(int i = 0; i < n; ++i){
        int hour_i, min_i;
        cin >> hour_i >> min_i;

        int alarmTime = hour_i * 60 + min_i;
        int diff = alarmTime - sleepTime;
        if(diff < 0) diff += 1440;

        ans = min(ans, diff);
    }

    cout << ans / 60 << " " << ans % 60 << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
