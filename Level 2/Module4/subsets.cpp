//**********************************************************************************
// pbm : https://leetcode.com/problems/subsets/description/
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
    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

/*
    Approach 1 : Bit Manipulation
    - There are 2^n subsets for a set of size n.
    - We can represent each subset as a binary number from 0 to 2^n - 1, where the j-th bit indicates 
    whether the j-th element is included in the subset.

    Approach 2 : Backtracking
    - We can use backtracking to generate all subsets by exploring two possibilities for each element: 
    including it in the current subset or excluding it.
*/

//Approach 1 : Bit Manipulation
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> result;
    int total_subsets = 1 << n; // 2^n subsets
    for (int i = 0; i < total_subsets; i++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { // Check if the j-th bit is set
                subset.push_back(nums[j]);
            }
        }
        result.push_back(subset);
    }
    return result;
}

//Approach 2 : Backtracking
void backtrack(vector<int>& nums, vector<int>& current, int index, vector<vector<int>>& result) {
    result.push_back(current); // Add the current subset to the result
    for (int i = index; i < nums.size(); i++) {
        current.push_back(nums[i]); // Include the current element
        backtrack(nums, current, i + 1, result); // Recur with the next index
        current.pop_back(); // Backtrack: remove the last element
    }
}   


void solve(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i]; 
    }

    vector<vector<int>> result;
    vector<int> current;
    backtrack(nums, current, 0, result);
    for (const auto& subset : result) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
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
