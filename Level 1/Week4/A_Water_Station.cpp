//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc305/tasks/abc305_a
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

    int val1 = n % 5;
    int val2 = 5 - (n%5);

    if(val1 < val2){
        cout << n - val1 << endl;
    } else {
        cout << n + val2 << endl;
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
