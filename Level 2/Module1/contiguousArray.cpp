//**********************************************************************************
// pbm : https://leetcode.com/problems/contiguous-array/description/
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
    Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

    Example 1:
    Input: nums = [0,1]
    Output: 2
    Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

    Example 2:
    Input: nums = [0,1,0]
    Output: 2
    Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

*/

/*
    Approach:
        map with prefix sum as key and index as value. 
        Whenever we encounter a prefix sum that we have seen before, 
        it means that the subarray between the previous index and the current index has an equal number of 0 and 1.

        0 map to -1, 
        1 map to +1
        prefix sum = 0 means equal number of 0 and 1

    Time Complexity : O(n)
    Space Complexity : O(n)
*/

/*
    - Two points i, j from start they both got the value of X, 
    - then i+1 to j will have the sum of 0, which means equal number of 0 and 1.
    - j-i will be the length of the subarray with equal number of 0 and 1.
    - If we encounter the same prefix sum again, 
    it means that the subarray between the previous index and the current index has an equal number of 0 and 1.

*/
void solve(){
    int n; cin >> n;
    vector<int> nums(n);
    for(auto &it:nums) cin >> it;

    int ans = 0, sum = 0;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        sum += (nums[i] == 0) ? -1 : 1;
        if(sum == 0){
            ans = max(ans, i + 1);
        }
        else if(mp.find(sum) != mp.end()){
            ans = max(ans, i - mp[sum]);
        }
        else{
            mp[sum] = i;
        }
    }
    cout << ans << endl;
    
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
