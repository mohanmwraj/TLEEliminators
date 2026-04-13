//**********************************************************************************
// pbm : https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/description/
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
    You are given a positive integer n.

    A binary string x is valid if all substrings of x of length 2 contain at least one "1".

    Return all valid strings with length n, in any order.
*/

/*
    2 Adjacent zeros are not allowed in the string. So we can have '1' followed by '0' or '1' 
    followed by '1', but not '0' followed by '0'.
    
    Approach: Recursion

    We can generate all valid strings of length n by recursively appending '1' or '0' to the current string.
    However, we need to ensure that we do not append '0' if the last character of the current string is '0', 
    as that would create a substring of "00".

    The base case is when the length of the current string is equal to n, at which point we can add it to our 
    list of valid strings.

    Time Complexity: O(2^n) in the worst case, as we are generating all possible combinations of '1' and '0'.
    Space Complexity: O(n) for the recursion stack, and O(2^n) for storing the valid strings in the worst case.

*/

void solve(){
    int n; cin >> n;
    vector<string> result;
    function<void(string)> generate = [&](string current) {
        if (current.length() == n) {
            result.push_back(current);
            return;
        }
        // Append '1' to the current string
        generate(current + '1');
        // Append '0' to the current string only if the last character is not '0'
        if (current.empty() || current.back() != '0') {
            generate(current + '0');
        }
    };
    generate("");
    for (const string& str : result) {
        cout << str << endl;
    }
}

void recurse(int n, string s){
    if(n == 0){
        cout << s << endl;
        return;
    }

    if(s.empty() || s.back() != '0'){
        recurse(n-1, s + '0');
        recurse(n-1, s + '1');
    } else {
        recurse(n-1, s + '1');
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
