
# Stack, Queue, Deque and Monotonic Structures

This note is written for Competitive Programming and interview preparation. It keeps the original ideas and strengthens them with the patterns, proofs, and problem sets that appear most often in Codeforces, LeetCode, and interviews.

---

## 1) Core Definitions

### Stack
A stack follows LIFO: Last In, First Out.

- push(x): add to top
- pop(): remove top
- top(): view top
- empty(): check emptiness
- size(): number of elements

C++:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    cout << st.top() << "\n"; // 20
    st.pop();
    cout << st.size() << "\n"; // 1
    return 0;
}
```

Java:

```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Stack<Integer> st = new Stack<>();
        st.push(10);
        st.push(20);
        System.out.println(st.peek()); // 20
        st.pop();
        System.out.println(st.size()); // 1
    }
}
```

### Queue
A queue follows FIFO: First In, First Out.

- push(x): enqueue at back
- pop(): dequeue from front
- front(): first element
- back(): last element

C++:

```cpp
queue<int> q;
q.push(1);
q.push(2);
cout << q.front() << "\n"; // 1
q.pop();
cout << q.back() << "\n"; // 2
```

Java:

```java
Queue<Integer> q = new ArrayDeque<>();
q.offer(1);
q.offer(2);
System.out.println(q.peek()); // 1
q.poll();
System.out.println(q.peek()); // 2
```

### Deque
Deque supports insertion/removal from both ends.

Useful when you need either front or back operations efficiently.

C++:

```cpp
deque<int> dq;
dq.push_back(10);
dq.push_front(20);
cout << dq.front() << "\n"; // 20
cout << dq.back() << "\n"; // 10
dq.pop_front();
```

Java:

```java
Deque<Integer> dq = new ArrayDeque<>();
dq.addLast(10);
dq.addFirst(20);
System.out.println(dq.getFirst()); // 20
System.out.println(dq.getLast()); // 10
dq.removeFirst();
```

### Important properties

- Stack: ideal for matching/bracket problems, recursive simulation, DFS.
- Queue: ideal for BFS, scheduling, ordering, producer/consumer models.
- Deque: ideal for sliding window, monotonic queue, and front/back operations.

---

## 2) Monotonic Stack

A monotonic stack keeps elements in increasing or decreasing order according to insertion order.

This is one of the most important patterns in competitive programming.

### Why it matters
For an array we often need:

- next greater element to left/right
- previous greater element to left/right
- next smaller element to left/right
- previous smaller element to left/right

These can be solved in O(n) using a monotonic stack.

### Core idea
We maintain a stack whose top is the candidate answer. While a condition fails, we pop and process the previous element.

This works because each element is pushed once and popped at most once.

### Typical pattern

```cpp
for (int i = 0; i < n; i++) {
    while (!st.empty() && st.top() < a[i]) {
        st.pop();
    }
    // st.top() is answer for current state
    st.push(a[i]);
}
```

### Time complexity
- Each element is pushed once.
- Each element is popped at most once.
- Total: O(n)
- Extra space: O(n)

---

## 3) Next Greater / Next Smaller Patterns

The most common mistake is to forget which direction we are scanning and which inequality sign we use.

### Next Greater Element to Left (NGE-L)
For each index i, find the nearest index j < i such that a[j] > a[i].

```cpp
vector<int> ans(n, -1);
stack<int> st;
for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.top()] <= a[i]) st.pop();
    ans[i] = st.empty() ? -1 : a[st.top()];
    st.push(i);
}
```

### Next Smaller Element to Left (NSE-L)

```cpp
while (!st.empty() && a[st.top()] >= a[i]) st.pop();
ans[i] = st.empty() ? -1 : a[st.top()];
st.push(i);
```

### Next Greater Element to Right (NGE-R)

```cpp
vector<int> ans(n, -1);
stack<int> st;
for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && st.top() <= a[i]) st.pop();
    ans[i] = st.empty() ? -1 : st.top();
    st.push(a[i]);
}
```

### Next Smaller Element to Right (NSE-R)

```cpp
while (!st.empty() && st.top() >= a[i]) st.pop();
ans[i] = st.empty() ? -1 : st.top();
st.push(a[i]);
```

### Important sign rules

- To find greater element: pop while current value is not strictly smaller than stack top.
- To find smaller element: pop while current value is not strictly greater than stack top.

### Original note preserved

```cpp
for i == 0 -> n:
    while(!s.empty() & s.top() >= a[i]){
        s.pop();
    }

    if(s.empty()){
        ans[i] = -1;
    } else {
        ans[i] = s.top();
    }

    s.push(a[i]);
