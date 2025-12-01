//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1614/B
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
    vector<pair<int, int>> v;

    for(int i = 0; i < n; ++i){
        int a; cin >> a;
        v.push_back({a, i});
    }

    vector<int> ans(n);
    sort(v.begin(), v.end());

    ll curr = 1, temp = 0;
    for(int i = n - 1; i >= 0; --i){
        ans[v[i].second] = curr;
        temp += (2*(v[i].first*abs(curr)));

        if(curr > 0){
            curr *= -1;
        } else {
            curr *= -1;
            curr++;
        }
    }

    cout << temp << endl;
    cout << 0 << " ";
    for(auto it: ans) cout << it << " ";
    cout << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
