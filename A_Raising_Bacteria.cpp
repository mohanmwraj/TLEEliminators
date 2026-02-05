//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/579/A
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

    if(n % 2 == 0){
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
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
