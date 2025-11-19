//**********************************************************************************
// pbm : https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/V
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
    int a, b;
    char s;
    cin >> a >> s >> b;

    if(s == '>'){
        if(a > b) {
            cout << "Right" << endl;
        } else 
            cout << "Wrong" << endl;
    } else if(s == '<'){
        if(a < b) {
            cout << "Right" << endl;
        } else 
            cout << "Wrong" << endl;
    } else if(s == '='){
        if(a == b) {
            cout << "Right" << endl;
        } else 
            cout << "Wrong" << endl;
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
