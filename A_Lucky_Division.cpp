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

void solve(){
    int n; cin >> n;

    // if(n % 4 != 0 || n % 7 != 0){
    //     cout << "NO" << endl;
    //     return;
    // }

    bool flag = true;
    int temp = n;
    while(temp != 0){
        temp = n % 10;
        if(temp != 4 && temp != 7){
            flag = false;
        }
        temp /= 10;
    }

    if(flag){
        cout << "YES" << endl;
    } else {
        if(n % 4 != 0 || n % 7 != 0){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
        
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
