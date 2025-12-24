//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/660/A
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
    if we insert 1 between two non-coprime, then it become coprime.
*/

ll gcd(ll num1, ll num2){
    if(num1 == 0){
        return num2;
    } 
    return gcd(num2 % num1, num1);
}

void solve(){
    ll n; cin >> n;
    ll arr[n], pos[n], cnt = 0;
    for(ll i = 0; i < n; ++i){
        cin >> arr[i];
        pos[i] = 0;
    }


    for(ll i = 0; i < n - 1; ++i){
        if(gcd(arr[i], arr[i + 1]) != 1){
            pos[i] = 1;
            cnt++;
        }
    }

    cout << cnt << endl;
    for(ll i = 0; i < n; ++i){
        cout << arr[i] << " ";
        if(pos[i]){
            cout << 1 << " ";
        }
    }
    cout << endl;

}

int main() {
    int T = 1;
   // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
