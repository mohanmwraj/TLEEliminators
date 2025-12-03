//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1033/B
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
    a^2 - b^2 == prime ?

    (a + b) (a - b) = prime condition is numnber only divisible by 1 and itslef.
    so (a - b) == 1 and (a + b) should be prime.

*/

bool isPrime(ll n){

    if(n == 2) return true;
    if(n < 2 || !(n&1)) return false;

    for(ll d = 2; d * d <= n; ++d){
        if(n % d == 0){
            return false;
        }

       // cout << "N % d" << n % d << endl;
    }
    return true;
}

void solve(){
    ll a, b; cin >> a >> b;
    // cout << "A + B: " << a + b << endl;
    // cout << "A - B:" << a - b << endl;
    // cout << "is Prime:" << isPrime(a + b) << endl;
    if((a-b == 1) && (isPrime(a + b))){
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