```

This is the standard monotonic increasing stack approach. The time complexity is O(n) because every element is pushed once and popped at most once.

### Analogy-based reasoning

- Linear search for every index is O(n^2).
- A monotonic stack keeps the useful candidates only.
- The top of the stack is the best candidate for the current position.

---

## 4) Monotonic Queue

A monotonic queue maintains elements in sorted order with respect to their value while supporting insertion and deletion from both ends.

This is useful in:

- sliding window maximum
- sliding window minimum
- online maxima/minima queries

### Pattern

```cpp
deque<int> dq;
for (int i = 0; i < n; i++) {
    // Maintain a decreasing deque: front = largest value in current window
    while (!dq.empty() && dq.back() < a[i]) dq.pop_back();
    dq.push_back(a[i]);

    // Remove elements outside the current window [i-k+1, i]
    while (!dq.empty() && i - dq.front() + 1 > k) dq.pop_front();

    // If the window is valid, the front of deque is the maximum
    if (i + 1 >= k) ans.push_back(dq.front());
}
```

This keeps the maximum of each window at the front.

---

## 5) Stack/Queue Interview Concepts

### 1. Valid Parentheses
Check whether a string has balanced brackets.

Key idea: push opening brackets; on closing bracket, match with the top.

C++:

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else {
                if (st.empty()) return false;
                char top = st.top();
                if ((top == '(' && ch == ')') ||
                    (top == '{' && ch == '}') ||
                    (top == '[' && ch == ']')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
```

Java:

```java
class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for (char ch : s.toCharArray()) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.isEmpty()) return false;
                char top = st.peek();
                if ((top == '(' && ch == ')') ||
                    (top == '{' && ch == '}') ||
                    (top == '[' && ch == ']')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.isEmpty();
    }
}
```

### 2. Min Stack
Need push/pop/top/getMin in O(1) time.

Key idea: maintain a second stack of current minimums.

C++:

```cpp
class MinStack {
    stack<int> st, mn;
public:
    void push(int x) {
        st.push(x);
        if (mn.empty() || x <= mn.top()) mn.push(x);
    }
    void pop() {
        if (st.empty()) return;
        if (st.top() == mn.top()) mn.pop();
        st.pop();
    }
    int top() { return st.top(); }
    int getMin() { return mn.top(); }
};
```

Java:

```java
class MinStack {
    private Stack<Integer> st;
    private Stack<Integer> minSt;

    public MinStack() {
        st = new Stack<>();
        minSt = new Stack<>();
    }

    public void push(int x) {
        st.push(x);
        if (minSt.isEmpty() || x <= minSt.peek()) minSt.push(x);
    }

    public void pop() {
        if (st.isEmpty()) return;
        if (st.peek().equals(minSt.peek())) minSt.pop();
        st.pop();
    }

    public int top() { return st.peek(); }
    public int getMin() { return minSt.peek(); }
}
```

### 3. Implement Queue Using Stacks
Two stacks are enough to simulate queue behavior.

C++:

```cpp
class MyQueue {
    stack<int> in, out;
public:
    void push(int x) { in.push(x); }

    void pop() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        if (!out.empty()) out.pop();
    }

    int peek() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    bool empty() { return in.empty() && out.empty(); }
};
```

Java:

```java
class MyQueue {
    private Stack<Integer> in = new Stack<>();
    private Stack<Integer> out = new Stack<>();

    public void push(int x) { in.push(x); }

    public int pop() {
        if (out.isEmpty()) {
            while (!in.isEmpty()) {
                out.push(in.pop());
            }
        }
        return out.pop();
    }

    public int peek() {
        if (out.isEmpty()) {
            while (!in.isEmpty()) {
                out.push(in.pop());
            }
        }
        return out.peek();
    }

    public boolean empty() { return in.isEmpty() && out.isEmpty(); }
}
```

### 4. Implement Stack Using Queues
A queue-based stack is a classic pattern.

C++:

```cpp
class MyStack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 1; i < q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        int x = q.front(); q.pop(); return x;
    }
    int top() { return q.front(); }
    bool empty() { return q.empty(); }
};
```

Java:

```java
class MyStack {
    private Queue<Integer> q = new ArrayDeque<>();

    public void push(int x) {
        q.offer(x);
        for (int i = 1; i < q.size(); i++) {
            q.offer(q.poll());
        }
    }

    public int pop() { return q.poll(); }
    public int top() { return q.peek(); }
    public boolean empty() { return q.isEmpty(); }
}
```

---

## 6) Important Competitive Programming Problems

### Problem 1: Next Greater Element
Given an array, for each value find the nearest greater element on the left or right.

Pattern: monotonic stack.

Key idea:

```cpp
for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.top()] <= a[i]) st.pop();
    ans[i] = st.empty() ? -1 : a[st.top()];
    st.push(i);
}
```

### Problem 2: Daily Temperatures
For each day, find the next day with a higher temperature.

