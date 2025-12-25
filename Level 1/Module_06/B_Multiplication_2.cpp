//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc169/tasks/abc169_b
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

/*


// 1_000_000_000_000_000_001

    Int = -2*10^9 to 2*10^9
    ll = -9*10^18 to 9*10^18

*/

void solve(){
    int n; cin >> n;

    ll ub = (ll)1e18;
    ll arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];}

    for(int i = 0; i < n; ++i){
        if(arr[i] == 0){
            cout << 0 << endl;
            return;
        }
    }
    
    ll prod = 1;
    for(int i = 0; i < n; ++i){
        //prod = prod * arr[i];
        if(prod > ub / arr[i]){
            cout << -1 << endl;
            return;
        } else {
            prod = prod * arr[i];
        }
    }
    cout << prod << endl;
}
int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
