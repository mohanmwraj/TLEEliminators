//**********************************************************************************
// pbm : https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/C
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

    int odd = 0, even = 0, pos = 0, neg = 0;
    for(int i = 0; i < n; ++i){
        int val; cin >> val;
        
        if(val % 2 == 0) even++;
        else odd++;
        
        if(val < 0) neg++;
        else if(val > 0) pos++;
    }

    cout<< "Even: " << even << endl;
    cout<< "Odd: " << odd << endl;
    cout<< "Positive: "<< pos << endl;
    cout<< "Negative: "<< neg << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
