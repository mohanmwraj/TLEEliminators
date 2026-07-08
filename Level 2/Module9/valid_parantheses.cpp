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
}
