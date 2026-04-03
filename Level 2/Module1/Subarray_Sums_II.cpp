//**********************************************************************************
// pbm : https://www.cses.fi/problemset/task/1661/
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
#include <map>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

/*
    Given an array of n integers, your task is to count the number of subarrays having sum x.
*/

/*
    Approach:
        Use a map to store frequency of prefix sums.
        When prefix_sum[i] - x exists in map, it means a subarray with sum x ends at i.

    Time Complexity: O(n)
    Space Complexity: O(n)

    Mathematical Definition:
        Given array a[0..n-1], find count of subarrays where:
        ∑(a[j]) = x, where i ≤ j ≤ k for all valid (i,k) pairs
        
    Key Insight:
        Let PSum[i] = ∑(a[0..i])
        
        For subarray [i+1..j]: ∑(a[i+1..j]) = PSum[j] - PSum[i]
        
        We need: PSum[j] - PSum[i] = x
        Therefore: PSum[i] = PSum[j] - x
        
    Algorithm:
        For each position j with prefix sum PSum[j]:
        Count how many times (PSum[j] - x) appeared before → those give subarrays with sum x
*/

void solve(){
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    for(auto &it:a) cin >> it;

    map<ll, ll> freq;
    freq[0] = 1;
    ll sum = 0, ans = 0;
    for(ll i = 0; i < n; i++){
        sum += a[i];
        if(freq.find(sum - x) != freq.end()){
            ans += freq[sum - x];
        }
        freq[sum]++;
    }
    cout << ans << endl;
}

int main() {
    int T = 1;
   // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
