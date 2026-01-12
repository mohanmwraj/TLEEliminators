//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc164/tasks/abc164_c
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

    set<string> st;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        st.insert(s);
    }

    cout << st.size() << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
