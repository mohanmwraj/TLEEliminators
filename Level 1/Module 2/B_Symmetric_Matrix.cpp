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

    if(m % 2 != 0){
        cout << "NO" << endl;
        return;
    }

    for(int i = 0; i < n; ++i){
        if(arr[i][0][1] == arr[i][1][0]){
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
