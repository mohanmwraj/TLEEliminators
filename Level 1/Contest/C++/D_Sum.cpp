//**********************************************************************************
// pbm : https://codeforces.com/gym/601714/problem/D
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
    string s; cin >> s;
    int a = s[0] - '0';
    int b = s[2] - '0';

    cout << a + b << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
