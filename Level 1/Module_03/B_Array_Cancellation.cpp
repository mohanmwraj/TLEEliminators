//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1405/B
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

    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];

    ll pos = 0;
    ll neg = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] >= 0){
            pos += arr[i];
        } else {
            // pos = 4, arr[i] = 3
            if(pos >= abs(arr[i])){
                pos -= abs(arr[i]);
            } else { // pos = 4, arr[i] = 5
                neg += (abs(arr[i]) - pos);
                pos = 0;
            }
        }
    }

    cout << neg << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
