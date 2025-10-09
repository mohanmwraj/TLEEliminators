//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc263/tasks/abc263_a
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
    int arr[14];
    for(int i = 0; i < 14; ++i) arr[i] = 0;

    for(int i = 0; i < 5; ++i){
        int n; cin >> n;
        arr[n]++;
    }

    bool cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < 14; ++i){
        if(arr[i] == 2){
            cnt1 = 1;
        }

        if(arr[i] == 3){
            cnt2 = 1;
        }
    }

    if(cnt1 & cnt2) {
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
