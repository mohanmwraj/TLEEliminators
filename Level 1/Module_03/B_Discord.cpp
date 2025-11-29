//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc303/tasks/abc303_b
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
   int n, m; cin >> n >> m;

   int arr[m][n];
   for(int i = 0; i < m; ++i){
    for(int j = 0; j < n; ++j){
        cin >> arr[i][j];
        arr[i][j]--;
     }
   }

   int count = 0;
   for(int i = 0; i < n; ++i){
        int v[n];
        memset(v, 0, sizeof(v));
        v[i] = 1;

        for(int j = 0; j < m; ++j){
            for(int k = 0; k < n; ++k){
                if(arr[j][k] == i){
                    if(k > 0 && k < n-1){
                        v[arr[j][k - 1]] = 1;
                        v[arr[j][k + 1]] = 1;
                    } else if(k < n - 1){
                        v[arr[j][k + 1]] = 1;
                    } else if (k > 0){
                        v[arr[j][k - 1]] = 1;
                    }
                }
            }
        }

        for(int l = 0; l < n; ++l){
            if(v[l] == 0) count++;
        }
   }

   cout << count / 2 << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
