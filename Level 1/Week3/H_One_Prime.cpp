//**********************************************************************************
// pbm : https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/H
//**********************************************************************************
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
using ll = long long;
using ld = long double;
#define endl "\n";
#define ff first
#define ss second

void solve(){
    int n; cin >> n;
    if(n <= 1) {
        cout << "NO" << endl;
        return;
    }

    for(int i = 2; i < n; ++i){
        if(n % i == 0){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
