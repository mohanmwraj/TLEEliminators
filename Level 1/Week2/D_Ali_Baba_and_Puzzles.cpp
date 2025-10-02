//**********************************************************************************
// pbm : https://codeforces.com/group/MWSDmqGsZm/contest/326175/problem/D
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
    int a, b, c;
    ll d;
    cin >> a >> b >> c >> d;

    string output = "NO";

    if(a + b - c == d) output = "YES";
    if(a + b * c == d) output = "YES";
    if(a - b + c == d) output = "YES";
    if(a - b * c == d) output = "YES";
    if(a * b + c == d) output = "YES";
    if(a * b - c == d) output = "YES";

    cout << output << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
