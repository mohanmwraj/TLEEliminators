//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc258/tasks/abc258_a
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

    if(n >= 60){
        int k = n%60;
        if(k < 10){
            cout << 22 << ":" << 0 << k << endl; 
        } else {
            cout << 22 << ":"  << k << endl; 
        }
    } else {
        if(n < 10){
            cout << 21 << ":" << 0 << n << endl; 
        } else {
            cout << 21 << ":"  << n << endl; 
        }
        //cout << "21:" << n << endl;
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
