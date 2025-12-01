//**********************************************************************************
// pbm : https://atcoder.jp/contests/arc157/tasks/arc157_a
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
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    bool ans = false;
    if(abs( B - C) <= 1){
        if(A != 0 && D != 0){
            if(B > 0 || C > 0){
                ans = true;
            } 
        } else {
            ans = true;
        }
    }

    if(ans){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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
