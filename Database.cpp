//**********************************************************************************
// pbm : https://www.spoj.com/problems/RPLD/
//**********************************************************************************
#include "bits/stdc++.h"

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second
int testCase = 0;

void solve(){
    ll n, r; cin >> n >> r;

    set<pair<ll, ll>> db;
    int flag = 1;

    for(int i = 0; i < r; ++i){
        ll id, subjectCode;
        cin >> id >> subjectCode;

        if(db.find({id, subjectCode}) != db.end()){
            flag = 0;
        } 
        db.insert({id, subjectCode});
    }

    cout << "Scenario #" << ++testCase << ": " << (flag == 1 ? "possible" : "impossible") << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
