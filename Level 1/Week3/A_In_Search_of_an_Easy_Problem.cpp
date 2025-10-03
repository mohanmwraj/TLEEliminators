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
    
    bool is_hard = false; 
    int easy;

    for(int i = 0; i < n; ++i){
        cin >> easy;
        if(easy == 1) is_hard = true;
    }

    if(is_hard){
        cout << "HARD" << endl;
    } else {
        cout << "EASY" << endl;
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
