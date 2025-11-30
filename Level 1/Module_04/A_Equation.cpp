//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1269/A
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
    1 <= x <= n: 5x is not composite, 7x is not composite
    9x, 8x are always composite. a - b = n; 4x and next composite 6x difference won't be n.
    22x and 21x are next consecutive composties.
*/

void solve(){
    int n; cin >> n;
    cout << 9 * n << " " << 8 * n << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
