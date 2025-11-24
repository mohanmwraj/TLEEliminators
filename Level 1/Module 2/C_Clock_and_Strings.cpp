//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1971/c
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;

    for(int i = 1; i <= 12; ++i){
        if(i == a || i == b) s += "a";
        if(i == c || i == d) s += "b";
    }

    cout << (s == "abab" || s == "baba" ? "YES" : "NO" )<< endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
