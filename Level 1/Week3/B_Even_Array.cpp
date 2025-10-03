//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1367/B
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

    int a[n];
    int ei = 0, oi = 0, ee = 0, oe = 0, nm = 0;

    for(int i = 0; i < n; ++i){
        cin >> a[i];

        if(i % 2 == 0) ei++;
        else oi++;

        if(a[i] % 2 == 0) ee++;
        else oe++;

        if(i % 2 != a[i] % 2) nm++;
    } 

    if(ei != ee || oi != oe) {
        cout << -1 << endl;
        return;
    }


    cout << nm / 2 << endl;

}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
