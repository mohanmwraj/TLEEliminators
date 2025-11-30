//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc241/tasks/abc241_b
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

    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    for(int i = 0; i < m; ++i){
        int temp; cin >> temp;
        bool flag = true;
        for(int i = 0; i < n; ++i){
            if(arr[i] == temp){
                arr[i] = 0;
                break;
            } else if(i == n - 1){
                flag = false;
            }
        }

        if(!flag){
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
