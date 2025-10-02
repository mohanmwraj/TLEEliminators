//**********************************************************************************
// pbm : https://codeforces.com/group/MWSDmqGsZm/contest/326175/problem/B
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
    ll a, b, k;
    cin >> a >> b >> k;

    bool memo = (a % k == 0); 
    bool momo = (b % k == 0);

    if(memo && momo){
        cout << "Both" << endl
    } else if (memo && !momo){
        cout << "Memo" << endl;       
    } else if(!memo && momo){
        cout << "Momo" << endl;
    } else {
        cout << "No One" << endl;
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
