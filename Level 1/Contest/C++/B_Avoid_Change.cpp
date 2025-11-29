//**********************************************************************************
// pbm : https://codeforces.com/gym/601714/problem/B
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
    int k, r; cin >> k >> r;
    
    if(k%10 == 0 || (k-r)%10==0){
        cout << "1" << endl;
        return;
    }

    int ans = 1, temp = k;
    for(int i = 1; i < 1000; ++i){
        if(k%10==0||(k-r)%10== 0){
            break;
        } else {
            k = temp * ans; //cout << "K:" << k << endl;
            ans++;
        }
    }

    cout << ans - 1 << endl;

}

int main() {
    int T = 1;
   // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
