#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

// https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/F

void solve(){
    ll n, m;
    cin >> n >> m;
    cout << n % 10 + m % 10 << endl;

}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
