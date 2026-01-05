//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1411/B
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

bool isFair(ll n){
    ll num = n;
    while(num != 0){
        int x = num % 10;
        if(x != 0 && n % x != 0){
            return false;
        }
        num /= 10;
    }
    return true;
}

void solve(){
    ll n; cin >> n;
    while(!isFair(n)){
        n += 1;
    }
    cout << n << endl;

}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