C++:

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && T[st.top()] <= T[i]) st.pop();
            ans[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return ans;
    }
};
```

Java:

```java
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int n = T.length;
        int[] ans = new int[n];
        Stack<Integer> st = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() && T[st.peek()] <= T[i]) {
                st.pop();
            }
            ans[i] = st.isEmpty() ? 0 : st.peek() - i;
            st.push(i);
        }
        return ans;
    }
}
```

### Problem 3: Largest Rectangle in Histogram
A classic monotonic stack problem.

Key idea: maintain increasing stack of indices.

C++:

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            while (!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;
                ans = max(ans, height * width);
            }
            st.push(i);
        }
        return ans;
    }
};
```

Java:

```java
class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> st = new Stack<>();
        int n = heights.length;
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            while (!st.isEmpty() && h < heights[st.peek()]) {
                int height = heights[st.pop()];
                int left = st.isEmpty() ? -1 : st.peek();
                int width = i - left - 1;
                ans = Math.max(ans, height * width);
            }
            st.push(i);
        }
        return ans;
    }
}
```

### Problem 4: Sliding Window Maximum
Use a monotonic deque.

C++:

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && dq.back() < nums[i]) dq.pop_back();
            dq.push_back(nums[i]);
            while (!dq.empty() && dq.front() == nums[i-k]) dq.pop_front();
            if (i >= k - 1) ans.push_back(dq.front());
        }
        return ans;
    }
};
```

Java:

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq = new ArrayDeque<>();
        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            while (!dq.isEmpty() && dq.peekLast() < nums[i]) {
                dq.pollLast();
            }
            dq.offerLast(nums[i]);

            while (!dq.isEmpty() && i - dq.peekFirst() + 1 > k) {
                dq.pollFirst();
            }

            if (i >= k - 1) ans.add(dq.peekFirst());
        }

        int[] result = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) result[i] = ans.get(i);
        return result;
    }
}
```

### Problem 5: Asteroid Collision
Stack matches positive and negative asteroids efficiently.

C++:

```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int> st;
        for (int x : ast) {
            bool alive = true;
            while (alive && x < 0 && !st.empty() && st.back() > 0) {
                int diff = st.back() + x;
                if (diff < 0) st.pop_back();
                else if (diff > 0) alive = false;
                else {
                    st.pop_back();
                    alive = false;
                }
            }
            if (alive) st.push_back(x);
        }
        return st;
    }
};
```

Java:

```java
class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> st = new Stack<>();
        for (int x : asteroids) {
            boolean alive = true;
            while (alive && x < 0 && !st.isEmpty() && st.peek() > 0) {
                int diff = st.peek() + x;
                if (diff < 0) st.pop();
                else if (diff > 0) alive = false;
                else {
                    st.pop();
                    alive = false;
                }
            }
            if (alive) st.push(x);
        }
        int[] ans = new int[st.size()];
        for (int i = ans.length - 1; i >= 0; i--) {
            ans[i] = st.pop();
        }
        return ans;
    }
}
```

### Problem 6: Remove All Adjacent Duplicates in String
Simple stack simulation.

C++:

```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        string st;
        for (char ch : s) {
            if (!st.empty() && st.back() == ch) st.pop_back();
            else st.push_back(ch);
        }
        return st;
    }
};
```

Java:

```java
class Solution {
    public String removeDuplicates(String s) {
        StringBuilder st = new StringBuilder();
        for (char ch : s.toCharArray()) {
            if (st.length() > 0 && st.charAt(st.length() - 1) == ch) {
                st.deleteCharAt(st.length() - 1);
            } else {
                st.append(ch);
            }
        }
        return st.toString();
    }
}
```

### Problem 7: Design Circular Queue
A deque or circular array queue problem.

C++:

```cpp
class MyCircularQueue {
    vector<int> q;
    int frontIndex, rearIndex, size, capacity;
public:
    MyCircularQueue(int k) : q(k), frontIndex(0), rearIndex(0), size(0), capacity(k) {}

    bool enQueue(int value) {
        if (isFull()) return false;
        q[rearIndex] = value;
        rearIndex = (rearIndex + 1) % capacity;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        frontIndex = (frontIndex + 1) % capacity;
        size--;
        return true;
    }

    int Front() { return isEmpty() ? -1 : q[frontIndex]; }
    int Rear() { return isEmpty() ? -1 : q[(rearIndex + capacity - 1) % capacity]; }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == capacity; }
};
```

Java:

