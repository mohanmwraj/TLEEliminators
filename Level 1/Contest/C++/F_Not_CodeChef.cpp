//**********************************************************************************
// pbm : https://codeforces.com/gym/601714/problem/F
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
    bool flag = 0;
    for(int i = 0; i < n; ++i){
        int judge; cin >> judge;
        if(judge == 1){
            flag = 1;
        }
    }

    if(flag){
        cout << "HARD" << endl;
    } else {
        cout << "EASY" << endl;
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
