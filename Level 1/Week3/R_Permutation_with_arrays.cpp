//**********************************************************************************
// pbm : https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/R
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

    int a[n], b[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    sort(a, a+n);
    sort(b, b+n);

    for(int i = 0; i < n; ++i){
        if(a[i] != b[i]){
            cout << "no" << endl;
            return;
        }
    }

    cout << "yes" << endl;

}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
