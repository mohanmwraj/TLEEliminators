//**********************************************************************************
// pbm : 
/*
    Given an array of N elements, answer the following Q queries:
    * Query: L, R
    * Result = A[L] ^ A[L+1] ^ ... ^ A[R]
    where ^ represents the bitwise XOR operation.

    Q ~ 1e5
    N ~ 1e5
*/
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

    a ^ a = 0

    a1 a2 a3 a4 a5 ... an

    (a1 ^ a2 ^ a3  ^ a4 ^ a5 ^ a6) ^ (a1 ^ a2)
           pre[r]                   pre[l-1]
    
    = a3 ^ a4 ^ a5 ^ a6 == pre[r] ^ pre[l-1]

    Time Complexity : O(N + Q)
    Space Complexity : O(N)

*/


void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> pre(n);
    pre[0] = arr[0];
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] ^ arr[i];
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        l--, r--;
        if(l == 0){
            cout << pre[r] << endl;
        } else {
            cout << (pre[r] ^ pre[l-1]) << endl;    
        }
    }
     
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
