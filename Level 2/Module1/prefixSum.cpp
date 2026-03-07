//**********************************************************************************
// pbm : 
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

// Query : Given an array of integers and a range [l, r], find the sum of the elements in that range.
// Brute Force : O(n) for each query, O(n*q) for q queries
void solve(int n){
    vector<int> arr(n);

    // for(int i = 0; i < n; i++){
    //     cin >> arr[i];
    // }
    for(auto &it:arr) cin >> it;
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        int sum = 0;
        for(int i = l; i <= r; i++){
            sum += arr[i];
        }
        cout << sum << endl;
    }
}

// Prefix Sum : O(n) for preprocessing, O(1) for each query, O(n + q) for q queries
void prefixSum(int n){
    vector<int> arr(n);
    for(auto &it:arr) cin >> it;

    // Create prefix sum array
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        int sum = prefix[r] - (l > 0 ? prefix[l-1] : 0);
        cout << sum << endl;
    }
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){ 
        // solve(5);
        prefixSum(5);
    }
    return 0;
}
