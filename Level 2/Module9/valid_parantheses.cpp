//**********************************************************************************
// pbm : https://leetcode.com/problems/valid-parentheses/description/
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

void solve(string s){
    stack<char> st;
    for(char c : s){
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        } else {
            if(st.empty()){
                cout << "false" << endl;
                return;
            }
            char top = st.top();
            if((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')){
                cout << "false" << endl;
                return;
            }
            st.pop();
        }
    }
    if(st.empty()){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
}


int main() {
    int T = 1;
    cin >> T;
    string s = "{([)]}";
    while(T--){
        solve(s);
    }
    return 0;
};


class Solution {
    private:
         unordered_map<char, char> mapping;
        //   = {
        //     {')', '('},
        //     {']', '['},
        //     {'}', '{'}
        // };
    public:
        Solution(){
            mapping = {
                {')', '('},
                {']', '['},
                {'}', '{'}
            };
            /*
                mappings[')'] = '(';
                mappings[']'] = '[';
                mappings['}'] = '{';
            */
        }
    
        bool isValid(string s) {
            stack<char> st;
            for(char c : s){
                if(mapping.find(c) != mapping.end()){
                    char top = st.empty() ? '#' : st.top();
                    if(top != mapping[c]){
                        return false;
                    }
                    st.pop();
                } else {
                    st.push(c);
                }
            }
            return st.empty();
        }   
        // Time Complexity: O(n), where n is the length of the string s. We traverse the string once, and each push and pop operation on the stack takes O(1) time.
        // Space Complexity: O(n), in the worst case, we may need to store all
        // the opening brackets in the stack if there are no matching closing brackets.

        
};