//**********************************************************************************
// pbm : https://codeforces.com/gym/601714/problem/A
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
    int a, b; cin >> a >> b;
    int priyanshWins = 0, priyamWins = 0, draw = 0;

    for(int i = 1; i <= 6; ++i){
        if(abs(a - i) > abs(b - i)){
            priyamWins++;
        } else if(abs(a - i) < abs(b - i)){
            priyanshWins++;
        } else {
            draw++;
        }
    }

    cout << priyanshWins << " " << draw << " " << priyamWins << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
