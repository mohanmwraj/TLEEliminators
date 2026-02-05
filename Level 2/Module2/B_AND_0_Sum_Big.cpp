//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1514/B
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

    Since there are n numbers, each bit in k has n opportunities to be turned off.

    All elements are integers between o to 2^k-1. Means each number can be represented in k bits. (Maximum of K bits)
    
    To satisfy the condition bitwise AND of all elements = 0, 
    each bit position in k must have at least one element with that bit position = 0.

    consider n = 4, k = 7, maximum number can be 2^7 - 1 = 127 (1111111 in binary)

    1 1 1 1 1 1 1
    1 1 1 1 1 1 1
    1 1 1 1 1 1 1
    1 1 1 1 1 1 1

    ------------------
    Choose any one bit position and turn it off in any one of the n elements.

    for every bit position we have n choices to turn it off in any one of the n elements.
    therefore total ways = n^k

*/

ll helper(ll n, ll k, ll mod){
    if(k == 0) return 1;
    ll ans = helper(n, k - 1, mod);
    ans %= mod;
    ans *= n;
    ans %= mod;

    return ans;
}


void solve(){
    int n, k;
    cin >> n >> k;
    ll mod = 1e9 + 7;
    ll ans = 1; //= helper(n, k, mod);
    for(int i = 0; i < k; i++){
        ans = (ans * n) % mod;
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
