# Prefix Sum — Complete Reference

> **Target:** Codeforces Candidate Master (1900+) & FAANG Senior SWE+ Interviews

---

## Table of Contents

1. [Core Concept](#1-core-concept)
2. [1D Prefix Sum](#2-1d-prefix-sum)
3. [2D Prefix Sum](#3-2d-prefix-sum)
4. [Prefix XOR](#4-prefix-xor)
5. [Prefix Product](#5-prefix-product)
6. [Difference Array (Inverse of Prefix Sum)](#6-difference-array-inverse-of-prefix-sum)
7. [2D Difference Array](#7-2d-difference-array)
8. [Prefix Sum + Hashing (Subarray Sum Patterns)](#8-prefix-sum--hashing-subarray-sum-patterns)
9. [Prefix Sum on Trees](#9-prefix-sum-on-trees)
10. [Prefix Sum with Modular Arithmetic](#10-prefix-sum-with-modular-arithmetic)
11. [Prefix Sum with Coordinate Compression](#11-prefix-sum-with-coordinate-compression)
12. [Sliding Window vs Prefix Sum](#12-sliding-window-vs-prefix-sum)
13. [Advanced: Prefix Sum + Binary Search](#13-advanced-prefix-sum--binary-search)
14. [Advanced: Persistent Prefix Structures](#14-advanced-persistent-prefix-structures)
15. [Common Pitfalls & Edge Cases](#15-common-pitfalls--edge-cases)
16. [Complexity Cheatsheet](#16-complexity-cheatsheet)
17. [Problem Set (LeetCode + Codeforces)](#17-problem-set)

---

## 1. Core Concept

**Prefix sum** converts an array into a cumulative-sum array so that **any subarray sum** can be answered in $O(1)$ after $O(n)$ preprocessing.

$$\text{prefix}[i] = \sum_{j=0}^{i-1} a[j]$$

arr = a0, a1, a2, a3, a4, a5

prefix sum arr = a0, a0 + a1, a0 + a1 + a2, a0 + a1 + a2 + a3, a0 + a1 + a2 + a3 + a4

**Range query:**

$$\text{sum}(l, r) = \text{prefix}[r+1] - \text{prefix}[l]$$

### Why it matters

| Context | Usage |
|---|---|
| **CP (CF 1400–1900+)** | Subarray sums, difference arrays, 2D grids, XOR queries, tree paths |
| **FAANG Interviews** | Subarray sum == k, max subarray with constraint, matrix region sums, equilibrium index |

---

## 2. 1D Prefix Sum

### Build

```cpp
// 0-indexed prefix sum (prefix[0] = 0, prefix has n+1 elements)
vector<long long> prefix(n + 1, 0);
for (int i = 0; i < n; i++)
    prefix[i + 1] = prefix[i] + a[i];
```

### Query: sum of `a[l..r]` (inclusive)

```cpp
long long rangeSum = prefix[r + 1] - prefix[l];
```

### Full Template

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n), prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        prefix[i + 1] = prefix[i] + a[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r; // 1-indexed input
        l--; r--;      // convert to 0-indexed
        cout << prefix[r + 1] - prefix[l] << "\n";
    }
}
```

### Suffix Sum (reverse direction)

```cpp
vector<long long> suffix(n + 1, 0);
for (int i = n - 1; i >= 0; i--)
    suffix[i] = suffix[i + 1] + a[i];
// sum(l..r) = suffix[l] - suffix[r+1]
```

**Time:** $O(n)$ build, $O(1)$ query | **Space:** $O(n)$

---

## 3. 2D Prefix Sum

For an $m \times n$ matrix, precompute:

$$\text{prefix}[i][j] = \sum_{r=0}^{i-1}\sum_{c=0}^{j-1} \text{mat}[r][c]$$

### Build (Inclusion-Exclusion)

```cpp
vector<vector<long long>> prefix(m + 1, vector<long long>(n + 1, 0));
for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
        prefix[i][j] = mat[i-1][j-1]
                      + prefix[i-1][j]
                      + prefix[i][j-1]
                      - prefix[i-1][j-1];
```

### Query: sum of submatrix `(r1,c1)` to `(r2,c2)` (0-indexed)

```cpp
long long regionSum = prefix[r2+1][c2+1]
                    - prefix[r1][c2+1]
                    - prefix[r2+1][c1]
                    + prefix[r1][c1];
```

### Visualization

```
+---+-------+---+
|   |       |   |
+---A=======B---+     Region sum = prefix[D] - prefix[B_row][D_col]
|   ‖       ‖   |                - prefix[D_row][A_col] + prefix[A]
|   ‖ query ‖   |
+---C=======D---+     (Inclusion-Exclusion Principle)
|   |       |   |
+---+-------+---+
```

**Time:** $O(mn)$ build, $O(1)$ query | **Space:** $O(mn)$

---

## 4. Prefix XOR

XOR is its own inverse: $a \oplus a = 0$. This makes prefix XOR work identically to prefix sum.

$$\text{prefixXor}[i] = a[0] \oplus a[1] \oplus \cdots \oplus a[i-1]$$

### Range XOR query

$$\text{xor}(l, r) = \text{prefixXor}[r+1] \oplus \text{prefixXor}[l]$$

```cpp
vector<int> px(n + 1, 0);
for (int i = 0; i < n; i++)
    px[i + 1] = px[i] ^ a[i];

// XOR of a[l..r]
int rangeXor = px[r + 1] ^ px[l];
```

### Key Trick: Subarray with XOR == k

Use a hashmap counting prefix XOR frequencies (analogous to subarray sum == k):

```cpp
int countSubarraysXorK(vector<int>& a, int k) {
    unordered_map<int, int> freq;
    freq[0] = 1;
    int xr = 0, count = 0;
    for (int x : a) {
        xr ^= x;
        count += freq[xr ^ k]; // xr ^ (xr ^ k) = k
        freq[xr]++;
    }
    return count;
}
```

---

## 5. Prefix Product

Useful when all elements are non-zero (or you handle zeros separately).

```cpp
vector<long long> prefProd(n + 1, 1);
for (int i = 0; i < n; i++)
    prefProd[i + 1] = prefProd[i] * a[i];

// Product of a[l..r]
long long rangeProd = prefProd[r + 1] / prefProd[l];
```

### Handling Zeros (FAANG pattern — LC 238)

**Product of Array Except Self** — build left product and right product arrays:

```cpp
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);
    // Left pass
    int left = 1;
    for (int i = 0; i < n; i++) {
        ans[i] = left;
        left *= nums[i];
    }
    // Right pass
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] *= right;
        right *= nums[i];
    }
    return ans;
}
```

---

## 6. Difference Array (Inverse of Prefix Sum)

When you have **multiple range-update queries** and a **single final read**, use a difference array. Applying prefix sum on the difference array reconstructs the actual array.

### Concept

- To add $v$ to all elements in $[l, r]$:
  - `diff[l] += v`
  - `diff[r + 1] -= v`
- Reconstruct: take prefix sum of `diff[]`

```cpp
vector<long long> diff(n + 1, 0); // size n+1 for boundary

// Range update: add v to [l, r]
void rangeAdd(vector<long long>& diff, int l, int r, long long v) {
    diff[l] += v;
    if (r + 1 < (int)diff.size()) diff[r + 1] -= v;
}

// Reconstruct actual array
void reconstruct(vector<long long>& diff) {
    for (int i = 1; i < (int)diff.size(); i++)
        diff[i] += diff[i - 1];
}
```

### When to Use

- $Q$ range updates + 1 final snapshot → $O(n + Q)$ instead of $O(nQ)$
- **Codeforces:** Very common in 1400–1800 problems
- **FAANG:** "Corporate Flight Bookings" (LC 1109), "Car Pooling" (LC 1094)

---

## 7. 2D Difference Array

Extends difference arrays to matrices. Add $v$ to submatrix $(r_1,c_1)$ to $(r_2,c_2)$:

```cpp
// diff is (m+1) x (n+1), initialized to 0
diff[r1][c1]     += v;
diff[r1][c2+1]   -= v;
diff[r2+1][c1]   -= v;
diff[r2+1][c2+1] += v;
```

Reconstruct by taking 2D prefix sum on `diff`.

```cpp
// Reconstruct
for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
        if (i > 0) diff[i][j] += diff[i-1][j];
        if (j > 0) diff[i][j] += diff[i][j-1];
        if (i > 0 && j > 0) diff[i][j] -= diff[i-1][j-1];
    }
```

**Time:** $O(1)$ per update, $O(mn)$ to reconstruct

---

## 8. Prefix Sum + Hashing (Subarray Sum Patterns)

> **This is the single most important prefix sum pattern for FAANG interviews.**

### Pattern: Count/Find subarrays where `sum == k`

If `prefix[j] - prefix[i] == k`, then `prefix[i] == prefix[j] - k`.

```cpp
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    freq[0] = 1; // empty prefix
    int sum = 0, count = 0;
    for (int x : nums) {
        sum += x;
        count += freq[sum - k];
        freq[sum]++;
    }
    return count;
}
```

### Variations of this pattern

| Variant | Key Insight | Hashmap stores |
|---|---|---|
| **Subarray sum == k** | `prefix[j] - prefix[i] == k` | `freq[prefix_sum]` |
| **Subarray sum divisible by k** | `prefix[j] % k == prefix[i] % k` | `freq[prefix_sum % k]` (handle negative mod!) |
| **Longest subarray sum == k** | Want max `j - i` where `prefix[j] - prefix[i] == k` | First occurrence index of each prefix sum |
| **# subarrays with equal 0s and 1s** | Replace 0 → -1, then subarray sum == 0 | `freq[prefix_sum]` |
| **# subarrays with equal x and y** | Replace x → +1, y → -1, sum == 0 | `freq[prefix_sum]` |
| **Max subarray len with sum ≤ k** | Prefix sum + binary search or sliding window | Sorted prefix sums |

### Handling Negative Modulo (C++ specific!)

```cpp
// In C++, -7 % 3 == -1 (not 2). Fix:
int mod(int a, int m) {
    return ((a % m) + m) % m;
}
```

---

## 9. Prefix Sum on Trees

### Technique: Edge/Node Weighted Tree Path Queries

Use **Euler Tour + Prefix Sum** or **LCA + prefix sums on paths**.

### Node-weighted path sum with LCA

```
dist(u) = prefix sum from root to u
path_sum(u, v) = dist(u) + dist(v) - 2 * dist(LCA(u, v)) + weight(LCA(u, v))
```

### Subtree sum with Euler Tour

```cpp
// Flatten tree via DFS, record tin[u] and tout[u]
// Subtree of u = range [tin[u], tout[u]] in Euler order
// Use 1D prefix sum on the flattened array

int timer = 0;
vector<int> tin(n), tout(n), euler_order;

void dfs(int u, int parent) {
    tin[u] = timer++;
    euler_order.push_back(val[u]);
    for (int v : adj[u]) {
        if (v != parent) dfs(v, u);
    }
    tout[u] = timer - 1;
}

// After DFS: subtree sum of u = prefix[tout[u]+1] - prefix[tin[u]]
```

### Difference Array on Tree Paths (CF Classic: 1400–1900)

Add $+1$ to all edges on path $u \to v$:

```cpp
// diff[u]++, diff[v]++, diff[LCA(u,v)] -= 2;
// Then DFS to compute subtree sums → each node stores the sum for its parent edge
```

---

## 10. Prefix Sum with Modular Arithmetic

### Counting subarrays divisible by $k$

Two prefix sums with the same remainder mod $k$ define a subarray whose sum is divisible by $k$.

```cpp
int subarraysDivByK(vector<int>& nums, int k) {
    vector<int> freq(k, 0);
    freq[0] = 1;
    int sum = 0, count = 0;
    for (int x : nums) {
        sum = ((sum + x) % k + k) % k; // handle negative
        count += freq[sum];
        freq[sum]++;
    }
    return count;
}
```

### Picking $\binom{freq[r]}{2}$ pairs (alternate counting)

If $freq[r]$ prefix sums share remainder $r$, then $\binom{freq[r]}{2}$ subarrays have sum divisible by $k$.

---

## 11. Prefix Sum with Coordinate Compression

When the value space is huge but the number of events is small, compress coordinates first, then apply prefix sums.

```cpp
// Example: count overlapping intervals
vector<int> coords; // collect all l, r+1
sort(coords.begin(), coords.end());
coords.erase(unique(coords.begin(), coords.end()), coords.end());

auto getIdx = [&](int x) {
    return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
};

vector<int> diff(coords.size() + 1, 0);
for (auto& [l, r] : intervals) {
    diff[getIdx(l)]++;
    diff[getIdx(r + 1)]--;
}
// prefix sum on diff to get overlap counts
```

---

## 12. Sliding Window vs Prefix Sum

| Feature | Prefix Sum | Sliding Window |
|---|---|---|
| **Works with negatives?** | Yes | No (for sum ≤ k type) |
| **Range sum query** | $O(1)$ per query | Recompute needed |
| **Max/Min subarray of fixed size** | Both work | Slightly faster |
| **Subarray sum == k (with negatives)** | Prefix + hashmap | Cannot |
| **Max subarray sum ≤ k** | Prefix + ordered set / binary search | Only if all positive |
| **Space** | $O(n)$ | $O(1)$ |

### Decision Rule

- **All positives + constraint on sum** → Sliding window (simpler)
- **Has negatives + exact sum condition** → Prefix sum + hashmap
- **Multiple range queries** → Prefix sum
- **Range updates** → Difference array

---

## 13. Advanced: Prefix Sum + Binary Search

### Maximum subarray sum ≤ k

```cpp
int maxSumSubarrayLeK(vector<int>& nums, int k) {
    set<int> prefixSet;
    prefixSet.insert(0);
    int sum = 0, ans = INT_MIN;
    for (int x : nums) {
        sum += x;
        // Need prefix[i] >= sum - k → lower_bound(sum - k)
        auto it = prefixSet.lower_bound(sum - k);
        if (it != prefixSet.end())
            ans = max(ans, sum - *it);
        prefixSet.insert(sum);
    }
    return ans;
}
// Time: O(n log n)
```

### Binary search on prefix sum (sorted / non-negative arrays)

When array has all non-negative values, prefix sum is **monotonically non-decreasing** → binary search for targets.

```cpp
// Find smallest subarray with sum >= target (all positive)
// Use prefix sum + binary search: for each j, find smallest i s.t. prefix[j] - prefix[i] >= target
// → prefix[i] <= prefix[j] - target → upper_bound
```

---

## 14. Advanced: Persistent Prefix Structures

### Prefix Sum of Frequencies (for range mode / range count)

For offline queries: build prefix frequency arrays. For each distinct value $v$:

$$\text{cnt}[v][i] = \text{number of occurrences of } v \text{ in } a[0..i-1]$$

Count of $v$ in $[l, r] = cnt[v][r+1] - cnt[v][l]$

For large value ranges, use **merge sort tree** or **persistent segment tree** (CF 1900+ territory).

### Prefix Sum + Fenwick Tree (BIT)

When you need **dynamic prefix sums** (point update + prefix query):

```cpp
struct BIT {
    int n;
    vector<long long> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {}

    void update(int i, long long delta) { // 1-indexed
        for (++i; i <= n; i += i & (-i))
            tree[i] += delta;
    }

    long long query(int i) { // prefix sum [0, i]
        long long s = 0;
        for (++i; i > 0; i -= i & (-i))
            s += tree[i];
        return s;
    }

    long long query(int l, int r) { // range sum [l, r]
        return query(r) - (l > 0 ? query(l - 1) : 0);
    }
};
```

---

## 15. Common Pitfalls & Edge Cases

| Pitfall | Fix |
|---|---|
| **Off-by-one in prefix indexing** | Use size `n+1`, `prefix[0] = 0`, query = `prefix[r+1] - prefix[l]` |
| **Integer overflow** | Use `long long` — sum of $10^5$ elements each $10^9$ = $10^{14}$ |
| **Negative mod in C++** | `((x % m) + m) % m` |
| **Forgetting `freq[0] = 1`** | The empty prefix is a valid prefix sum of 0 |
| **2D prefix off-by-one** | Draw it out. Prefix matrix is `(m+1) x (n+1)` |
| **Difference array boundary** | `diff[r+1] -= v` — make sure `r+1 < size` or allocate `n+1` |
| **Floating point prefix sums** | Accumulation error — use integer math or Kahan summation |

---

## 16. Complexity Cheatsheet

| Technique | Build | Query/Update | Space |
|---|---|---|---|
| 1D Prefix Sum | $O(n)$ | $O(1)$ | $O(n)$ |
| 2D Prefix Sum | $O(mn)$ | $O(1)$ | $O(mn)$ |
| Difference Array | $O(n)$ | $O(1)$ update, $O(n)$ reconstruct | $O(n)$ |
| 2D Difference Array | $O(mn)$ | $O(1)$ update, $O(mn)$ reconstruct | $O(mn)$ |
| Prefix + Hashmap | $O(n)$ | $O(1)$ amortized | $O(n)$ |
| Prefix + Sorted Set | $O(n \log n)$ | $O(\log n)$ | $O(n)$ |
| Fenwick Tree (BIT) | $O(n \log n)$ | $O(\log n)$ | $O(n)$ |

---

## 17. Problem Set

### Tier 1: Foundation (Easy — build intuition)

| # | Problem | Platform | Key Technique | Difficulty |
|---|---|---|---|---|
| 1 | [Running Sum of 1D Array](https://leetcode.com/problems/running-sum-of-1d-array/) | LC 1480 | Basic prefix sum | Easy |
| 2 | [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/) | LC 303 | 1D prefix sum | Easy |
| 3 | [Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/) | LC 304 | 2D prefix sum | Medium |
| 4 | [Find Pivot Index](https://leetcode.com/problems/find-pivot-index/) | LC 724 | Left sum == right sum | Easy |
| 5 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | LC 238 | Prefix/suffix product | Medium |

### Tier 2: Prefix + Hashing (FAANG Core)

| # | Problem | Platform | Key Technique | Difficulty |
|---|---|---|---|---|
| 6 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | LC 560 | Prefix + hashmap | Medium |
| 7 | [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/) | LC 523 | Prefix mod + hashmap | Medium |
| 8 | [Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/) | LC 974 | Prefix mod counting | Medium |
| 9 | [Contiguous Array](https://leetcode.com/problems/contiguous-array/) | LC 525 | 0→-1 transform + prefix | Medium |
| 10 | [Binary Subarrays With Sum](https://leetcode.com/problems/binary-subarrays-with-sum/) | LC 930 | Prefix + hashmap | Medium |
| 11 | [Count Number of Nice Subarrays](https://leetcode.com/problems/count-number-of-nice-subarrays/) | LC 1248 | Prefix sum of odd count | Medium |
| 12 | [Make Sum Divisible by P](https://leetcode.com/problems/make-sum-divisible-by-p/) | LC 1590 | Prefix mod + hashmap | Medium |

### Tier 3: Difference Array

| # | Problem | Platform | Key Technique | Difficulty |
|---|---|---|---|---|
| 13 | [Corporate Flight Bookings](https://leetcode.com/problems/corporate-flight-bookings/) | LC 1109 | Difference array | Medium |
| 14 | [Car Pooling](https://leetcode.com/problems/car-pooling/) | LC 1094 | Difference array | Medium |
| 15 | [Minimum Number of Increments on Subarrays to Form a Target Array](https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/) | LC 1526 | Difference thinking | Hard |
| 16 | [Brightest Position on Street](https://leetcode.com/problems/brightest-position-on-street/) | LC 2021 | Sweep line + diff array | Medium |

### Tier 4: Advanced Prefix Sum (FAANG Hard / CF 1600+)

| # | Problem | Platform | Key Technique | Difficulty |
|---|---|---|---|---|
| 17 | [Max Sum of Rectangle No Larger Than K](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/) | LC 363 | 2D prefix + sorted set | Hard |
| 18 | [Number of Submatrices That Sum to Target](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/) | LC 1074 | 2D → 1D reduce + hashmap | Hard |
| 19 | [Stamping the Grid](https://leetcode.com/problems/stamping-the-grid/) | LC 2132 | 2D prefix + 2D diff | Hard |
| 20 | [Count Subarrays With Score Less Than K](https://leetcode.com/problems/count-subarrays-with-score-less-than-k/) | LC 2302 | Prefix sum + binary search | Hard |
| 21 | [Minimum Operations to Make All Array Elements Equal](https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/) | LC 2602 | Sort + prefix + binary search | Medium |
| 22 | [Maximum Total Reward Using Operations](https://leetcode.com/problems/maximum-total-reward-using-operations-ii/) | LC 3181 | Prefix bitset/DP | Hard |
| 23 | [Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums/) | LC 907 | Monotonic stack + prefix contribution | Medium |
| 24 | [Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/) | LC 2104 | Monotonic stack + prefix contribution | Medium |

### Tier 5: Codeforces (Candidate Master level)

| # | Problem | Platform | Key Technique | Rating |
|---|---|---|---|---|
| 25 | [Good Subarrays](https://codeforces.com/problemset/problem/1398/C) | CF 1398C | Prefix sum + hashmap | 1600 |
| 26 | [Number of Segments with Big Sum](https://codeforces.com/problemset/problem/1006/C) | CF 1006C | Prefix + binary search | 1400 |
| 27 | [Kuroni and Impossible Calculation](https://codeforces.com/problemset/problem/1305/C) | CF 1305C | Pigeonhole + prefix | 1600 |
| 28 | [Greg and Array](https://codeforces.com/problemset/problem/295/A) | CF 295A | Nested difference arrays | 1400 |
| 29 | [Little Girl and Maximum Sum](https://codeforces.com/problemset/problem/276/C) | CF 276C | Difference array + sort | 1500 |
| 30 | [Karen and Coffee](https://codeforces.com/problemset/problem/816/B) | CF 816B | Difference array + prefix | 1400 |
| 31 | [Array Splitting](https://codeforces.com/problemset/problem/1197/C) | CF 1197C | Prefix sum + greedy | 1400 |
| 32 | [Balanced Tunnel](https://codeforces.com/problemset/problem/1237/C) | CF 1237C | Difference array | 1600 |
| 33 | [Tokitsukaze and Strange Inequality](https://codeforces.com/problemset/problem/1677/C) | CF 1677C | 2D prefix sum on values | 1800 |
| 34 | [Zero-One](https://codeforces.com/problemset/problem/1733/D) | CF 1733D | XOR prefix + greedy | 1800 |
| 35 | [Yet Another Card Deck](https://codeforces.com/problemset/problem/1511/C) | CF 1511C | Prefix simulation | 1100 |

---

## Quick Interview Patterns Cheatsheet

```
┌──────────────────────────────────────────────────────────────────┐
│                    DECISION TREE FOR INTERVIEWS                  │
├──────────────────────────────────────────────────────────────────┤
│                                                                  │
│  "Given an array, find subarrays with property X"                │
│       │                                                          │
│       ├─ Sum == k?  ──────────────── Prefix + Hashmap (LC 560)   │
│       │                                                          │
│       ├─ Sum divisible by k? ─────── Prefix mod + Hashmap        │
│       │                              (LC 523, LC 974)            │
│       │                                                          │
│       ├─ Equal 0s and 1s? ────────── 0→-1 + Prefix + Hashmap    │
│       │                              (LC 525)                    │
│       │                                                          │
│       ├─ XOR == k? ──────────────── Prefix XOR + Hashmap         │
│       │                                                          │
│       ├─ Max sum ≤ k? ──────────── Prefix + Sorted Set (LC 363)  │
│       │                                                          │
│       ├─ Range updates? ─────────── Difference Array (LC 1109)   │
│       │                                                          │
│       ├─ 2D region sum? ─────────── 2D Prefix Sum (LC 304)       │
│       │                                                          │
│       └─ Product except self? ───── Left/Right Product (LC 238)  │
│                                                                  │
└──────────────────────────────────────────────────────────────────┘
```

---

## FAANG Interview Tips

1. **Always clarify:** "Can elements be negative?" — this determines prefix+hash vs sliding window.
2. **State the brute force first:** $O(n^2)$ — check all subarrays. Then optimize with prefix sum.
3. **Draw the prefix array** on the whiteboard. Visually show how `prefix[j] - prefix[i]` gives subarray sum.
4. **Watch for overflow:** Mention `long long` or `long` explicitly.
5. **Handle empty prefix:** Always initialize `map[0] = 1` or `set.insert(0)`.
6. **Mod pitfall:** In C++/Java, negative % positive can be negative. Always normalize.
7. **Follow-up mastery:** If asked LC 560, be ready for LC 523, 525, 974 follow-ups.

---

## CP Strategy Notes (1900+ Rating Target)

- **Prefix + Difference array combos** appear in Div2 B/C consistently (1400–1700).
- **2D prefix sum** appears in Div2 C/D (1600–1900). Practice inclusion-exclusion until automatic.
- **Prefix on trees (Euler tour)** is the gateway to harder tree problems. Master it before tackling HLD/centroid.
- **Prefix XOR + trie** is a 1900+ technique for max XOR queries.
- **Know when NOT to use prefix sums:** If updates are online (interleaved with queries), switch to BIT/segment tree.
- **Speed:** You should code 1D/2D prefix sum and difference array in < 2 minutes. Template it.

---

*Last updated: March 7, 2026*