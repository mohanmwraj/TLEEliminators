//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc120/tasks/abc120_b
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
    
    To find the k-th largest common divisor of two numbers a and b, we can follow these steps:
    1. Find all common divisors of a and b by iterating from 1 to min(a, b) and checking if both a and b are divisible by the iterator.
    2. Store these common divisors in a list or vector.
    3. Sort the list of common divisors in ascending order.
    4. The k-th largest common divisor will be the element at the index (size - k) in the sorted list.
*/

void solve(){
    ll a, b, k; cin >> a >> b >> k;

    vector<ll> factors;
    for(ll i = 1; i <= min(a, b); ++i){
        if(a % i == 0 && b % i == 0){
            factors.push_back(i);
        }
    }

    sort(factors.begin(), factors.end());
    cout << factors[factors.size() - k] << endl;
}

int main() {
    int T = 1;
   // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
