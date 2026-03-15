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
    Given an array of N elements, answer the following queries:

    * Query : Given a range [l, r]
    * Result = A[L] + 2 * A[L+1] + 3 * A[L+2] + ... + (r-l+1) * A[r]

*/

/*
    A = [2, 4, 3, 6, 9]
    
    Summation of A[L] + 2 * A[L+1] + 3 * A[L+2] + ... + (r-l+1) * A[r]
    = A[L] + A[L+1] + A[L+2] + ... + A[r] + A[L+1] + A[L+2] + ... + A

    Summation of i (L to R) A[i] * (i - L + 1 )
   = Summation of i (L to R) (i * A[i]) - Summation of i (L to R) (L-1) * (A[i])

    Mathematical Representation:

    For a given array A[1..N], and a query range [L, R]:

    Result = A[L] * 1 + A[L+1] * 2 + ... + A[R] * (R-L+1)
           = Σ_{i=L}^{R} A[i] * (i - L + 1)

    This can be rewritten as:
           = Σ_{i=L}^{R} (i * A[i]) - (L-1) * Σ_{i=L}^{R} A[i]

    Where:
        Σ_{i=L}^{R} (i * A[i]) is the sum of i * A[i] for i in [L, R]
        Σ_{i=L}^{R} A[i] is the sum of A[i] for i in [L, R]
*/


void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &it:arr) cin >> it;

    vector<ll> pre1(n+1, 0), pre2(n+1, 0);
    for(int i = 1; i <= n; i++){
        pre1[i] = pre1[i-1] + arr[i-1];
        pre2[i] = pre2[i-1] + (ll)arr[i-1] * i;
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        ll ans = pre2[r] - pre2[l-1] - (l-1) * (pre1[r] - pre1[l-1]);
        cout << ans << endl;
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
