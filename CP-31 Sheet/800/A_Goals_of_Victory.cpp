//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1877/A
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

    a = {a1, a2, a3, ... an-1}

    t1 t2 t3 t4 teams
    
    each team plays with each other team once.
    t1 plays with t2, t3, t4
    t1 score = s1, s2, s3
    opponent score = s1', s2', s3'

    a1 = (s1 + s2 + s3) - (s1' + s2' + s3') => efficiency of team 1.

    given is n -1 efficiency of teams, we need to find the efficiency of the nth team.

    Argument: The answer is simply the negative of the sum of the given efficiencies. This is because the sum of all efficiencies must be
    zero, as each match contributes equally to the efficiency of both teams involved. 
    Therefore, if we sum up the efficiencies of the first n-1 teams and negate it, we will get the efficiency of the nth team.


    if a X team scores against Y team,
    then X's efficiency++
    and Y's efficiency--.

    based on the above, we can conclude that the sum of all efficiencies must be zero, because every point scored by one team is a point lost by another team.
    Sum is a constant. sum = 0. sum is 0 because every point scored by one team is a point lost by another team.
    a4 = - (a1 + a2 + a3) => a4 = - sum of efficiencies of first n-1 teams.

*/

void solve(){
    int n; cin >> n;
    vector<int> a(n - 1);
    for(int i = 0; i < n - 1; i++)
        cin >> a[i];
    
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += a[i];
    }
    cout << -1 * sum << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
