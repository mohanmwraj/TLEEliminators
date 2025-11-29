#include<bits/stdc++.h>
#include<iostream>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

// https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/J

void solve(){
    int a, b;
    cin >> a >> b;

    // if(a < b) {
    //     int temp = a;
    //     a = b;
    //     b = temp;
    // }

    if((a % b == 0) || (b % a == 0)) {
        cout << "Multiples" << endl;
    } else cout << "No Multiples" << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
