# 🔥 Recursion & Time Complexity — Complete Guide for CP & FAANG

> **Goal**: Codeforces Master | FAANG Mid-Senior SWE  
> **Last Updated**: April 2026

---

## 📚 Table of Contents
1. [Recursion Fundamentals](#recursion-fundamentals)
2. [Recurrence Relations](#recurrence-relations)
3. [Master Theorem](#master-theorem)
4. [Extended Master Theorem (Akra-Bazzi)](#extended-master-theorem-akra-bazzi)
5. [Substitution Method](#substitution-method)
6. [Recursion Tree Method](#recursion-tree-method)
7. [Common Recurrences Cheat Sheet](#common-recurrences-cheat-sheet)
8. [CP & FAANG Problem Examples](#cp--faang-problem-examples)
9. [Limitations & Pitfalls](#limitations--pitfalls)
10. [Quick Revision Checklist](#quick-revision-checklist)

---

## Recursion Fundamentals

### What is Recursion?
A function that calls itself with a **smaller subproblem** until it hits a **base case**.

```
Recursion = Base Case + Recursive Case (reducing toward base)
```

### Three Pillars
| Pillar | Description |
|--------|-------------|
| **Base Case** | Terminating condition — prevents infinite calls |
| **Recursive Case** | Break the problem into smaller subproblems |
| **Convergence** | Each recursive call must move toward the base case |

### Recursion Mental Model (Stack Frames)
```
factorial(4)
 └─ 4 * factorial(3)
         └─ 3 * factorial(2)
                 └─ 2 * factorial(1)
                         └─ return 1   ← base case
                    return 2 * 1 = 2
             return 3 * 2 = 6
      return 4 * 6 = 24
```
Every recursive call pushes a **stack frame**. Max depth = max stack frames = **O(depth)** space.

### Types of Recursion

| Type | Description | Example |
|------|-------------|---------|
| **Linear** | One recursive call per invocation | `factorial(n)` |
| **Binary/Tree** | Two recursive calls | `fib(n)`, merge sort |
| **Tail** | Recursive call is the **last** operation | Optimizable by compiler |
| **Indirect** | A → B → A | Mutual recursion |
| **Nested** | Argument itself is a recursive call | `f(f(n-1))` — Ackermann |

### Tail Recursion (Important for Interviews)
```cpp
// NOT tail recursive — multiplication happens AFTER return
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Tail recursive — result carried in accumulator
int factorial(int n, int acc = 1) {
    if (n <= 1) return acc;
    return factorial(n - 1, n * acc);  // last operation is the call itself
}
```
- Tail recursion can be optimized to **O(1) space** by compilers (tail-call optimization).
- C++ with `-O2` does this. Java/Python do **not** guarantee TCO.

---

## Recurrence Relations

A **recurrence relation** expresses $T(n)$ in terms of $T$ on smaller inputs.

### How to Write a Recurrence
1. Count work done **outside** recursive calls → $f(n)$
2. Count **how many** recursive calls → $a$
3. Size of each subproblem → $n/b$ (or $n - k$)

**General form:**

$$T(n) = a \cdot T\!\left(\frac{n}{b}\right) + f(n)$$

### Examples of Deriving Recurrences

| Algorithm | Recurrence | Why |
|-----------|-----------|-----|
| Binary Search | $T(n) = T(n/2) + O(1)$ | 1 call, half the input, O(1) comparison |
| Merge Sort | $T(n) = 2T(n/2) + O(n)$ | 2 calls, half each, O(n) merge |
| Naive Fibonacci | $T(n) = T(n-1) + T(n-2) + O(1)$ | 2 calls, subtract form |
| Strassen's | $T(n) = 7T(n/2) + O(n^2)$ | 7 subproblems, O(n²) combine |
| Karatsuba | $T(n) = 3T(n/2) + O(n)$ | 3 multiplications instead of 4 |
| Quick Select (avg) | $T(n) = T(n/2) + O(n)$ | 1 partition + scan |
| Towers of Hanoi | $T(n) = 2T(n-1) + O(1)$ | Move n-1, move 1, move n-1 |

---

## Master Theorem

### Standard Form

For recurrences of the form:

$$T(n) = a \cdot T\!\left(\frac{n}{b}\right) + \Theta(n^c \log^k n)$$

where $a \geq 1$, $b > 1$, $c \geq 0$, $k \geq 0$.

Compute the **critical exponent**: $\log_b a$

### The Three Cases

| Case | Condition | Result | Intuition |
|------|-----------|--------|-----------|
| **Case 1** (Heavy Leaves) | $c < \log_b a$ | $T(n) = \Theta(n^{\log_b a})$ | Leaves dominate — work grows as tree branches |
| **Case 2** (Balanced) | $c = \log_b a$ | $T(n) = \Theta(n^c \log^{k+1} n)$ | Every level contributes equally |
| **Case 3** (Heavy Root) | $c > \log_b a$ | $T(n) = \Theta(n^c \log^k n)$ | Root work dominates — recursion is cheap |

> **Case 3 regularity condition**: $a \cdot f(n/b) \leq \delta \cdot f(n)$ for some $\delta < 1$ and sufficiently large $n$. Almost always satisfied in practice.

### Step-by-Step Application

```
Given: T(n) = a·T(n/b) + Θ(n^c · log^k(n))

Step 1: Identify a, b, c, k
Step 2: Compute log_b(a)
Step 3: Compare c with log_b(a)
Step 4: Apply the matching case
```

### Worked Examples

---

#### Example 1: Merge Sort
$$T(n) = 2T(n/2) + \Theta(n)$$
- $a = 2, \; b = 2, \; c = 1, \; k = 0$
- $\log_b a = \log_2 2 = 1$
- $c = \log_b a = 1$ → **Case 2**
- $T(n) = \Theta(n^1 \cdot \log^{0+1} n) = \boxed{\Theta(n \log n)}$

---

#### Example 2: Binary Search
$$T(n) = T(n/2) + \Theta(1)$$
- $a = 1, \; b = 2, \; c = 0, \; k = 0$
- $\log_b a = \log_2 1 = 0$
- $c = \log_b a = 0$ → **Case 2**
- $T(n) = \Theta(n^0 \cdot \log^{0+1} n) = \boxed{\Theta(\log n)}$

---

#### Example 3: Strassen's Matrix Multiplication
$$T(n) = 7T(n/2) + \Theta(n^2)$$
- $a = 7, \; b = 2, \; c = 2$
- $\log_b a = \log_2 7 \approx 2.807$
- $c = 2 < 2.807 = \log_b a$ → **Case 1**
- $T(n) = \boxed{\Theta(n^{\log_2 7}) \approx \Theta(n^{2.807})}$

---

#### Example 4: Karatsuba Multiplication
$$T(n) = 3T(n/2) + \Theta(n)$$
- $a = 3, \; b = 2, \; c = 1$
- $\log_b a = \log_2 3 \approx 1.585$
- $c = 1 < 1.585$ → **Case 1**
- $T(n) = \boxed{\Theta(n^{\log_2 3}) \approx \Theta(n^{1.585})}$

---

#### Example 5: Some D&C Algorithm
$$T(n) = 3T(n/4) + \Theta(n^2)$$
- $a = 3, \; b = 4, \; c = 2$
- $\log_b a = \log_4 3 \approx 0.793$
- $c = 2 > 0.793$ → **Case 3**
- $T(n) = \boxed{\Theta(n^2)}$

---

#### Example 6: Case 2 with log factor
$$T(n) = 2T(n/2) + \Theta(n \log n)$$
- $a = 2, \; b = 2, \; c = 1, \; k = 1$
- $\log_b a = 1 = c$ → **Case 2**
- $T(n) = \Theta(n \cdot \log^{1+1} n) = \boxed{\Theta(n \log^2 n)}$

---

## Extended Master Theorem (Akra-Bazzi)

When the standard Master Theorem **doesn't apply** (unequal splits, multiple different subproblem sizes):

$$T(n) = \sum_{i=1}^{k} a_i \cdot T(b_i \cdot n) + f(n)$$

### Akra-Bazzi Method
1. Find $p$ such that $\sum_{i=1}^{k} a_i \cdot b_i^p = 1$
2. Then: $T(n) = \Theta\!\left(n^p \left(1 + \int_1^n \frac{f(u)}{u^{p+1}} \, du\right)\right)$

### Example: Unequal Split
$$T(n) = T(n/3) + T(2n/3) + O(n)$$
- Solve $\left(\frac{1}{3}\right)^p + \left(\frac{2}{3}\right)^p = 1$ → $p = 1$
- $\int_1^n \frac{u}{u^2} du = \ln n$
- $T(n) = \Theta(n(1 + \ln n)) = \boxed{\Theta(n \log n)}$

This is actually the **worst-case quicksort recurrence** — still $O(n \log n)$!

---

## Substitution Method

### When to Use
- When Master Theorem doesn't apply (subtract recurrences like $T(n) = 2T(n-1) + O(1)$)
- To prove tight bounds when you already **guess** the answer
- FAANG interviews to demonstrate mathematical reasoning

### Steps
1. **Guess** the form of the solution (e.g., $T(n) = O(n^2)$)
2. **Assume** it holds for smaller inputs: $T(k) \leq c \cdot k^2$ for all $k < n$
3. **Substitute** into the recurrence and prove $T(n) \leq c \cdot n^2$
4. **Verify** the base case

### Worked Example 1: Merge Sort (Upper Bound)

**Claim**: $T(n) = 2T(n/2) + n$ is $O(n \log n)$.

**Guess**: $T(n) \leq c \cdot n \log n$ for some constant $c > 0$.

**Inductive step**: Assume $T(k) \leq c \cdot k \log k$ for $k < n$.

$$T(n) = 2T(n/2) + n$$
$$\leq 2 \cdot c \cdot \frac{n}{2} \cdot \log\frac{n}{2} + n$$
$$= c \cdot n \cdot (\log n - 1) + n$$
$$= c \cdot n \log n - c \cdot n + n$$
$$\leq c \cdot n \log n \quad \text{(when } c \geq 1 \text{)}$$

**Base**: $T(1) = 1 \leq c \cdot 1 \cdot \log 1 = 0$? No! Fix: Start base at $T(2)$ or adjust constant. $\square$

### Worked Example 2: Subtract Recurrence

**Recurrence**: $T(n) = 2T(n - 1) + 1, \quad T(0) = 1$

**Guess**: $T(n) = O(2^n)$. Assume $T(k) \leq c \cdot 2^k$ for $k < n$.

$$T(n) = 2T(n-1) + 1 \leq 2 \cdot c \cdot 2^{n-1} + 1 = c \cdot 2^n + 1$$

This **doesn't** work directly — we get $c \cdot 2^n + 1$, not $\leq c \cdot 2^n$.

**Fix — subtract a lower-order term**: Guess $T(n) \leq c \cdot 2^n - 1$.

$$T(n) = 2T(n-1) + 1 \leq 2(c \cdot 2^{n-1} - 1) + 1 = c \cdot 2^n - 2 + 1 = c \cdot 2^n - 1 \; ✓$$

**Base**: $T(0) = 1 \leq c \cdot 2^0 - 1 = c - 1$ → works for $c \geq 2$. $\square$

> **Pro tip**: When substitution is off by an additive constant, subtract a lower-order term from your guess. This is a classic trick.

### Worked Example 3: Fibonacci

**Recurrence**: $T(n) = T(n-1) + T(n-2) + O(1)$

**Guess**: $T(n) = O(\phi^n)$ where $\phi = \frac{1+\sqrt{5}}{2} \approx 1.618$ (golden ratio).

$$T(n) = T(n-1) + T(n-2) \leq c \cdot \phi^{n-1} + c \cdot \phi^{n-2}$$
$$= c \cdot \phi^{n-2}(\phi + 1) = c \cdot \phi^{n-2} \cdot \phi^2 = c \cdot \phi^n \; ✓$$

Uses the identity: $\phi^2 = \phi + 1$. $\square$

---

## Recursion Tree Method

### When to Use
- Best for **building intuition** and generating a guess for substitution
- Great for **visual thinkers** and explaining in interviews
- Works on any recurrence (divide-and-conquer or subtract)

### Steps
1. **Draw** the tree: each node = work done at that call (excluding recursive calls)
2. **Compute** total work per level
3. **Count** the number of levels
4. **Sum** across all levels → total work

### Template
```
Level 0:           f(n)                    → work at root
Level 1:      f(n/b)  f(n/b) ... (a times) → a · f(n/b)
Level 2:      (a² nodes of size n/b²)       → a² · f(n/b²)
  ...
Level i:      aⁱ nodes of size n/bⁱ        → aⁱ · f(n/bⁱ)
  ...
Level L:      a^L leaves (n/b^L = 1 → L = log_b(n))
```

**Total**:

$$T(n) = \sum_{i=0}^{\log_b n} a^i \cdot f\!\left(\frac{n}{b^i}\right)$$

---

### Example 1: Merge Sort — $T(n) = 2T(n/2) + n$

```
Level 0:               n                    = n
                      / \
Level 1:          n/2     n/2               = n
                 / \     / \
Level 2:      n/4 n/4 n/4 n/4              = n
                  ...
Level k:    2^k nodes × (n/2^k)             = n
                  ...
Level log₂n: n leaves × O(1)               = n
```

- **Levels**: $\log_2 n$
- **Work per level**: $n$ (constant across levels!)
- **Total**: $n \times \log_2 n = \boxed{\Theta(n \log n)}$

---

### Example 2: $T(n) = 3T(n/4) + cn^2$

```
Level 0:               cn²                        = cn²
                     / | \
Level 1:      3 × c(n/4)²                         = (3/16) cn²
                   ...
Level i:     3ⁱ × c(n/4ⁱ)²                       = (3/16)ⁱ cn²
                   ...
Level log₄n: 3^(log₄n) leaves                     = n^(log₄3) 
```

- Sum: $cn^2 \sum_{i=0}^{\log_4 n} \left(\frac{3}{16}\right)^i$
- Geometric series with ratio $3/16 < 1$ → converges to constant
- **Total**: $\boxed{\Theta(n^2)}$ — root dominates (Case 3 of Master Theorem)

---

### Example 3: $T(n) = T(n/3) + T(2n/3) + n$ (Unequal split)

```
Level 0:               n                          = n
                      / \
Level 1:          n/3     2n/3                     = n
                 / \     / \
Level 2:     n/9 2n/9 2n/9 4n/9                   = n
                    ...
```

- Each level sums to **exactly** $n$
- Shortest path: $n → n/3 → n/9 → ...$ ends at depth $\log_3 n$
- Longest path: $n → 2n/3 → 4n/9 → ...$ ends at depth $\log_{3/2} n$
- **Total**: between $n \log_3 n$ and $n \log_{3/2} n$ → $\boxed{\Theta(n \log n)}$

---

### Example 4: $T(n) = 2T(n-1) + 1$ (Exponential — subtract recurrence)

```
Level 0:             1                    = 1 = 2⁰
                    / \
Level 1:          1     1                 = 2 = 2¹
                / \   / \
Level 2:       1  1  1  1                = 4 = 2²
                 ...
Level n:      2ⁿ leaves                  = 2ⁿ
```

- **Levels**: $n$
- **Work at level i**: $2^i$
- **Total**: $\sum_{i=0}^{n} 2^i = 2^{n+1} - 1 = \boxed{\Theta(2^n)}$

---

### Example 5: $T(n) = T(n-1) + n$ (Decreasing with linear work)

```
Level 0:     n
Level 1:     n-1
Level 2:     n-2
  ...
Level n-1:   1
```

- **Total**: $n + (n-1) + (n-2) + \cdots + 1 = \frac{n(n+1)}{2} = \boxed{\Theta(n^2)}$

Think: selection sort, bubble sort inner recursion.

---

### Example 6: $T(n) = 2T(n/2) + n^2$

```
Level 0:               n²                   = n²
                      / \
Level 1:          2×(n/2)² = n²/2           = n²/2
Level 2:          4×(n/4)² = n²/4           = n²/4
  ...
Level i:          n²/2ⁱ
```

- Geometric series: $n^2(1 + 1/2 + 1/4 + ...) = 2n^2$
- **Total**: $\boxed{\Theta(n^2)}$ — root dominates

---

## Common Recurrences Cheat Sheet

| Recurrence | Solution | Algorithm/Pattern |
|---|---|---|
| $T(n) = T(n/2) + O(1)$ | $O(\log n)$ | Binary search |
| $T(n) = T(n-1) + O(1)$ | $O(n)$ | Linear scan / factorial |
| $T(n) = T(n-1) + O(n)$ | $O(n^2)$ | Selection sort |
| $T(n) = 2T(n/2) + O(1)$ | $O(n)$ | Tree traversal |
| $T(n) = 2T(n/2) + O(n)$ | $O(n \log n)$ | Merge sort |
| $T(n) = 2T(n/2) + O(n^2)$ | $O(n^2)$ | — |
| $T(n) = 2T(n/2) + O(n \log n)$ | $O(n \log^2 n)$ | — |
| $T(n) = T(n/2) + O(n)$ | $O(n)$ | Quick select (avg) |
| $T(n) = 2T(n-1) + O(1)$ | $O(2^n)$ | Towers of Hanoi / subsets |
| $T(n) = T(n-1) + T(n-2)$ | $O(\phi^n) \approx O(1.618^n)$ | Naive Fibonacci |
| $T(n) = 3T(n/2) + O(n)$ | $O(n^{\log_2 3}) \approx O(n^{1.585})$ | Karatsuba |
| $T(n) = 7T(n/2) + O(n^2)$ | $O(n^{\log_2 7}) \approx O(n^{2.807})$ | Strassen |
| $T(n) = 4T(n/2) + O(n)$ | $O(n^2)$ | — |
| $T(n) = 4T(n/2) + O(n^2)$ | $O(n^2 \log n)$ | — |
| $T(n) = T(\sqrt{n}) + O(1)$ | $O(\log \log n)$ | Van Emde Boas / nested sqrt |

---

## CP & FAANG Problem Examples

### Problem 1: Power Function — $x^n$

```cpp
// Naive: O(n)
int power(int x, int n) {
    if (n == 0) return 1;
    return x * power(x, n - 1);   // T(n) = T(n-1) + O(1) → O(n)
}

// Fast (Binary Exponentiation): O(log n)
long long power(long long x, long long n, long long mod) {
    if (n == 0) return 1;
    long long half = power(x, n / 2, mod);  // T(n) = T(n/2) + O(1) → O(log n)
    half = (half * half) % mod;
    if (n & 1) half = (half * x) % mod;
    return half;
}
```
- **Recurrence**: $T(n) = T(n/2) + O(1)$ → Master Theorem Case 2 → $O(\log n)$
- **CP Usage**: Modular inverse, matrix exponentiation, Fermat's little theorem

---

### Problem 2: Generate All Subsets (Power Set)

```cpp
void subsets(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& res) {
    if (i == nums.size()) {
        res.push_back(curr);   // O(n) to copy
        return;
    }
    subsets(nums, i + 1, curr, res);          // exclude
    curr.push_back(nums[i]);
    subsets(nums, i + 1, curr, res);          // include
    curr.pop_back();
}
```
- **Recurrence**: $T(n) = 2T(n-1) + O(1)$ → $O(2^n)$ calls
- Total with copying: $O(n \cdot 2^n)$ (each of $2^n$ subsets has avg size $n/2$)

---

### Problem 3: Generate All Permutations

```cpp
void permute(vector<int>& nums, int l, int r) {
    if (l == r) { print(nums); return; }
    for (int i = l; i <= r; i++) {
        swap(nums[l], nums[i]);
        permute(nums, l + 1, r);
        swap(nums[l], nums[i]);
    }
}
```
- **Recurrence**: $T(n) = n \cdot T(n-1) + O(n)$
- $T(n) = n \cdot (n-1) \cdot (n-2) \cdots 1 = O(n!)$
- Total with printing: $O(n \cdot n!)$

---

### Problem 4: Merge Sort

```cpp
void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);       // T(n/2)
    mergeSort(arr, mid + 1, r);   // T(n/2)
    merge(arr, l, mid, r);        // O(n)
}
```
- **Recurrence**: $T(n) = 2T(n/2) + O(n)$ → $\boxed{O(n \log n)}$

---

### Problem 5: Quick Sort (Average & Worst)

| Case | Recurrence | Complexity |
|------|-----------|------------|
| Average | $T(n) = 2T(n/2) + O(n)$ | $O(n \log n)$ |
| Worst (sorted input) | $T(n) = T(n-1) + O(n)$ | $O(n^2)$ |

---

### Problem 6: N-Queens (Backtracking)

```cpp
void solve(int col, int n, vector<int>& board) {
    if (col == n) { count++; return; }
    for (int row = 0; row < n; row++) {
        if (isSafe(board, row, col)) {
            board[col] = row;
            solve(col + 1, n, board);
        }
    }
}
```
- **Upper bound**: $O(n!)$ — at level $i$, at most $n - i$ choices
- **Tighter**: $O(n!)$ with backtracking prunes, but worst case still factorial

---

### Problem 7: Tower of Hanoi

```cpp
void hanoi(int n, char from, char to, char aux) {
    if (n == 0) return;
    hanoi(n - 1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << "\n";
    hanoi(n - 1, aux, to, from);
}
```
- **Recurrence**: $T(n) = 2T(n-1) + 1$
- **Solution**: $T(n) = 2^n - 1 = \boxed{\Theta(2^n)}$

---

### Problem 8: Matrix Chain Multiplication (DP on Intervals)

```cpp
int mcm(int i, int j) {
    if (i >= j) return 0;
    int res = INT_MAX;
    for (int k = i; k < j; k++) {
        res = min(res, mcm(i, k) + mcm(k + 1, j) + cost(i, k, j));
    }
    return res;
}
```
- Without memoization: $T(n) = \sum_{k=1}^{n-1} [T(k) + T(n-k)] + O(n)$ → $\boxed{O(2^n)}$ (Catalan number growth)
- With memoization: $O(n^2)$ subproblems × $O(n)$ each = $\boxed{O(n^3)}$

---

### Problem 9: Segment Tree Build

```cpp
void build(int node, int start, int end, vector<int>& arr) {
    if (start == end) { tree[node] = arr[start]; return; }
    int mid = (start + end) / 2;
    build(2*node, start, mid, arr);
    build(2*node+1, mid+1, end, arr);
    tree[node] = tree[2*node] + tree[2*node+1];
}
```
- **Recurrence**: $T(n) = 2T(n/2) + O(1)$ → $\boxed{O(n)}$ (Master: Case 1)

---

### Problem 10: Segment Tree Query

```cpp
int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;        // out of range
    if (l <= start && end <= r) return tree[node]; // fully in range
    int mid = (start + end) / 2;
    return query(2*node, start, mid, l, r) + query(2*node+1, mid+1, end, l, r);
}
```
- At each level, at most **2 partial nodes** are explored
- **Total**: $O(\log n)$ per query

---

### Problem 11: DFS/BFS on Graph

```cpp
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
}
```
- Each vertex visited once, each edge examined once → $\boxed{O(V + E)}$
- Recursion depth ≤ $V$ (path graph worst case)

---

### Problem 12: $T(n) = T(\sqrt{n}) + O(1)$ (Van Emde Boas style)

Let $m = \log n$. Then $T(2^m) = T(2^{m/2}) + O(1)$.

Substitution $S(m) = T(2^m)$: $S(m) = S(m/2) + O(1)$ → $O(\log m) = \boxed{O(\log \log n)}$

---

## Limitations & Pitfalls

### Master Theorem Limitations

| Limitation | Example | What to Use Instead |
|------------|---------|-------------------|
| **Only divide-by recurrences** | $T(n) = 2T(n-1) + 1$ — subtract, not divide | Substitution or unrolling |
| **Polynomial gap required** | $T(n) = 2T(n/2) + \frac{n}{\log n}$ — not $\Theta(n^c \log^k n)$ | Akra-Bazzi or recursion tree |
| **Equal-sized subproblems** | $T(n) = T(n/3) + T(2n/3) + n$ | Akra-Bazzi or recursion tree |
| **Non-constant a, b** | $T(n) = n \cdot T(n-1)$ (variable branching) | Direct analysis |
| **Floor/ceiling issues** | In theory problematic, in practice ignorable | — |
| **Negative f(n)** | $f(n)$ must be asymptotically positive | — |

### Substitution Method Limitations

| Limitation | Mitigation |
|------------|-----------|
| Need a good initial guess | Use recursion tree to generate guess |
| Proving tight bounds is hard | May need to subtract lower-order terms |
| Off-by-constant errors | Adjust the hypothesis form |
| Only proves O/Ω, not Θ directly | Prove both upper and lower bounds separately |

### Recursion Tree Limitations

| Limitation | Mitigation |
|------------|-----------|
| Informal — not a rigorous proof | Use it to guess, then verify with substitution |
| Hard with uneven splits | Draw both shortest and longest paths |
| Can be error-prone with complicated cost functions | Use geometric series analysis |

### General Pitfalls in CP

| Pitfall | Reality |
|---------|---------|
| Forgetting **memoization** changes complexity | Naive Fib is $O(\phi^n)$, memoized is $O(n)$ |
| Confusing **number of calls** with **total work** | Each call may do $O(n)$ work, not $O(1)$ |
| Ignoring **space complexity** | Recursion depth $d$ → $O(d)$ stack space |
| Not accounting for **output size** | Generating all subsets is $\Omega(2^n)$ regardless |
| Stack overflow in practice | Default stack is ~1-8 MB. Use iterative or increase stack: `ulimit -s unlimited` |

---

## Quick Revision Checklist

### Identifying the Method

```
Is it T(n) = aT(n/b) + f(n)?
  ├── YES → Is f(n) = Θ(n^c · log^k(n))?
  │           ├── YES → Use MASTER THEOREM
  │           └── NO  → Use RECURSION TREE or AKRA-BAZZI
  │
  └── NO → Is it a subtract recurrence T(n) = aT(n-c) + f(n)?
             ├── YES → Use SUBSTITUTION METHOD or UNROLLING
             └── NO  → Use RECURSION TREE (most general)
```

### Speed Lookup for Contests

| If you see this pattern... | The complexity is... |
|---|---|
| Halving each time, O(1) per call | $O(\log n)$ |
| Halving each time, O(n) per call | $O(n)$ (geometric sum) |
| Two halves + linear merge | $O(n \log n)$ |
| Loop + recurse on $n-1$ | $O(n^2)$ |
| Two branches: $n-1$ each | $O(2^n)$ |
| $n$ branches: $n-1$ each | $O(n!)$ |
| $\sqrt{n}$ each time, O(1) per call | $O(\log \log n)$ |
| Divide into 4 of size $n/2$, linear merge | $O(n^2)$ |

### Complexity Hierarchy (for constraint analysis)

```
O(1) < O(log log n) < O(log n) < O(√n) < O(n) < O(n log n) < O(n√n)
< O(n²) < O(n² log n) < O(n³) < O(2^n) < O(n!) < O(n^n)
```

### Contest Constraint → Expected Complexity

| n ≤ | Expected TC | Typical Approach |
|-----|------------|-----------------|
| 10 | $O(n!)$ or $O(n \cdot 2^n)$ | Brute force, permutations |
| 20 | $O(2^n)$ | Bitmask/backtracking |
| 25 | $O(2^{n/2})$ | Meet in the middle |
| 100 | $O(n^3)$ or $O(n^4)$ | DP, Floyd-Warshall |
| 500 | $O(n^3)$ | DP, matrix |
| 5000 | $O(n^2)$ | DP, greedy |
| $10^5$ | $O(n \log n)$ or $O(n \sqrt{n})$ | Sort, segment tree, sqrt decomp |
| $10^6$ | $O(n)$ or $O(n \log n)$ | Linear scan, two pointers |
| $10^8$ | $O(n)$ | Simple loop |
| $10^{12}$+ | $O(\sqrt{n})$ or $O(\log n)$ | Math, binary search, matrix exp |

---

> **Key Insight**: In contests, you almost never formally prove time complexity. You look at constraints, match to the expected complexity band above, then verify your recursion fits. In interviews, be ready to write the recurrence and solve it step-by-step using Master Theorem or substitution.