```java
class MyCircularQueue {
    private int[] q;
    private int front, rear, size, capacity;

    public MyCircularQueue(int k) {
        q = new int[k];
        front = 0;
        rear = 0;
        size = 0;
        capacity = k;
    }

    public boolean enQueue(int value) {
        if (isFull()) return false;
        q[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
        return true;
    }

    public boolean deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    public int Front() { return isEmpty() ? -1 : q[front]; }
    public int Rear() { return isEmpty() ? -1 : q[(rear + capacity - 1) % capacity]; }
    public boolean isEmpty() { return size == 0; }
    public boolean isFull() { return size == capacity; }
}
```

---

## 7) Common CP Templates

### Template 1: Stack template

```cpp
stack<int> st;
while (!st.empty()) {
    int x = st.top();
    st.pop();
}
```

### Template 2: Queue template

```cpp
queue<int> q;
q.push(x);
int front = q.front();
q.pop();
```

### Template 3: Deque template

```cpp
deque<int> dq;
dq.push_back(x);
dq.push_front(x);
dq.pop_back();
dq.pop_front();
```

### Template 4: Monotonic increasing stack

```cpp
stack<int> st;
for (int x : arr) {
    while (!st.empty() && st.top() >= x) st.pop();
    // process x with current stack top
    st.push(x);
}
```

### Template 5: Monotonic decreasing stack

```cpp
stack<int> st;
for (int x : arr) {
    while (!st.empty() && st.top() <= x) st.pop();
    // process x with current stack top
    st.push(x);
}
```

---

## 8) Practical Tips for Competitive Programming

1. Before writing code, identify the exact operation you need:
   - stack = nearest previous/next while matching structure
   - queue = ordering / BFS / scheduling
   - deque = sliding windows and two-ended constraints

2. For monotonic problems, ask:
   - Which side is the answer on?
   - Does the stack need to be increasing or decreasing?
   - When do we pop?

3. Always reason about the invariant:
   - What remains in the stack after processing current element?
   - Why is it safe to pop?

4. Most stack problems are linear because each element is processed at most twice.

5. In Codeforces, the key is not just the data structure but the invariant.

---

## 9) Interview Checklist

You should be able to explain:

- stack vs queue vs deque
- LIFO vs FIFO
- monotonic stack invariant
- when to use stack for matching/nearest greater
- when to use deque for sliding window
- complexity analysis of each solution
- how to trace state for edge cases

### Typical interview edge cases

- empty structures
- duplicate values
- all equal elements
- negative values
- extreme large/small input sizes
- bracket mismatch at the very end

---

## 10) Final notes from the original work

```cpp
stack<type> var;
stack<pair<int, string>> st;

queue<type> var;
queue<pair<int, string>> que;

    * enque & deque operations
    * front() - returns the front values from the queue.

Deque - add or remove elements from both ends.

deque<type> var;
deque<pair<int, string>> q;

    * push_back(), pop_back()
    * push_front(), pop_front()
    * front(), back()
    * empty(), size()
```

### Monotonic Stack summary

-> Monotonic stack ensures that elements inside the stack are arranged in an increasing or decreasing order based on their arrival time.
-> It helps to find the following in O(1) per query after O(n) preprocessing:
    * Next greater element to left/right
    * Next smaller element to left/right

### Standard pattern

```cpp
for i == 0 -> n:
    while(!s.empty() && s.top() >= a[i]){
        s.pop();
    }

    if(s.empty()){
        ans[i] = -1;
    } else {
        ans[i] = s.top();
    }

    s.push(a[i]);
```

Time Complexity: O(n) because every element is pushed once and deleted at most once.

### Useful comparison

- Consider an index i, to find the next smaller element to the left in the range [0, i-1]
    - Approach 1: linear scan each query -> O(n^2)
    - Approach 2: a monotonic stack -> O(n)

- We keep the smaller/larger element at the top because, when we move to the next index, the current element can become the answer for that query if it satisfies the required greater-or-smaller condition.

### Core sign rules

Next Smallest Element: (Right to left) towards left
```cpp
while(!s.empty() && s.top() >= v[i]){
    s.pop();
}
```

Next Greater Element: (Right to left)
```cpp
while(!s.empty() && s.top() <= v[i]){
    s.pop();
}
```

Next Greater or equal to Element: (Right to left)
```cpp
while(!s.empty() && s.top() < v[i]){
    s.pop();
}
```

Next Smaller or equal to Element: (Right to left)
```cpp
while(!s.empty() && s.top() > v[i]){
    s.pop();
}
```

NSE towards right (Left to right)
```cpp
while(!s.empty() && s.top() >= v[i]){
    s.pop();
}
```

---

## 11) Final takeaway

Stack and queue problems are often about one key idea:

- maintain a valid candidate set
- discard everything that can never become useful
- keep only the elements that still matter for future answers

That is exactly why monotonic stack/queue problems are so common in CP and interviews.

If you can reason with the invariant and keep the structure monotonic, you will solve a large number of hard-looking problems with surprisingly short code.
