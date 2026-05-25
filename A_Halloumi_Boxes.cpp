//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1903/A
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

    If K > 1, any permutaion of the boxes is possible, so the answer is always YES.

    Missed: 
    Check the condition, if array is already sorted, then the answer is YES, otherwise NO.

*/


void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);

    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<ll> copy_a = a;
    sort(copy_a.begin(), copy_a.end());

    if(copy_a == a || k > 1){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
