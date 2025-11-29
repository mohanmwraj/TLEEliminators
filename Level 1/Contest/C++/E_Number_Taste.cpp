//**********************************************************************************
// pbm : https://codeforces.com/gym/601714/problem/E
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

    int i = 0;
    for(int i = 1; i < INT_MAX; ++i){
        if(i % 3 == 0 || i % 10 == 3){
            continue;
        }

        if(--n == 0){
            cout << i << endl;
            break;
        }
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
