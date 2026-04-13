//**********************************************************************************
// pbm : https://leetcode.com/problems/subsets-ii/description/
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
    Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
    The solution set must not contain duplicate subsets. The subsets can be returned in any order.
    Input: nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/

/*
    Approach : Backtracking
    - Sort the input array to handle duplicates easily.
    - Use backtracking to generate subsets, but skip over duplicate elements to avoid generating 
    the same subset multiple times.


*/

void backtrack(vector<int>& nums, vector<int>& current, int index, vector<vector<int>>& result) {
    result.push_back(current); // Add the current subset to the result
    for (int i = index; i < nums.size(); i++) {
        if (i > index && nums[i] == nums[i - 1]) continue; // Skip duplicates
        current.push_back(nums[i]); // Include the current element
        backtrack(nums, current, i + 1, result); // Recur with the next index
        current.pop_back(); // Backtrack: remove the last element
    }
}

void helper(int idx, int n, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    if (idx == n) {
        if(find(result.begin(), result.end(), current) == result.end()) // Check for duplicates
            result.push_back(current);
        return;
    }
    // Include the current element
    current.push_back(nums[idx]);
    helper(idx + 1, n, nums, current, result);
    current.pop_back(); // Backtrack

    // Skip duplicates
    // while (idx + 1 < n && nums[idx] == nums[idx + 1]) {
    //     idx++;
    // }
    helper(idx + 1, n, nums, current, result); // Exclude the current element
}

void solve(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i]; 
    }

    sort(nums.begin(), nums.end()); // Sort to handle duplicates
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
