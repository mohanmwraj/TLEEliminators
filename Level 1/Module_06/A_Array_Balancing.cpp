//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1661/A
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
    
    int a[n], b[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    ll sum = 0;
    for(int i = 0; i < n - 1; ++i){
        if((abs(a[i] - a[i + 1]) + (abs(b[i] - b[i + 1]))) > (abs(a[i] - b[i + 1]) + (abs(b[i] - a[i + 1])))){
            swap(a[i + 1], b[i + 1]);
        }
    }

    for(int i = 0; i < n - 1; ++i){
        sum += (abs(a[i] - a[i + 1]) + abs(b[i] - b[i + 1]));
    }

    cout << sum << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
