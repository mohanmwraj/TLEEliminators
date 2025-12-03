//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1475/A
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

/*
    A number with only even divisors is a power of 2
*/

void solve(){
    ll n; cin >> n;
    // for(int i = 2; i * i <= n; ++i){
    //     if(i % 2 != 0 && n % i == 0){
    //         cout << "YES" << endl;
    //         return;
    //     }
    // }

    // cout << "NO" << endl;

    while(n % 2 == 0){
        n /= 2;
    }

    if(n != 1){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
