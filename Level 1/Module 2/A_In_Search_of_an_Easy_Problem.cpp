//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1030/A
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
    for(int i = 0; i < n; ++i){
        int val; cin >> val;
        if(val == 1){
            cout << "HARD" << endl;
            return;
        }

    }
    cout << "EASY" << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
