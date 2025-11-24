//**********************************************************************************
// pbm : https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/K
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
    for(int i = 1; i <= n; ++i){
        if(n % i == 0){
            cout << i << endl;
        }
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
