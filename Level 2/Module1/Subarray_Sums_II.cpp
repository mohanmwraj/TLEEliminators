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
