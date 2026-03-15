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

/*
    Difference array can be used to perform multiple range update where we need to find the final state
    of the array only after performing all the queries.

    Difference array helps us achieve the above in O(1) time for each query 
    and O(n) time to find the final state of the array after performing all the queries.
*/

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &it:arr) cin >> it;

    int q; cin >> q;
    vector<int> diff(n+1, 0);
    while(q--){
        int l, r, x; cin >> l >> r >> x;
        diff[l] += x;
        if(r + 1 < n) diff[r + 1] -= x;
    }

    for(int i = 1; i < n; i++){
        diff[i] += diff[i-1];
    }

    for(int i = 0; i < n; i++){
        arr[i] += diff[i];
    }
    for(auto it:arr) cout << it << " ";
    cout << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
