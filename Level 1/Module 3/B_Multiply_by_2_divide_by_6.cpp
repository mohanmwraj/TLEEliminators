//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1374/B
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

    int ops = 0;
    while(n != 1){
        if(n % 6 == 0){
            n /= 6;
            ops++;
        } else if((n * 2) % 6 == 0){
            n = (n * 2) / 6;
            ops += 2;
        } else {
            break;
        }
    }

    cout << ((n == 1) ? ops : -1) << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
