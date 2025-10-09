//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc258/tasks/abc258_a
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
    int T; cin >> T;

    int hour = 21;
    if(T >= 60){
        hour = 22;
        T -= 60;
    }

    cout << hour << ":" ;//<< T << endl;
    if(T < 10){
        cout << 0 << T << endl;
    } else {
        cout << T << endl;
    }
}

int main() {
    int T = 1;
   // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
