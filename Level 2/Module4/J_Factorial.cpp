//**********************************************************************************
// pbm : https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/J
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

ll factorial(ll n){
    if(n == 0) return 1;
    return n * factorial(n - 1);
}

void solve(){
    ll n; cin >> n;
    cout << factorial(n) << endl;
}

int main() {
    int T = 1;
   // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
