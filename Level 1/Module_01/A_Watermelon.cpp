//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/4/A
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

    if(n % 2 == 1 || n == 2){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    int T = 1;
   // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
