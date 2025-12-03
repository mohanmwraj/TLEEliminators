//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1954/B
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
#include <map>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

void solve(){
    int n; cin >> n;

    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];

    // int count = 0;
    // for(int i = 0; i < n - 1; ++i){
    //     if(arr[i - 1] == arr[i + 1]){
    //         ++count;
    //     }
    // }

    // if(count == 0){
    //     if(arr[0] != arr[1] && arr[n - 1] != arr[n - 2]){
    //         cout << -1 << endl;
    //         return;
    //     }
    // }

    // cout << count << endl;

    map<int, int> map;
    for(auto it: arr){
        map[it]++;
    }

    if(map.size() == 1){
        cout << -1 << endl;
        return;
    }

    int ans = n, j = 0;
    for(int i = 0; i < n; ++i){
        if(arr[0] == arr[i]){
            j += 1;
        } else {
            ans = min(ans, j);
            j = 0;
        }
    }

    cout << min(ans, j) << endl;

}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
