//**********************************************************************************
// pbm : https://atcoder.jp/contests/arc087/tasks/arc087_a
//**********************************************************************************
#include "bits/stdc++.h"

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

void solve(){
    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];    
    }

    map<int, int> freq;
    for(int i = 0; i < n; i++){
        freq[a[i]]++;
    }
}

int main() {
    int T = 1;
   // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
