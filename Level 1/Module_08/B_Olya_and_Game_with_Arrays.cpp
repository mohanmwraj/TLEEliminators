//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1859/B
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
    there are n arrays.
    1 -> a1, a2, a3, ..., an
    2 -> b1, b2, b3, ..., bn

    n -> z1, z2, z3, ..., zn

    The beauty of the list of the arrays is defined as the sum of the maximum elements of each array.
    in other words, we find the minimum value in it and then sum up these values. 

    Note that integers can be moved from one array only once, but integers can be added to one array multiple times. and all
    the movements are done at the same time.

    - means atmost only one element can be picked from one array and added to another array.
    - elements can be added to one array multiple times.

    in every array, minimum element is first element after sorting. (a1, b1, c1, ..., z1)
    to maximize the beauty, we need to maximize the sum of minimum elements of each array.
    we can do this by moving the smallest elements from other arrays to the array which has the largest minimum element.
    this way, the minimum element of that array will remain the same and 
    all other arrays will have their minimum elements increased.
    finally, we sum up all the minimum elements of each array to get the maximum beauty.

    v = a2 + b2 + c2 + ... + (min of all elements in trash vectors)

    last array, we can't be sure right to trash. 
    Greedy approach: we need to find which array can be a trash.
    we can try all arrays as trash and calculate the beauty for each case.
    finally, we take the maximum beauty among all cases.

    The array which has the initial second lowest minimum element should be the trash array.
    because moving elements to that array will not increase the minimum element of that array.
    and all other arrays will have their minimum elements increased.
    thus, maximizing the sum of minimum elements of each array.




*/

void solve(){
    ll n; cin >> n;
    vector<pair<ll, ll>> first_2_mins;// {min, second min}

    for(int i = 0; i < n; ++i){
        ll m; cin >> m;
        vector<ll> arr(m);
        for(int j = 0; j < m; ++j){
            cin >> arr[j];
        }
        sort(arr.begin(), arr.end());
        first_2_mins.push_back({arr[1], arr[0]});
    }

    sort(first_2_mins.begin(), first_2_mins.end());
    ll answer = 0;

    ll first_2_min = first_2_mins[0].second; 
    for(int i = 1; i < n; ++i){
        answer += first_2_mins[i].first;
        first_2_min = min(first_2_min, first_2_mins[i].second);
    }

    answer += first_2_min;
    cout << answer << endl;

}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
