//**********************************************************************************
// pbm : https://leetcode.com/problems/min-stack/description/
//**********************************************************************************
#include <bits/stdc++.h>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> s;
    stack<int> pre;
    
    MinStack() {
        
    }
    void push(int val) {
        s.push(val);
        if(pre.empty() || val <= pre.top()){
            pre.push(min(val, pre.empty() ? val : pre.top()));
        }
    }

    void pop() {
        if(s.top() == pre.top()){
            pre.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return pre.top();
    }
};

