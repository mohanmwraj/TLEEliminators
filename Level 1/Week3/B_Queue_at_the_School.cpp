//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/266/B
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
    int n, t; cin >> n >> t;
    string s; cin >> s;

    for(int i = 0; i < t; ++i){
        for(int j = 0; j < n - 1; ++j){
            if(s[j] == 'B' && s[j + 1] == 'G'){
                swap(s[j], s[j + 1]);
                j++;
            }
        }
    }

    cout << s << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
