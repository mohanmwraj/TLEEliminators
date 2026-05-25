//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1903/A
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

    If K > 1, any permutaion of the boxes is possible, so the answer is always YES.

    Missed: 
    Check the condition, if array is already sorted, then the answer is YES, otherwise NO.


    1 Sec = 10^8 operations, so we can sort the array in O(n log n) and compare it with the original array in O(n), 
    which is efficient for the given constraints.

    100 Test cases given, and each test case can have up to 10^6 elements, 
    so the overall complexity of O(T * n log n) is acceptable.

    N = 100 K = 100 MAX (1 <= N <= 10^6) (1 <= K <= 100) A[i] <= 10^9

    O(N^3) = 10^6
    O(N^2) = 10^4

    O(N) O(N log N) = 10^6 log 10^6 = 10^6 * 20 = 2 * 10^7 (Acceptable)

    Time Complexity: O(n log n) = O(100log2 100) = O(100 * 7) = O(700)
    Space Complexity: O(n) for the copy of the array.
*/


void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);

    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<ll> copy_a = a;
    sort(copy_a.begin(), copy_a.end());

    if(copy_a == a || k > 1){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
