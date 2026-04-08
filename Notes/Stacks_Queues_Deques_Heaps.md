# 🔥 Stacks, Queues, Deques & Heaps — Complete Guide for CP & FAANG

> **Goal**: Codeforces Master | FAANG Mid-Senior SWE  
> **Last Updated**: April 2026

---

## 📚 Table of Contents
1. [Stack](#stack)
2. [Queue](#queue)
3. [Deque (Double-Ended Queue)](#deque-double-ended-queue)
4. [Monotonic Stack](#monotonic-stack)
5. [Monotonic Deque (Sliding Window)](#monotonic-deque-sliding-window)
6. [Priority Queue / Heap](#priority-queue--heap)
7. [Two-Heap Pattern](#two-heap-pattern)
8. [Comparison Table](#comparison-table)
9. [FAANG LeetCode Problem List](#faang-leetcode-problem-list)
10. [Quick Revision Checklist](#quick-revision-checklist)

---

# Stack

## Core Idea
**LIFO** — Last In, First Out. Think of a stack of plates.

```
push(5) → [5]
push(3) → [5, 3]
push(7) → [5, 3, 7]
pop()   → [5, 3]   returns 7
top()   → 3
```

## Operations & Time Complexity

| Operation | Time | Space |
|-----------|------|-------|
| `push(x)` | $O(1)$ | — |
| `pop()` | $O(1)$ | — |
| `top()` / `peek()` | $O(1)$ | — |
| `empty()` | $O(1)$ | — |
| `size()` | $O(1)$ | — |
| Search | $O(n)$ | — |
| **Overall space** | — | $O(n)$ |

## C++ STL

```cpp
#include <stack>
stack<int> st;
st.push(10);
st.top();      // 10
st.pop();      // removes 10
st.empty();    // true
st.size();     // 0
```

## When to Use Stack
- **Matching brackets / parentheses** — classic
- **Undo operations** — last action reversed first
- **DFS (iterative)** — explicit stack replaces call stack  
- **Expression evaluation** — infix, postfix, prefix
- **Monotonic stack** — next greater/smaller element  
- **Backtracking** — implicit stack via recursion

## CP/FAANG Problems with Analysis

---

### Problem 1: Valid Parentheses (LC 20)

```cpp
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top(); st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
        }
    }
    return st.empty();
}
```
**TC**: $O(n)$ — single pass  
**SC**: $O(n)$ — worst case all opening brackets

---

### Problem 2: Min Stack (LC 155)

Store pairs `(value, current_min)` on the stack.

```cpp
class MinStack {
    stack<pair<int,int>> st; // (val, min_so_far)
public:
    void push(int val) {
        int mn = st.empty() ? val : min(val, st.top().second);
        st.push({val, mn});
    }
    void pop() { st.pop(); }
    int top() { return st.top().first; }
    int getMin() { return st.top().second; }
};
```
**TC**: All operations $O(1)$  
**SC**: $O(n)$

---

### Problem 3: Evaluate Reverse Polish Notation (LC 150)

```cpp
int evalRPN(vector<string>& tokens) {
    stack<long long> st;
    for (auto& t : tokens) {
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            if (t == "+") st.push(a + b);
            else if (t == "-") st.push(a - b);
            else if (t == "*") st.push(a * b);
            else st.push(a / b);
        } else {
            st.push(stoll(t));
        }
    }
    return st.top();
}
```
**TC**: $O(n)$  
**SC**: $O(n)$

---

### Problem 4: Largest Rectangle in Histogram (LC 84)

**Key Insight**: For each bar, find the nearest smaller bar on left and right using a monotonic stack.

```cpp
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size(), ans = 0;
    stack<int> st; // indices of increasing heights
    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        while (!st.empty() && heights[st.top()] > h) {
            int height = heights[st.top()]; st.pop();
            int width = st.empty() ? i : (i - st.top() - 1);
            ans = max(ans, height * width);
        }
        st.push(i);
    }
    return ans;
}
```
**TC**: $O(n)$ — each index pushed and popped at most once  
**SC**: $O(n)$

---

### Problem 5: Daily Temperatures (LC 739)

```cpp
vector<int> dailyTemperatures(vector<int>& T) {
    int n = T.size();
    vector<int> ans(n, 0);
    stack<int> st; // decreasing stack of indices
    for (int i = 0; i < n; i++) {
        while (!st.empty() && T[i] > T[st.top()]) {
            int idx = st.top(); st.pop();
            ans[idx] = i - idx;
        }
        st.push(i);
    }
    return ans;
}
```
**TC**: $O(n)$ — amortized, each element pushed/popped once  
**SC**: $O(n)$

---

### Problem 6: Trapping Rain Water (LC 42) — Stack Approach

```cpp
int trap(vector<int>& height) {
    stack<int> st;
    int water = 0;
    for (int i = 0; i < height.size(); i++) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int bot = height[st.top()]; st.pop();
            if (st.empty()) break;
            int w = i - st.top() - 1;
            int h = min(height[i], height[st.top()]) - bot;
            water += w * h;
        }
        st.push(i);
    }
    return water;
}
```
**TC**: $O(n)$  
**SC**: $O(n)$

---

# Queue

## Core Idea
**FIFO** — First In, First Out. Think of a line at a counter.

```
enqueue(5) → [5]
enqueue(3) → [5, 3]
enqueue(7) → [5, 3, 7]
dequeue()  → [3, 7]   returns 5
front()    → 3
```

## Operations & Time Complexity

| Operation | Time | Space |
|-----------|------|-------|
| `push(x)` / `enqueue` | $O(1)$ | — |
| `pop()` / `dequeue` | $O(1)$ | — |
| `front()` | $O(1)$ | — |
| `back()` | $O(1)$ | — |
| `empty()` | $O(1)$ | — |
| `size()` | $O(1)$ | — |
| Search | $O(n)$ | — |
| **Overall space** | — | $O(n)$ |

## C++ STL

```cpp
#include <queue>
queue<int> q;
q.push(10);
q.front();    // 10
q.back();     // 10
q.pop();      // removes 10
q.empty();    // true
```

## When to Use Queue
- **BFS** — level-order traversal on graphs/trees
- **Task scheduling** — process in arrival order
- **Sliding window** — combined with deque for optimization
- **Stream processing** — buffer data in order

## CP/FAANG Problems with Analysis

---

### Problem 7: Implement Queue using Stacks (LC 232)

**Amortized O(1)** — push to input stack, lazily transfer to output stack on pop/peek.

```cpp
class MyQueue {
    stack<int> in, out;
    void transfer() {
        if (out.empty())
            while (!in.empty()) { out.push(in.top()); in.pop(); }
    }
public:
    void push(int x) { in.push(x); }
    int pop() { transfer(); int v = out.top(); out.pop(); return v; }
    int peek() { transfer(); return out.top(); }
    bool empty() { return in.empty() && out.empty(); }
};
```
**TC**: `push` $O(1)$, `pop`/`peek` amortized $O(1)$ (each element transferred at most once)  
**SC**: $O(n)$

---

### Problem 8: Implement Stack using Queues (LC 225)

```cpp
class MyStack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < (int)q.size() - 1; i++) {
            q.push(q.front()); q.pop();
        }
    }
    int pop() { int v = q.front(); q.pop(); return v; }
    int top() { return q.front(); }
    bool empty() { return q.empty(); }
};
```
**TC**: `push` $O(n)$, `pop`/`top` $O(1)$  
**SC**: $O(n)$

---

### Problem 9: Number of Recent Calls (LC 933)

```cpp
class RecentCounter {
    queue<int> q;
public:
    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) q.pop();
        return q.size();
    }
};
```
**TC**: Amortized $O(1)$ per ping (each element enqueued & dequeued once)  
**SC**: $O(W)$ where $W = 3000$

---

### Problem 10: Rotting Oranges (LC 994) — Multi-source BFS

```cpp
int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), fresh = 0, time = 0;
    queue<pair<int,int>> q;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) q.push({i, j});
            else if (grid[i][j] == 1) fresh++;
        }
    int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
    while (!q.empty() && fresh > 0) {
        int sz = q.size();
        while (sz--) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx, ny});
                }
            }
        }
        time++;
    }
    return fresh == 0 ? time : -1;
}
```
**TC**: $O(m \times n)$  
**SC**: $O(m \times n)$

---

### Problem 11: Walls and Gates (LC 286) — Multi-source BFS

Start BFS from all gates simultaneously; queue guarantees shortest distance.

**TC**: $O(m \times n)$  
**SC**: $O(m \times n)$

---

# Deque (Double-Ended Queue)

## Core Idea
Insert and remove from **both ends** in $O(1)$.

```
push_back(5)  → [5]
push_front(3) → [3, 5]
push_back(7)  → [3, 5, 7]
pop_front()   → [5, 7]   returns 3
pop_back()    → [5]      returns 7
```

## Operations & Time Complexity

| Operation | Time | Note |
|-----------|------|------|
| `push_front(x)` | $O(1)$ | — |
| `push_back(x)` | $O(1)$ | — |
| `pop_front()` | $O(1)$ | — |
| `pop_back()` | $O(1)$ | — |
| `front()` / `back()` | $O(1)$ | — |
| `operator[]` (random access) | $O(1)$ | C++ `deque` supports this! |
| `insert` at middle | $O(n)$ | Rare use |
| **Overall space** | $O(n)$ | — |

## C++ STL

```cpp
#include <deque>
deque<int> dq;
dq.push_back(10);
dq.push_front(5);
dq.front();       // 5
dq.back();        // 10
dq[0];            // 5 — random access!
dq.pop_front();
dq.pop_back();
```

> **`deque` vs `vector`**: `deque` has $O(1)$ `push_front`; `vector` has $O(n)$ `insert(begin())`. But `vector` has better cache performance. Use `deque` when you need both-end operations.

## When to Use Deque
- **Sliding window max/min** — monotonic deque
- **0-1 BFS** — push weight-0 edges to front, weight-1 to back
- **Palindrome checking** — compare front and back
- **Work-stealing** — concurrent algorithms take from both ends

## CP/FAANG Problems with Analysis

---

### Problem 12: Sliding Window Maximum (LC 239) — Monotonic Deque

**The single most important deque problem for interviews.**

```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // indices, decreasing values
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        // Remove elements outside window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        // Maintain decreasing order
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}
```
**TC**: $O(n)$ — each element pushed and popped at most once  
**SC**: $O(k)$

**Why it works**: The deque always contains indices in **decreasing value** order. The front is always the max of the current window. When a larger element enters, all smaller elements in the deque are useless → pop them.

---

### Problem 13: 0-1 BFS (CP Classic — Codeforces staple)

**Find shortest path when edge weights are only 0 or 1.**

```cpp
vector<int> bfs01(int src, vector<vector<pair<int,int>>>& adj, int n) {
    vector<int> dist(n, INT_MAX);
    deque<int> dq;
    dist[src] = 0;
    dq.push_back(src);
    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (w == 0) dq.push_front(v);  // 0-weight → front (higher priority)
                else        dq.push_back(v);   // 1-weight → back
            }
        }
    }
    return dist;
}
```
**TC**: $O(V + E)$ — same as BFS! Way better than Dijkstra's $O((V+E) \log V)$ for 0-1 graphs  
**SC**: $O(V)$

**When to spot this in CP**: Graph with binary weights, or grid problems where some moves are free.

---

### Problem 14: Design Circular Deque (LC 641)

Classic implementation exercise. Use a circular array:

```cpp
class MyCircularDeque {
    vector<int> data;
    int front, rear, size, cap;
public:
    MyCircularDeque(int k) : data(k), front(0), rear(k - 1), size(0), cap(k) {}
    bool insertFront(int val) {
        if (isFull()) return false;
        front = (front - 1 + cap) % cap;
        data[front] = val; size++;
        return true;
    }
    bool insertLast(int val) {
        if (isFull()) return false;
        rear = (rear + 1) % cap;
        data[rear] = val; size++;
        return true;
    }
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % cap; size--;
        return true;
    }
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + cap) % cap; size--;
        return true;
    }
    int getFront() { return isEmpty() ? -1 : data[front]; }
    int getRear()  { return isEmpty() ? -1 : data[rear]; }
    bool isEmpty()  { return size == 0; }
    bool isFull()   { return size == cap; }
};
```
**TC**: All operations $O(1)$  
**SC**: $O(k)$

---

# Monotonic Stack

## Core Idea
A stack that maintains elements in **monotonically increasing or decreasing** order. When a new element violates the order, pop until order is restored.

**Purpose**: Find the **Next Greater Element (NGE)**, **Next Smaller Element (NSE)**, **Previous Greater/Smaller** in $O(n)$.

## The Four Variants

| Problem | Stack Order | Direction | Pop When |
|---------|------------|-----------|----------|
| Next Greater Element (right) | Decreasing | Left → Right | `stack.top() < curr` |
| Next Smaller Element (right) | Increasing | Left → Right | `stack.top() > curr` |
| Previous Greater Element (left) | Decreasing | Left → Right | `stack.top() <= curr` |
| Previous Smaller Element (left) | Increasing | Left → Right | `stack.top() >= curr` |

> **Strict vs non-strict**: Use `<` vs `<=` depending on whether equal elements count.

## Template: Next Greater Element

```cpp
// Returns NGE index for each element. -1 if none exists.
vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> st; // decreasing stack of indices
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return nge;
}
```

## Template: Previous Smaller Element

```cpp
vector<int> prevSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> pse(n, -1);
    stack<int> st; // increasing stack of indices
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if (!st.empty()) pse[i] = st.top();
        st.push(i);
    }
    return pse;
}
```

**TC**: $O(n)$ — each element pushed and popped at most once (amortized analysis)  
**SC**: $O(n)$

## CP/FAANG Problems

---

### Problem 15: Next Greater Element I (LC 496)

```cpp
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nge;
    stack<int> st;
    for (int x : nums2) {
        while (!st.empty() && st.top() < x) {
            nge[st.top()] = x;
            st.pop();
        }
        st.push(x);
    }
    vector<int> ans;
    for (int x : nums1)
        ans.push_back(nge.count(x) ? nge[x] : -1);
    return ans;
}
```
**TC**: $O(n + m)$  
**SC**: $O(n)$

---

### Problem 16: Next Greater Element II (LC 503) — Circular Array

**Trick**: Iterate twice (modular indexing) to simulate circular array.

```cpp
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = 0; i < 2 * n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i % n]) {
            ans[st.top()] = nums[i % n];
            st.pop();
        }
        if (i < n) st.push(i);
    }
    return ans;
}
```
**TC**: $O(n)$  
**SC**: $O(n)$

---

### Problem 17: Stock Span Problem (LC 901)

Find how many consecutive days (including today) the price was ≤ today's price. Equivalent to **Previous Greater Element**.

```cpp
class StockSpanner {
    stack<pair<int,int>> st; // (price, span)
public:
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};
```
**TC**: Amortized $O(1)$ per call  
**SC**: $O(n)$

---

### Problem 18: Sum of Subarray Minimums (LC 907)

**Key Insight**: For each element, find how many subarrays it is the minimum of, using PSE (Previous Smaller Element) and NSE (Next Smaller Element).

Contribution of `arr[i]` = `arr[i] * left[i] * right[i]` where:
- `left[i]` = distance to previous smaller (or left boundary)
- `right[i]` = distance to next smaller or equal (or right boundary)

```cpp
int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size(), MOD = 1e9 + 7;
    vector<int> left(n), right(n);
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        left[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
        right[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }
    
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans = (ans + (long long)arr[i] * left[i] % MOD * right[i]) % MOD;
    return ans;
}
```
**TC**: $O(n)$  
**SC**: $O(n)$

> **Codeforces Tip**: Subarray min/max contribution technique appears in rating 1600-2000 problems frequently. Master this pattern.

---

### Problem 19: Maximal Rectangle (LC 85)

Reduce to Largest Rectangle in Histogram (Problem 4) per row.

```cpp
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size(), ans = 0;
    vector<int> heights(n, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
        ans = max(ans, largestRectangleArea(heights)); // Problem 4
    }
    return ans;
}
```
**TC**: $O(m \times n)$  
**SC**: $O(n)$

---

# Monotonic Deque (Sliding Window)

## Core Idea
Extend the monotonic stack to support **expiration** of old elements (sliding window).

The deque maintains a window of size $k$ with elements in monotonic order.  
- **Front** = optimal answer for current window  
- **Back** = where new elements enter  
- Remove from front when element exits window  
- Remove from back to maintain monotonic property  

## Template: Sliding Window Minimum

```cpp
// Returns minimum in every window of size k
vector<int> slidingWindowMin(vector<int>& arr, int k) {
    deque<int> dq; // increasing order of values (store indices)
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++) {
        // Remove expired elements
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        // Maintain increasing order
        while (!dq.empty() && arr[dq.back()] >= arr[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) ans.push_back(arr[dq.front()]);
    }
    return ans;
}
```

**TC**: $O(n)$  
**SC**: $O(k)$

## CP Application: DP Optimization

Many DP transitions of the form:

$$dp[i] = \min_{j \in [i-k, i-1]} dp[j] + cost(i)$$

can be optimized from $O(nk)$ to $O(n)$ using a monotonic deque.

```cpp
// Example: minimum cost to reach index i, can jump at most k steps
deque<int> dq;
for (int i = 0; i < n; i++) {
    while (!dq.empty() && dq.front() < i - k) dq.pop_front();
    if (!dq.empty()) dp[i] = dp[dq.front()] + cost[i];
    while (!dq.empty() && dp[dq.back()] >= dp[i]) dq.pop_back();
    dq.push_back(i);
}
```

---

# Priority Queue / Heap

## Core Idea
A **complete binary tree** where each parent is greater (max-heap) or smaller (min-heap) than its children. Provides $O(\log n)$ insert and extract-optimal.

```
Max Heap:        50
               /    \
             30      40
            /  \    /
          10   20  15

Array representation: [50, 30, 40, 10, 20, 15]
Parent of i: (i-1)/2     Children of i: 2i+1, 2i+2
```

## Operations & Time Complexity

| Operation | Time | Notes |
|-----------|------|-------|
| `push(x)` (insert) | $O(\log n)$ | Bubble up |
| `pop()` (extract top) | $O(\log n)$ | Swap with last, bubble down |
| `top()` (peek max/min) | $O(1)$ | Root element |
| `heapify` (build from array) | $O(n)$ | NOT $O(n \log n)$! |
| `empty()` / `size()` | $O(1)$ | — |
| Search / Delete arbitrary | $O(n)$ | Heap doesn't support efficient search |
| Decrease/Increase key | $O(\log n)$ | With index tracking |
| **Overall space** | $O(n)$ | — |

> **Why `heapify` is $O(n)$, not $O(n \log n)$**: Most nodes are near the bottom. Nodes at height $h$ need $O(h)$ work. Sum: $\sum_{h=0}^{\log n} \frac{n}{2^{h+1}} \cdot O(h) = O(n)$.

## C++ STL Priority Queue

```cpp
#include <queue>

// Max heap (default)
priority_queue<int> maxPQ;
maxPQ.push(10);
maxPQ.push(30);
maxPQ.push(20);
maxPQ.top();  // 30
maxPQ.pop();  // removes 30

// Min heap
priority_queue<int, vector<int>, greater<int>> minPQ;
minPQ.push(10);
minPQ.push(30);
minPQ.push(20);
minPQ.top();  // 10

// Custom comparator (sort by second element, ascending)
auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
    return a.second > b.second; // min heap by second
};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
```

## When to Use Heap
- **Top K elements** — maintain heap of size k
- **Kth largest/smallest** — min/max heap of size k
- **Merge K sorted lists/arrays** — min heap
- **Dijkstra's shortest path** — min heap
- **Median maintenance** — two heaps
- **Task scheduling with priorities** — max/min heap
- **Huffman coding** — min heap

## Heap Sort

```cpp
// In-place, O(n log n), NOT stable
void heapSort(vector<int>& arr) {
    int n = arr.size();
    // Build max heap: O(n)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // Extract elements one by one: O(n log n)
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void heapify(vector<int>& arr, int n, int i) {
    int largest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
```
**TC**: Build $O(n)$ + Extract $O(n \log n)$ = $O(n \log n)$  
**SC**: $O(1)$ in-place (but not stable!)

## CP/FAANG Problems with Analysis

---

### Problem 20: Kth Largest Element in Array (LC 215)

**Approach 1: Min Heap of size K**

```cpp
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minPQ;
    for (int x : nums) {
        minPQ.push(x);
        if (minPQ.size() > k) minPQ.pop();
    }
    return minPQ.top();
}
```
**TC**: $O(n \log k)$  
**SC**: $O(k)$

**Approach 2: Quickselect** — $O(n)$ average, $O(n^2)$ worst. More efficient but trickier.

---

### Problem 21: Top K Frequent Elements (LC 347)

```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int x : nums) freq[x]++;
    
    // Min heap of (frequency, element)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    for (auto& [val, cnt] : freq) {
        pq.push({cnt, val});
        if (pq.size() > k) pq.pop();
    }
    
    vector<int> ans;
    while (!pq.empty()) { ans.push_back(pq.top().second); pq.pop(); }
    return ans;
}
```
**TC**: $O(n \log k)$  
**SC**: $O(n)$ for the frequency map

---

### Problem 22: Merge K Sorted Lists (LC 23)

```cpp
ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    
    for (auto* l : lists)
        if (l) pq.push(l);
    
    ListNode dummy(0), *tail = &dummy;
    while (!pq.empty()) {
        auto* node = pq.top(); pq.pop();
        tail->next = node;
        tail = tail->next;
        if (node->next) pq.push(node->next);
    }
    return dummy.next;
}
```
**TC**: $O(N \log k)$ where $N$ = total elements, $k$ = number of lists  
**SC**: $O(k)$

---

### Problem 23: Dijkstra's Shortest Path (CP Essential)

```cpp
vector<long long> dijkstra(int src, vector<vector<pair<int,int>>>& adj, int n) {
    vector<long long> dist(n, LLONG_MAX);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue; // lazy deletion — skip stale entries
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```
**TC**: $O((V + E) \log V)$ with binary heap  
**SC**: $O(V + E)$

> **CP Note**: Use `if (d > dist[u]) continue;` for lazy deletion instead of decrease-key. Simpler and fast enough for contests.

---

### Problem 24: Task Scheduler (LC 621)

```cpp
int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    for (char c : tasks) freq[c - 'A']++;
    priority_queue<int> pq;
    for (int f : freq) if (f > 0) pq.push(f);
    
    int time = 0;
    while (!pq.empty()) {
        vector<int> temp;
        for (int i = 0; i <= n; i++) {
            if (!pq.empty()) {
                temp.push_back(pq.top() - 1);
                pq.pop();
            }
            time++;
            if (pq.empty() && temp.back() <= 0 && 
                all_of(temp.begin(), temp.end(), [](int x){ return x <= 0; }))
                break;
        }
        for (int t : temp) if (t > 0) pq.push(t);
    }
    return time;
}
```
**TC**: $O(n \cdot 26) = O(n)$ where $n$ = number of tasks  
**SC**: $O(1)$ (26 characters)

---

### Problem 25: Reorganize String (LC 767)

```cpp
string reorganizeString(string s) {
    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;
    priority_queue<pair<int,char>> pq;
    for (int i = 0; i < 26; i++)
        if (freq[i] > 0) pq.push({freq[i], 'a' + i});
    
    string ans;
    while (pq.size() >= 2) {
        auto [f1, c1] = pq.top(); pq.pop();
        auto [f2, c2] = pq.top(); pq.pop();
        ans += c1; ans += c2;
        if (f1 - 1 > 0) pq.push({f1 - 1, c1});
        if (f2 - 1 > 0) pq.push({f2 - 1, c2});
    }
    if (!pq.empty()) {
        if (pq.top().first > 1) return "";
        ans += pq.top().second;
    }
    return ans;
}
```
**TC**: $O(n \log 26) = O(n)$  
**SC**: $O(1)$

---

### Problem 26: K Closest Points to Origin (LC 973)

```cpp
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // Max heap — keep the k smallest by popping the largest when size > k
    auto cmp = [](vector<int>& a, vector<int>& b) {
        return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
    for (auto& p : points) {
        pq.push(p);
        if (pq.size() > k) pq.pop();
    }
    vector<vector<int>> ans;
    while (!pq.empty()) { ans.push_back(pq.top()); pq.pop(); }
    return ans;
}
```
**TC**: $O(n \log k)$  
**SC**: $O(k)$

---

# Two-Heap Pattern

## Core Idea
Maintain a **max-heap** for the lower half and a **min-heap** for the upper half of a data stream. The median is always accessible from the tops of the two heaps.

```
Max Heap (lower)  |  Min Heap (upper)
     [3, 1]       |     [5, 7]
      top=3       |      top=5

Median = (3 + 5) / 2 = 4
```

**Invariants**:
1. `maxHeap.size()` == `minHeap.size()` or `maxHeap.size()` == `minHeap.size() + 1`
2. Every element in maxHeap ≤ every element in minHeap

---

### Problem 27: Find Median from Data Stream (LC 295)

```cpp
class MedianFinder {
    priority_queue<int> lo;                              // max heap (lower half)
    priority_queue<int, vector<int>, greater<int>> hi;   // min heap (upper half)
public:
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top()); lo.pop();  // balance: push to lo, move max to hi
        if (hi.size() > lo.size()) {  // keep lo.size >= hi.size
            lo.push(hi.top()); hi.pop();
        }
    }
    double findMedian() {
        return lo.size() > hi.size() ? lo.top() : (lo.top() + hi.top()) / 2.0;
    }
};
```
**TC**: `addNum` $O(\log n)$, `findMedian` $O(1)$  
**SC**: $O(n)$

---

### Problem 28: Sliding Window Median (LC 480)

Harder version — maintain two heaps with lazy deletion for the sliding window.

**TC**: $O(n \log n)$  
**SC**: $O(n)$

---

### Problem 29: IPO (LC 502)

Two heaps: min-heap on capital requirements, max-heap on profits of affordable projects.

**TC**: $O(n \log n)$  
**SC**: $O(n)$

---

# Comparison Table

| Feature | Stack | Queue | Deque | Priority Queue |
|---------|-------|-------|-------|----------------|
| **Order** | LIFO | FIFO | Both ends | By priority |
| **Insert** | $O(1)$ top | $O(1)$ back | $O(1)$ both | $O(\log n)$ |
| **Remove** | $O(1)$ top | $O(1)$ front | $O(1)$ both | $O(\log n)$ top |
| **Peek** | $O(1)$ | $O(1)$ | $O(1)$ | $O(1)$ |
| **Search** | $O(n)$ | $O(n)$ | $O(n)$ | $O(n)$ |
| **Random Access** | No | No | Yes (C++ deque) | No |
| **Use case** | DFS, undo, parsing | BFS, scheduling | Sliding window, 0-1 BFS | Top-K, greedy, scheduling |
| **C++ STL** | `stack<T>` | `queue<T>` | `deque<T>` | `priority_queue<T>` |
| **Underlying** | `deque` (default) | `deque` (default) | Blocked array | `vector` (default) |

---

# FAANG LeetCode Problem List

## Must-Solve (Sorted by Priority)

### Stack
| # | Problem | Difficulty | Pattern | Frequency |
|---|---------|-----------|---------|-----------|
| 20 | Valid Parentheses | Easy | Matching | ★★★★★ |
| 155 | Min Stack | Medium | Design | ★★★★★ |
| 150 | Evaluate Reverse Polish Notation | Medium | Evaluation | ★★★★ |
| 84 | Largest Rectangle in Histogram | Hard | Monotonic Stack | ★★★★★ |
| 739 | Daily Temperatures | Medium | Monotonic Stack | ★★★★★ |
| 42 | Trapping Rain Water | Hard | Monotonic Stack | ★★★★★ |
| 85 | Maximal Rectangle | Hard | Mono Stack + DP | ★★★★ |
| 496 | Next Greater Element I | Easy | Monotonic Stack | ★★★★ |
| 503 | Next Greater Element II | Medium | Mono Stack + Circular | ★★★★ |
| 901 | Online Stock Span | Medium | Monotonic Stack | ★★★★ |
| 907 | Sum of Subarray Minimums | Medium | Mono Stack + Contrib | ★★★★ |
| 316 | Remove Duplicate Letters | Medium | Greedy + Stack | ★★★ |
| 32 | Longest Valid Parentheses | Hard | Stack | ★★★★ |
| 71 | Simplify Path | Medium | Stack | ★★★ |
| 394 | Decode String | Medium | Stack | ★★★★ |
| 735 | Asteroid Collision | Medium | Stack | ★★★ |
| 402 | Remove K Digits | Medium | Monotonic Stack | ★★★★ |
| 2104 | Sum of Subarray Ranges | Medium | Mono Stack | ★★★ |

### Queue
| # | Problem | Difficulty | Pattern | Frequency |
|---|---------|-----------|---------|-----------|
| 232 | Implement Queue using Stacks | Easy | Design | ★★★★★ |
| 225 | Implement Stack using Queues | Easy | Design | ★★★★ |
| 933 | Number of Recent Calls | Easy | Queue | ★★★ |
| 994 | Rotting Oranges | Medium | BFS | ★★★★★ |
| 286 | Walls and Gates | Medium | Multi-BFS | ★★★★ |
| 649 | Dota2 Senate | Medium | Queue | ★★★ |
| 950 | Reveal Cards In Increasing Order | Medium | Queue | ★★★ |
| 362 | Design Hit Counter | Medium | Queue | ★★★★ |

### Deque
| # | Problem | Difficulty | Pattern | Frequency |
|---|---------|-----------|---------|-----------|
| 239 | Sliding Window Maximum | Hard | Monotonic Deque | ★★★★★ |
| 641 | Design Circular Deque | Medium | Design | ★★★ |
| 862 | Shortest Subarray with Sum ≥ K | Hard | Deque + Prefix | ★★★★ |
| 1425 | Constrained Subsequence Sum | Hard | DP + Deque | ★★★ |
| 1696 | Jump Game VI | Medium | DP + Deque | ★★★★ |

### Heap / Priority Queue
| # | Problem | Difficulty | Pattern | Frequency |
|---|---------|-----------|---------|-----------|
| 215 | Kth Largest Element | Medium | Heap / Quickselect | ★★★★★ |
| 347 | Top K Frequent Elements | Medium | Heap | ★★★★★ |
| 23 | Merge K Sorted Lists | Hard | Min Heap | ★★★★★ |
| 295 | Find Median from Data Stream | Hard | Two Heaps | ★★★★★ |
| 621 | Task Scheduler | Medium | Greedy + Heap | ★★★★★ |
| 973 | K Closest Points to Origin | Medium | Heap | ★★★★★ |
| 767 | Reorganize String | Medium | Greedy + Heap | ★★★★ |
| 502 | IPO | Hard | Two Heaps | ★★★★ |
| 480 | Sliding Window Median | Hard | Two Heaps | ★★★ |
| 703 | Kth Largest Element in a Stream | Easy | Min Heap | ★★★★ |
| 1046 | Last Stone Weight | Easy | Max Heap | ★★★ |
| 355 | Design Twitter | Medium | Heap + Design | ★★★ |
| 378 | Kth Smallest Element in Sorted Matrix | Medium | Min Heap | ★★★★ |
| 632 | Smallest Range Covering K Lists | Hard | Min Heap | ★★★ |
| 1642 | Furthest Building You Can Reach | Medium | Min Heap | ★★★★ |
| 1353 | Maximum Number of Events | Medium | Greedy + Heap | ★★★ |
| 692 | Top K Frequent Words | Medium | Heap | ★★★★ |
| 1851 | Min Interval to Include Each Query | Hard | Heap + Sort | ★★★ |

---

# Quick Revision Checklist

## Pattern Recognition Cheat Sheet

```
See "nearest/next greater/smaller" → MONOTONIC STACK
See "sliding window max/min"       → MONOTONIC DEQUE
See "top K / kth largest"          → HEAP (size k)
See "merge K sorted"               → MIN HEAP
See "median in stream"             → TWO HEAPS
See "balanced parentheses"         → STACK
See "BFS / shortest path"          → QUEUE
See "0-1 weight BFS"              → DEQUE (0-1 BFS)
See "evaluate expression"          → STACK (operand + operator)
See "undo/back"                    → STACK
See "schedule by priority"         → HEAP
See "process in order"             → QUEUE
```

## Complexity Summary

| Data Structure | Insert | Remove | Peek | Build | Space |
|---------------|--------|--------|------|-------|-------|
| Stack | $O(1)$ | $O(1)$ | $O(1)$ | $O(n)$ | $O(n)$ |
| Queue | $O(1)$ | $O(1)$ | $O(1)$ | $O(n)$ | $O(n)$ |
| Deque | $O(1)$ | $O(1)$ | $O(1)$ | $O(n)$ | $O(n)$ |
| Binary Heap | $O(\log n)$ | $O(\log n)$ | $O(1)$ | $O(n)$ | $O(n)$ |
| Monotonic Stack | $O(1)$ amort | $O(1)$ amort | $O(1)$ | $O(n)$ | $O(n)$ |
| Monotonic Deque | $O(1)$ amort | $O(1)$ amort | $O(1)$ | $O(n)$ | $O(k)$ |

## Key Gotchas for Interviews

| Gotcha | Details |
|--------|---------|
| C++ `priority_queue` is **max heap** by default | Use `greater<>` for min heap |
| `priority_queue` has no `decrease_key` | Use lazy deletion: push new entry, skip stale ones |
| `stack`/`queue` have no iterator | Can't iterate; if you need to, use `deque` or `vector` |
| Monotonic stack = $O(n)$ total | Each element pushed & popped **at most once** → amortized $O(1)$ |
| Heap build is $O(n)$, **not** $O(n \log n)$ | Common interview question — know the proof |
| `deque` random access is $O(1)$ | Unlike `list` which is $O(n)$ |
| Stack overflow with deep recursion | Convert recursive DFS to iterative with explicit stack |

## Contest Speed Tips

| Constraint | What to Reach For |
|-----------|-------------------|
| "next greater element" in $O(n)$ | Monotonic stack |
| Sliding window: max/min over window of size $k$ | Monotonic deque + `multiset` if you need both |
| Shortest path, 0-1 weights | 0-1 BFS with deque |
| Top-K anything | Heap of size K |
| Need median online | Two heaps |
| Merge K sorted streams | K-way merge with min heap |
| Expression parsing | Two stacks (operand + operator) or recursive descent |

---

> **Final Tip**: For FAANG interviews, the heap + greedy combination is extremely common (Task Scheduler, Reorganize String, IPO). For Codeforces 1600+, monotonic stack contribution technique (Sum of Subarray Minimums/Maximums) and 0-1 BFS are rating boosters. Master these patterns and you'll handle 80% of stack/queue/heap problems on sight.
