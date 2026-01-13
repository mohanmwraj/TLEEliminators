//**********************************************************************************
// pbm : https://www.cses.fi/problemset/task/1640
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

/*

    Brute Force:

        outer loop (i... n)
            inner loop (j... n)
                if a[i] + a[j] == x
                    print i+1, j+1
                    return
        TLE - O(n^2) ~ 10^5.

    Optimal Approach: Using Hashing

*/

void solve(){
    int n, x; cin >> n >> x;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    map<int, int> mp; // value, index
    int flag = 0;
    int i1 = -1, i2 = -1;
    for(int i = 0; i < n; i++){
        if(mp.find(x - a[i]) != mp.end()){
            i1 = i + 1;
            i2 = mp[x - a[i]] + 1;
            flag = 1;
            break;
        }
        mp[a[i]] = i;
    }

    if(flag == 1){
        cout << i1 << " " << i2 << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
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
