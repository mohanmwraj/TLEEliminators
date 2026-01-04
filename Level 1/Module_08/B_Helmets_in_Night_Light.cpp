//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1877/B
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
    N P
    v = v1, v2, v3, ..., vn
    a = a1, a2, a3, ..., an
    b = b1, b2, b3, ..., bn

    I want to share the announcement to as N residents at minimum cost.

    Villager Vi can share the announcement to ai residents at cost bi.

    Initially, 0 residents know the announcement.
    Pak Chanek should announce it to atleast one villager.
    After that, any villager who knows the announcement can share it to ai residents at cost bi.
    Find the minimum cost to share the announcement to at least P residents.

    - Find the cost of villager with lowest cost bi.
    - Choose a resident who has lowest cost bi.
    - cost = p, people = 1, at this time.
    - Always prefer the guy whose individula share cost is lowest bi.
    - Greedily choose the villager with lowest cost bi until we reach all residents.
*/
/*
    Approach:
    1. Create a min-heap (priority queue) to store villagers based on their cost bi.
    2. Initialize total cost to 0 and residents reached to 0.
    3. While residents reached < P:
        a. Extract the villager with the lowest cost bi from the min-heap.
        b. Add their cost bi to total cost.
        c. Increase residents reached by ai.
        d. If residents reached >= P, break.
    4. Output the total cost.
*/

void solve(){
    ll n, p; cin >> n >> p;
    vector<pair<ll, ll>> v(n); // {residents, cost}
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }

    for(int i = 0; i < n; ++i){
        v[i] = {b[i], a[i]};
    }   

    // sort(v.begin(), v.end(), [](pair<ll, ll> &x, pair<ll, ll> &y){
    //     return x.ss < y.ss; // sort by cost
    // });
    sort(v.begin(), v.end());

    ll minimum_cost = p;
    ll already_shared = 1;

    for(auto it: v){
        ll can_be_shared = it.second;
        ll sharing_cost = it.first;

        if(sharing_cost >= p){
            break;
        } 

        if(already_shared + can_be_shared > n){
            minimum_cost += (n - already_shared) * sharing_cost;
            already_shared = n;
            break;
        } else {
            minimum_cost += can_be_shared * sharing_cost;
            already_shared += can_be_shared;
        }

    }
    minimum_cost += (n - already_shared) * p;
    cout << minimum_cost << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
