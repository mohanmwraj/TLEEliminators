#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

void solve(){
    string fnfp, fnsp;
    string snfp, snsp;

    cin >> fnfp >> snfp;
    cin >> fnsp >> snsp;

    if( snfp == snsp){ 
        cout << "ARE Brothers" << endl;
    }else {
        cout << "NOT" << endl;
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
