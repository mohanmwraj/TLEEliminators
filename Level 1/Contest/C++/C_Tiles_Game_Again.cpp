//**********************************************************************************
// pbm : https://codeforces.com/gym/601714/problem/C
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
    int ans = 0;
    int count = 0;

    for(int i = 0; i < n; ++i){
        int s; cin >> s;
        if(s == 0){
            count++;
        } else {
            ans = max(ans, count);
            count = 0;
        }
    }

    cout << max(ans, count) << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
