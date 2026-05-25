//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1901/A
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

    Insert 0 and x into points;
    let g = max gap between two consecutive stations;
    let tail = 2. (x - last station);
    ans = max(g, tail);

    Missed:
    We need to consider the case where the last station is close to x, and 
    we need to return the maximum of g and 2 * (x - last station) to
    ensure that we have enough fuel to reach the destination.

    1 Sec = 10^ 8 operations.
    2 Sec = 2 * 10^8 operations.

    test cases = 1000

    time/t = 2 * 10^8 / 1000 = 2 * 10^5 operations per test case. 

    we can go upto 2 * 10^5 operations per test case. to get a TLE.

    Time Complexity: O(n).
    Space Complexity: O(n).

*/

void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    a.push_back(0);
    for(int i = 0; i < n; i++){
        ll point;
        cin >> point;
        a.push_back(point);
    }
    a.push_back(x);

    n = a.size();
    //int tank_capacity = 0;
    ll max_distance_between_points = INT_MIN;
    for(int i = 1; i < n; ++i){
        // int diff = (i == n + 1 ? x : a[i]) - (i == 0 ? 0 : a[i - 1]);

        // tank_capacity = max(tank_capacity, diff);

        if(i == n - 1){
            max_distance_between_points = max(max_distance_between_points, 2LL * (a[i] - a[i - 1]));
        } else {
            max_distance_between_points = max(max_distance_between_points, (ll)(a[i] - a[i - 1]));
        }
    }
    cout << max_distance_between_points << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
