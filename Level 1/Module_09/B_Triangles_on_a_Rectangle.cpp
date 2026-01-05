//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1620/B
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
    Area of triangle = (1/2) * base * height
    2A = base * height

    To get maximum are, we need to find max of base or max of height.

    2A = b * h
    base (high) or height (high)

    To achieve highest base, we need to choose the two farthest vertical lines.
    In opposite side, if you take any point, the height will be same (h).

    (b1 * h, b2 * h, b3 * w1, b4 * w2 )
    max(b1, b2) * h or max(w1, w2)

*/

void solve(){
    ll w, h; cin >> w >> h;
    ll area = INT_MIN;

    for(int i = 0; i < 4; ++i){
        ll k; cin >> k;
        ll first, last;
        for(int j = 0; j < k; ++j){
            ll x; cin >> x;
            if(j == 0) first = x;
            if(j == k - 1) last = x;
        }
        area = max(area, (last - first) * (i <= 1 ? h : w));

    }
    cout << area << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
