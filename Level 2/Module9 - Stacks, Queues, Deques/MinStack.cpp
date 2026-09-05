//**********************************************************************************
// pbm : https://leetcode.com/problems/min-stack/description/
//**********************************************************************************
#include <bits/stdc++.h>
#include <stack>
using namespace std;

class MinStack {
public:
    // Main stack stores all values.
    stack<int> s;
    // pre stores the running minimums in the same order as s.
    stack<int> pre;

    MinStack() {
        // Default constructor
    }

    void push(int val) {
        s.push(val);

        // If the new value is smaller or equal to current minimum,
        // store it in the min-stack.
        if (pre.empty() || val <= pre.top()) {
            pre.push(val);
        }
    }

    void pop() {
        // If the popped value is the current minimum,
        // also remove it from the min-stack.
        if (!s.empty() && !pre.empty() && s.top() == pre.top()) {
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

