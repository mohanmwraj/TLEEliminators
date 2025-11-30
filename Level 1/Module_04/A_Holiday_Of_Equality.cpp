//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/758/A
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

    int maxEle = *max_element(arr, arr + n);
    int ans = 0;

    for(int i = 0; i < n; ++i){
        if(arr[i] != maxEle){
            ans = ans + (maxEle - arr[i]);
        }
    }

    cout << ans << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
