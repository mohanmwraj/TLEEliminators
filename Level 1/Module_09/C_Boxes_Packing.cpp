//**********************************************************************************
// pbm : https://codeforces.com/contest/903/problem/c
//**********************************************************************************
#include "bits/stdc++.h"

#include<iostream>
#include <set>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

/*

    claim: the minimum number of visible boxes
    frequency of the size of the box
    which appears the most.

    a1 a2 a3 a3 a3 a3 a4 a5

    a1 < a2 < a3 < a4 < a5

    boxes which are smaller than a3 can be placed inside a3 => a1, a2 <= a3
    simalarly for larger boxes

*/

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    multiset<int> st; // multiset will store the weights of boxes with possible duplicates in sorted order.
    for(int i = 0; i < n; ++i){
        st.insert(a[i]);
    }

    int ans = 0;
    while(!st.empty()){
        ans++;

        int val = *st.begin();
        st.erase(st.begin()); // remove the smallest element

        while(st.upper_bound(val) != st.end()){
            int newVal = *st.upper_bound(val);
            st.erase(st.find(newVal));
            val = newVal;
        }
    }

    cout << ans << endl;
}

void solve_maxFreq_Claim(){
    int n; cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> count;
    for(int i = 0; i < n; i++){
        count[a[i]]++;
    }

    int ans = 0;
    for(auto &it : count){
        int freq = it.second;
        ans = max(ans, freq);
    }

    cout << ans << endl;
}

int main() {
    int T = 1;
  //  cin >> T;
    while(T--){
       // solve();
        solve_maxFreq_Claim();
    }
    return 0;
}
