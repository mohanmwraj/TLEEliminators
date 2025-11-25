//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1426/B
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
    int n, m; cin >> n >> m;

    int arr[n][2][2];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k < 2; ++k){
                cin >> arr[i][j][k];
            }
        }
    }

    // for(int i = 0; i < n; ++i){
    //     for(int j = 0; j < 2; ++j){
    //         for(int k = 0; k < 2; ++k){
    //             cout << arr[i][j][k];
    //         }
    //     }
    //     cout << endl;
    // }
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
