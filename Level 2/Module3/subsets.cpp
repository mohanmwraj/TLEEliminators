//**********************************************************************************
// pbm : 
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
    Given an array A of N elements, print all possible subsets of the array in any order.
    Example:

    arr = [1,2,3]
    Output:
    [
      [],
      [1],
      [2],
      [3],
      [1,2],
      [1,3],
      [2,3],
      [1,2,3]
    ]
*/


/*
    bit which is set, corresponding to that index, we will include that element in the subset.
    For example, consider the array [1, 2, 3]. The binary representation of the numbers from 0 to 7 (2^3 - 1) will be:
 index: 2 1 0
    0 -> 000 -> []
    1 -> 001 -> [3]
    2 -> 010 -> [2]
    3 -> 011 -> [2, 3]
    4 -> 100 -> [1]
    5 -> 101 -> [1, 3]
    6 -> 110 -> [1, 2]
    7 -> 111 -> [1, 2, 3]
    Here, each bit position corresponds to an index in the array:
    - Bit 0 -> 3
    - Bit 1 -> 2
    - Bit 2 -> 1
    Thus, by iterating through all numbers from 0 to 2^N - 1 and checking which bits are set, 
    we can generate all possible subsets of the array.

    Array of size n, every number from 0 to 2^n - 1 will be represent a unique subset.
    For every number, check every bit position. If the bit is set, include that element 
    in the current subset.
*/

void solve(){
    int n; cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // 1 << n is 2^n
    for(int mask = 0; mask < (1 << n); mask++){
        vector<int> subset;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                subset.push_back(arr[i]);
            }
        }

        // Print the current subset
        cout << "[";
        for(int i = 0; i < subset.size(); i++){
            cout << subset[i];
            if(i != subset.size() - 1){
                cout << ",";
            }
        }
        cout << "]" << endl;
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
