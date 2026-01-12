//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/637/B
//**********************************************************************************
#include"bits/stdc++.h"

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

/*

> Iterate from last, skip any message if it's the same person again.

*/

void solve(){
    int n; cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    set<string> st;
    for(int i = n - 1; i >= 0; i--){
        if(st.find(v[i]) == st.end()){
            cout << v[i] << endl;
            st.insert(v[i]);
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
