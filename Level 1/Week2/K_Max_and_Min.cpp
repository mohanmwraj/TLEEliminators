//**********************************************************************************
// pbm : https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/K
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
    cin >> a >> b >> c;

    int mini = a;

    if(mini > b)
        mini = b;

    if(mini > c) mini = c;

    int maxi = a;
    if(maxi < b) maxi = b;
    if(maxi < c) maxi = c;

    cout << mini << " " << maxi << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
