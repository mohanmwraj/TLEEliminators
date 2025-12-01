//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1509/B
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
    TMT - 

    if we divide no of T before M as A, and after as C,
    No of M is B. 

    if A == B == C, then we can form the sequence, by taking 1 from A, 1 from B, 1 from C.
*/

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<int> T, M;
    for(int i = 0; i < n; ++i){
        if(s[i] == 'T'){
            T.push_back(i);
        } else {
            M.push_back(i);
        }
    }

    bool ans = true;
    if(T.size() != M.size() * 2){
        ans = false;
    } else {
        int x = M.size();
        for(int i = 0; i < x; ++i){
            if(! (T[i] < M[i] && M[i] < T[i + x])){
                ans = false;
            }
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
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
