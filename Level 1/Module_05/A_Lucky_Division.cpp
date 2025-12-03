//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/122/A
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

bool isLucky(int n){
    while(n > 0){
        if(n % 10 != 4 && n % 10 != 7){
            return false;
        }
        n /= 10;
    }

    return true;
}

void solve(){
    int n; cin >> n;

    // bool flag = true;
    // int temp = n;
    // while(temp != 0){
    //     int lastDigit = temp % 10;
    //     if(lastDigit != 4 && lastDigit != 7){
    //         flag = false;
    //     }
    //     temp /= 10;
    // }

    // if(flag || (n % 4 == 0 || n % 7 == 0)){
    //     cout << "YES" << endl;
    // } else {
    //     cout << "NO" << endl;
    // }

    bool ans = false;
    for(int i = 1; i <= n; ++i){
        if(n % i == 0 && isLucky(i)){
            ans = true;
        }
    }

    if(ans){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
