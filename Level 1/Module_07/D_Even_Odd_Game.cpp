//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1472/D
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
    7 8, Alice choose 8 SA = 8, Bob choose 7 SB = 7. Alice wins.

    Observations:
    #1 Take max odd bob and Max even alice.
    #2 give the max odd to alice and max even to bob. It may not increase their sum 
    but may decrease the other player's sum.

    Claim - Taking the max value irrespective of parity is always optimal.

    Player try to max his/her sum and minimize the other player's sum.
*/


void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];

    ll aliceSum = 0, bobSum = 0;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    string turn = "A";

    for(int i = 0; i < n; i++){
        if(turn == "A"){
            if(a[i] % 2 == 0){
                aliceSum += a[i];
            }
            turn = "B";
        } else {
            if(a[i] % 2 != 0){
                bobSum += a[i];
            }
            turn = "A";
        }
    }

    if(aliceSum > bobSum) {
        cout << "Alice" << endl;
    } else if(bobSum > aliceSum) {
        cout << "Bob" << endl;
    } else {
        cout << "Tie" << endl;
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
