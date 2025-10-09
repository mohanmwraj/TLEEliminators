//**********************************************************************************
// pbm : https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/Z
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
    int k, s;
    cin >> k >> s;

    int count = 0;
    for(int x = 0; x <= k; ++x){
        for(int y = 0; y <= k; ++y){
            int z = s - x - y;
            if(z >= 0 && z <= k){
                count++;
            }
        }
    }

    cout << count << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
