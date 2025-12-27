//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1676/B
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

/*
    Given an array of 𝑛
 numbers, sorted in non-decreasing order, and 𝑘
 queries. For each query, print the maximum index of an array element not greater than the given one.

*/


void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    for(int i = 1; i < n; ++i){
        // if(arr[i] != arr[0]){
        //     ans += (arr[i] - arr[0]);// << endl;
        //    // return;
        // }
        ans += (arr[i] - arr[0]);
    }
    cout << ans << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
