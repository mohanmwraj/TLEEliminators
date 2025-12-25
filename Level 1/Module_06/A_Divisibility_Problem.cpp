//**********************************************************************************
// pbm : https://codeforces.com/contest/1328/problem/A
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
    int a, b;
    cin >> a >> b;

    if(a%b == 0){
        cout << 0 << endl;
    } else {
        cout << (b - (a%b)) << endl;
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
