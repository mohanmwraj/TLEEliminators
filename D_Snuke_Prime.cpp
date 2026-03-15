//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc188/tasks/abc188_d
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
#include <set>
#include <map>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

/*
A payment plan called Snuke Prime is available.
In this plan, by paying C yen (the currency of Japan) per day, you can use all services offered by the company without additional fees.
You can start your subscription to this plan at the beginning of any day and cancel your subscription at the end of any day.

Takahashi is going to use N of the services offered by the company.
He will use the i-th of those services from the beginning of the a_i-th day until the end of the b_i-th day, where today is the first day.
Without a subscription to Snuke Prime, he has to pay c_i yen per day to use the i-th service.

Find the minimum total amount of money Takahashi has to pay to use the services.
*/

const int N = 1e6 + 1;
ll diff[N];

// we can construct an array of size up to 1e7. we can't construct an array of size 1e9. 
// we can use difference array to solve this problem in O(n + N) time, where N is the maximum day we need to consider.
void solve(){
    ll n, c; cin >> n >> c;
    
    vector<ll> start(n), end(n), cost(n);
    for(ll i = 0; i < n; i++){
        cin >> start[i] >> end[i] >> cost[i];
        diff[start[i]] += cost[i];
        diff[end[i] + 1] -= cost[i];
    }

    for(ll i = 1; i < N; i++){
        diff[i] += diff[i-1];
    }

    ll ans = 0;
    for(ll i = 0; i < N; i++){
        ans += min(diff[i], c);
    }
    cout << ans << endl;
}

// When A, B <= 1e9, we can't construct an array of size 1e9. 
// We can use a map to store the difference array, but it will be slower than using an array. 
// We can use a vector of pairs to store the difference array, and sort
// it by the day, and then iterate through it to calculate the prefix sum and the answer.
void solve2(){
    ll n, c; cin >> n >> c;
    // vector<pair<ll, ll>> diff;
    // for(ll i = 0; i < n; i++){
    //     ll a, b, cost; cin >> a >> b >> cost;
    //     diff.push_back({a, cost});
    //     diff.push_back({b + 1, -cost});
    // }
    // sort(diff.begin(), diff.end());
    // ll ans = 0, sum = 0, prev = 0;
    // for(auto it: diff){
    //     ans += min(sum, c) * (it.ff - prev);
    //     sum += it.ss;
    //     prev = it.ff;       
    // }
    // cout << ans << endl;

    vector<ll> start(n), end(n), cost(n);
    for(ll i = 0; i < n; i++){
        cin >> start[i] >> end[i] >> cost[i];
    }

    // Mark Important Points
    set<int> st;
    for(ll i = 0; i < n; i++){
        st.insert(start[i]);
        st.insert(end[i] + 1);
    }

    //Compress the important points
    int idx = 0;
    map<int, int> mp;
    for(auto it: st){
        mp[it] = idx++; 
    }

    //Difference Array
    vector<ll> diff(idx + 1, 0);
    for(ll i = 0; i < n; i++){
        diff[mp[start[i]]] += cost[i];
        diff[mp[end[i] + 1]] -= cost[i];
    }

    for(ll i = 1; i < idx; i++){
        diff[i] += diff[i-1];
    }

    ll ans = 0, sum = 0, prev = 0;
    vector<int> st_vec(st.begin(), st.end());

    for(int i = 1; i < st_vec.size(); i++){
        // ans += min(sum, c) * (st_vec[i] - prev);
        // sum += diff[i];
        // prev = st_vec[i];
        ll span = st_vec[i] - st_vec[i-1];
        ans += min(sum, c) * span;
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
