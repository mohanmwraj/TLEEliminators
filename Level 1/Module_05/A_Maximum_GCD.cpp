//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1370/A
//**********************************************************************************
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

void solve(){
    int n; cin >> n;

    //  TLE #########################
    // int ans = -1;
    // for(int a = 1; a <= n; ++a){
    //     for(int b = a + 1; b <= n; ++b){
    //         ans = max(ans, __algo_gcd(a, b));
    //     }
    // }
    // cout << ans << endl;

    /*
        if we maximize distance between a and b, we can maximize

        a < b for each divide no of GCD. 
        1 2 3 4 5 6 7 8 ==> a = 4, b = 8. GCD = 4.
    */


    cout << n / 2 << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
