//**********************************************************************************
// pbm : https://codeforces.com/contest/1660/problem/B
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

    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n);
    if(n == 1){
        if(a[0] > 1){
            cout << "NO" << endl;
            return;
        } else {
            cout << "YES" << endl;
            return;
        }
    }

    if(a[n - 1] - a[n - 2] > 1){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
