# 🔥 Difference Array — Complete Guide for Competitive Programming

> **Goal**: Master (Codeforces) in 2 years  
> **Last Updated**: March 2026

---

## 📚 Table of Contents
1. [What is a Difference Array?](#what-is-a-difference-array)
2. [Core Intuition](#core-intuition)
3. [Building & Reconstructing](#building--reconstructing)
4. [The Range Update Trick](#the-range-update-trick)
5. [Step-by-Step Walkthrough](#step-by-step-walkthrough)
6. [When to Use Difference Arrays — Pattern Recognition](#when-to-use-difference-arrays--pattern-recognition)
7. [Common Variations](#common-variations)
8. [Tips & Pitfalls from a Grandmaster](#tips--pitfalls-from-a-grandmaster)
9. [Example Problems with Solutions](#example-problems-with-solutions)
10. [Practice Problems (Codeforces & Leetcode)](#practice-problems-codeforces--leetcode)

---

## What is a Difference Array?

A **difference array** is a technique that converts **range update operations** from $O(n)$ to $O(1)$ each, at the cost of a single $O(n)$ prefix-sum pass at the end to recover the final array.

Given an array `a[0..n-1]`, the difference array `d[0..n-1]` is defined as:

$$
d[i] = \begin{cases} a[0] & \text{if } i = 0 \\ a[i] - a[i-1] & \text{if } i > 0 \end{cases}
$$

The original array can always be recovered from `d` by taking the **prefix sum**:

$$
a[i] = \sum_{j=0}^{i} d[j]
$$

> **Key Insight**: The difference array is the **inverse operation** of the prefix sum. If prefix sum answers range *queries* efficiently, the difference array answers range *updates* efficiently.

---

## Core Intuition

Think of it like this:

| Technique | What it optimizes | Direction |
|---|---|---|
| **Prefix Sum** | Multiple **range queries** on a static array | Query: $O(1)$, Update: $O(n)$ |
| **Difference Array** | Multiple **range updates**, single final read | Update: $O(1)$, Query (after rebuild): $O(n)$ |

They are **duals** of each other. Understanding this duality is the mark of a strong competitive programmer.

---

## Building & Reconstructing

### Building the Difference Array
```cpp
// Given array a[] of size n
vector<int> d(n);
d[0] = a[0];
for (int i = 1; i < n; i++) {
    d[i] = a[i] - a[i - 1];
}
```

### Reconstructing the Original Array (Prefix Sum of d)
```cpp
// Given difference array d[] of size n
vector<int> a(n);
a[0] = d[0];
for (int i = 1; i < n; i++) {
    a[i] = a[i - 1] + d[i];
}
```

---

## The Range Update Trick

**Problem**: Add value `val` to every element in range `[l, r]` (0-indexed).

**Brute force**: Loop from `l` to `r` and add `val` → $O(r - l + 1)$ per update.

**Difference array**: Just two operations → $O(1)$ per update!

```cpp
d[l] += val;
if (r + 1 < n) d[r + 1] -= val;
```

**Why does this work?**

When you eventually take the prefix sum of `d`:
- `d[l] += val` means every element from index `l` onward gets `+val`.
- `d[r+1] -= val` cancels that effect from index `r+1` onward.
- Net result: only `[l, r]` gets `+val`. Exactly what we want.

### Template Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<long long> d(n + 1, 0); // +1 to avoid boundary checks
    
    while (q--) {
        int l, r;
        long long val;
        cin >> l >> r >> val; // 0-indexed [l, r]
        d[l] += val;
        if (r + 1 <= n - 1) d[r + 1] -= val;
    }
    
    // Reconstruct: prefix sum
    vector<long long> a(n);
    a[0] = d[0];
    for (int i = 1; i < n; i++) {
        a[i] = a[i - 1] + d[i];
    }
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
    
    return 0;
}
```

---

## Step-by-Step Walkthrough

**Initial array**: `a = [0, 0, 0, 0, 0]` (5 elements, all zero)

**Operations**:
1. Add `+3` to range `[1, 3]`
2. Add `+5` to range `[0, 2]`
3. Add `-2` to range `[2, 4]`

**Difference array evolution**:

```
Start:      d = [0, 0, 0, 0, 0]

Op 1: +3 on [1,3]
  d[1] += 3, d[4] -= 3
  d = [0, 3, 0, 0, -3]

Op 2: +5 on [0,2]
  d[0] += 5, d[3] -= 5
  d = [5, 3, 0, -5, -3]

Op 3: -2 on [2,4]
  d[2] += (-2), d[5] is out of bounds → skip
  d = [5, 3, -2, -5, -3]
```

**Prefix sum to reconstruct**:
```
a[0] = 5
a[1] = 5 + 3 = 8
a[2] = 8 + (-2) = 6
a[3] = 6 + (-5) = 1
a[4] = 1 + (-3) = -2
```

**Final array**: `a = [5, 8, 6, 1, -2]`

**Verify manually**:
```
Index:       0    1    2    3    4
Start:       0    0    0    0    0
+3 on [1,3]: 0    3    3    3    0
+5 on [0,2]: 5    8    8    3    0
-2 on [2,4]: 5    8    6    1   -2  ✓
```

---

## When to Use Difference Arrays — Pattern Recognition

This is the **most important section**. Recognizing when to apply the technique separates Experts from Grandmasters.

### 🔍 Red Flags in Problem Statements

Look for these keywords and patterns:

| Signal | Example Phrasing |
|---|---|
| **Multiple range updates** | "Perform Q operations, each adds X to elements from L to R" |
| **Increment/Decrement intervals** | "For each query, increase all values in a subarray" |
| **Overlap counting** | "How many intervals cover each point?" |
| **Sweep line on 1D** | "Given N intervals, find the maximum number of overlapping intervals" |
| **Final state after all operations** | "After all operations, print the resulting array" |
| **Arithmetic progression on range** | "Add 1, 2, 3, ... to positions L, L+1, ..., R" (use 2nd order diff) |

### ✅ Use Difference Array When:
1. You have **many range updates** but only need the **final result** (not intermediate states).
2. You need to count how many intervals/segments **cover each index**.
3. The problem involves **sweeping** over intervals on a number line or array.
4. You see `Q` updates on ranges and `Q` can be up to $10^5$ or $10^6$, making brute force $O(N \times Q)$ TLE.
5. The updates are all of the form: "add a constant to a contiguous subarray."

### ❌ Do NOT Use Difference Array When:
1. You need the array state **after each individual update** (use a Segment Tree or BIT instead).
2. Updates are **point updates** and queries are **range queries** (use prefix sums or Fenwick tree).
3. The range updates are **non-additive** (e.g., set all elements in range to X — use lazy segment tree).

### 🧠 Mental Decision Tree

```
Are you doing range updates?
├── YES → Do you need intermediate states after each update?
│   ├── YES → Use Segment Tree with Lazy Propagation
│   └── NO  → Are the updates additive (add val to [l,r])?
│       ├── YES → ✅ DIFFERENCE ARRAY
│       └── NO  → Use Segment Tree / other DS
└── NO → Are you doing range queries?
    ├── YES → Use Prefix Sums
    └── NO  → Brute force may be fine
```

---

## Common Variations

### 1. 2D Difference Array (Range updates on a matrix)

Add `val` to every cell in the sub-rectangle `(r1, c1)` to `(r2, c2)`:

```cpp
d[r1][c1]     += val;
d[r1][c2 + 1] -= val;
d[r2 + 1][c1] -= val;
d[r2 + 1][c2 + 1] += val;
```

Reconstruct with a **2D prefix sum**.

This is the 2D extension and appears in problems like "stamp a rectangle Q times, find the final grid."

### 2. Second-Order Difference Array (Arithmetic Progression Updates)

**Problem**: Add an arithmetic sequence `(a, a+d, a+2d, ...,)` to range `[l, r]`.

A single difference array handles constant additions. For **linear** (arithmetic) additions, use a **second-order difference array** — i.e., take the difference array of the difference array.

```cpp
// Add values start, start+d, start+2d, ..., to positions l, l+1, ..., r
// 1st order diff handles the "constant" part
// 2nd order diff handles the "slope" part

// dd = second order difference array
// d  = first order difference array

// Step 1: Add the slope via 2nd order
dd[l] += d_val;          // slope starts at l
dd[r + 1] -= d_val;      // slope stops after r

// Step 2: Add the base via 1st order  
d[l] += start;
d[r + 1] -= (start + (long long)(r - l) * d_val);

// Reconstruct: prefix sum dd → d_contribution, then add to d, then prefix sum d → a
```

This comes up more often than you'd expect, especially in CF Div 2 C/D problems.

### 3. Circular Difference Array

When the array is **circular** (wraps around), a range `[l, r]` where `l > r` means "from l to end, then from 0 to r":

```cpp
if (l <= r) {
    d[l] += val;
    if (r + 1 < n) d[r + 1] -= val;
} else {
    // Wraps around: [l, n-1] and [0, r]
    d[l] += val;
    d[0] += val;
    if (r + 1 < n) d[r + 1] -= val;
}
```

### 4. Difference Array on Sorted Events (Coordinate Compression)

When the value range is huge (e.g., coordinates up to $10^9$) but the number of events is small:

1. **Coordinate compress** the endpoints.
2. Apply difference array on the compressed coordinates.
3. Expand back when reading results.

```cpp
// Collect all unique endpoints, sort & deduplicate
vector<int> coords;
for (auto& [l, r, val] : queries) {
    coords.push_back(l);
    coords.push_back(r + 1);
}
sort(coords.begin(), coords.end());
coords.erase(unique(coords.begin(), coords.end()), coords.end());

// Map to compressed index
auto getIdx = [&](int x) {
    return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
};

vector<long long> d(coords.size() + 1, 0);
for (auto& [l, r, val] : queries) {
    d[getIdx(l)] += val;
    d[getIdx(r + 1)] -= val;
}
// Prefix sum on d to get values at each compressed coordinate
```

---

## Tips & Pitfalls from a Grandmaster

### 💡 Pro Tips

1. **Always allocate `n + 2` for the difference array.** Off-by-one on `d[r+1]` is the #1 bug. Just allocate extra space and forget about boundary checks.

2. **Use `long long` by default.** If you have $10^5$ updates each adding $10^9$, the prefix sum can overflow `int` easily. Don't waste 10 minutes debugging WA on test 34 because of overflow.

3. **Difference array + sorting = powerful combo.** Many problems give you intervals. Sort them by left endpoint, apply difference array logic, and sweep. This is essentially a simplified sweep line.

4. **Think of difference arrays as "event scheduling."** `d[l] += val` is "event starts at l", `d[r+1] -= val` is "event ends after r". This mental model helps with interval overlap problems.

5. **Difference array is just the derivative.** Prefix sum is integration. This analogy from calculus is exact. If you need to add a polynomial of degree $k$ to a range, use a $(k+1)$-th order difference array.

6. **0-indexed vs 1-indexed**: Be consistent. I recommend **1-indexed** for CP to avoid `r+1 == n` boundary issues (just make the array size `n + 2`).

7. **Multiple difference arrays**: Sometimes you need two — one for "how many times each index is covered" and another for "total value added." Don't be afraid to maintain multiple parallel arrays.

### ⚠️ Common Pitfalls

| Pitfall | Fix |
|---|---|
| Forgetting `d[r+1] -= val` | Always pair the increment with a decrement |
| Off-by-one: using `d[r]` instead of `d[r+1]` | Remember: the cancellation is at `r + 1`, not `r` |
| Not taking prefix sum at the end | The difference array is NOT the answer — you must reconstruct |
| Using 0-indexed with `r+1 == n` causing out-of-bounds | Allocate `n + 2` elements or use a bounds check |
| Confusing 1-indexed and 0-indexed | Pick one and stick with it for the entire problem |
| Applying to non-additive updates (e.g., "set range to X") | Difference arrays only work for additive updates |

---

## Example Problems with Solutions

### Problem 1: Range Update Queries (CSES)

> Given an array of $n$ values (initially 0) and $q$ update operations. Each operation adds value $val$ to all elements in range $[l, r]$. Print the final array.
>
> **Constraints**: $1 \le n, q \le 2 \times 10^5$

**Solution**: Textbook difference array.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<long long> d(n + 2, 0); // 1-indexed, extra space
    
    while (q--) {
        int l, r;
        long long val;
        cin >> l >> r >> val; // 1-indexed
        d[l] += val;
        d[r + 1] -= val;
    }
    
    // Prefix sum
    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
        cout << d[i] << " \n"[i == n];
    }
    
    return 0;
}
```
**Time**: $O(n + q)$ — blazing fast.

---

### Problem 2: Maximum Overlapping Intervals

> Given $n$ intervals $[l_i, r_i]$, find the maximum number of intervals that overlap at any single point.
>
> **Constraints**: $1 \le n \le 10^5$, $1 \le l_i \le r_i \le 10^6$

**Solution**: Each interval contributes `+1` at its start and `-1` after its end.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    const int MAXVAL = 1e6 + 2;
    vector<int> d(MAXVAL, 0);
    
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        d[l] += 1;
        d[r + 1] -= 1;
    }
    
    int maxOverlap = 0, current = 0;
    for (int i = 0; i < MAXVAL; i++) {
        current += d[i];
        maxOverlap = max(maxOverlap, current);
    }
    
    cout << maxOverlap << endl;
    return 0;
}
```

---

### Problem 3: CF 1000C — Covered Points Count

> You are given $n$ segments on a number line. For each $k$ from $1$ to $n$, find the number of integer points that are covered by **exactly** $k$ segments.
>
> Coordinates up to $10^{18}$ → needs coordinate compression.

**Approach**:
1. Coordinate compress the endpoints.
2. Use a difference array on compressed coordinates.
3. For each compressed interval, calculate its length and accumulate into the answer for the corresponding overlap count.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<long long> starts(n), ends(n);
    vector<long long> coords;
    
    for (int i = 0; i < n; i++) {
        cin >> starts[i] >> ends[i];
        coords.push_back(starts[i]);
        coords.push_back(ends[i] + 1);
    }
    
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    
    int m = coords.size();
    vector<long long> d(m + 1, 0);
    
    auto idx = [&](long long x) {
        return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
    };
    
    for (int i = 0; i < n; i++) {
        d[idx(starts[i])] += 1;
        d[idx(ends[i] + 1)] -= 1;
    }
    
    // Prefix sum + accumulate answer
    vector<long long> ans(n + 1, 0);
    long long cur = 0;
    for (int i = 0; i < m; i++) {
        cur += d[i];
        if (cur > 0 && i + 1 < m) {
            long long len = coords[i + 1] - coords[i];
            ans[cur] += len;
        }
    }
    
    for (int k = 1; k <= n; k++) {
        cout << ans[k] << " \n"[k == n];
    }
    
    return 0;
}
```

---

### Problem 4: CF 276C — Little Girl and Maximum Sum

> Given an array of $n$ integers and $q$ queries, each query asks for the sum of elements in $[l, r]$. You can **rearrange** the array in any order before answering. Maximize the total sum of all query answers.
>
> **Key Insight**: Use a difference array to count how many times each index is queried. Then sort both the counts and the array values — pair the largest values with the most frequently queried positions (greedy).

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<long long> a(n);
    for (auto& x : a) cin >> x;
    
    vector<long long> d(n + 2, 0); // 1-indexed
    while (q--) {
        int l, r;
        cin >> l >> r;
        d[l] += 1;
        d[r + 1] -= 1;
    }
    
    // Build frequency array
    vector<long long> freq(n);
    long long cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += d[i];
        freq[i - 1] = cur;
    }
    
    // Greedy: sort both, pair largest with largest
    sort(a.begin(), a.end());
    sort(freq.begin(), freq.end());
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] * freq[i];
    }
    
    cout << ans << endl;
    return 0;
}
```

---

### Problem 5: B — Array Cancellation (CF 1405B)

> You have an array where you can transfer value from index $i$ to index $j$. If $i < j$, it's free. If $i > j$, it costs the transferred amount. Minimize total cost to make all elements zero.
>
> **Approach**: Track the prefix sum. Whenever it goes negative, that's the cost we must pay (transferring right-to-left). This is a prefix-sum / difference-array style thinking.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long ans = 0, prefix = 0;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            prefix += x;
            if (prefix < 0) {
                ans -= prefix;
                prefix = 0;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
```

---

## Practice Problems (Codeforces & Leetcode)

### 🟢 Easy (Beginner Difference Array)
| Problem | Platform | Key Idea |
|---|---|---|
| [CSES — Range Update Queries](https://cses.fi/problemset/task/1651) | CSES | Pure difference array template |
| [CF 276C — Little Girl and Maximum Sum](https://codeforces.com/contest/276/problem/C) | CF | Diff array + greedy sort |
| [Leetcode 370 — Range Addition](https://leetcode.com/problems/range-addition/) | LC | Direct diff array application |
| [Leetcode 1109 — Corporate Flight Bookings](https://leetcode.com/problems/corporate-flight-bookings/) | LC | Range additions, return final array |

### 🟡 Medium (Difference Array + Observation)
| Problem | Platform | Key Idea |
|---|---|---|
| [CF 1000C — Covered Points Count](https://codeforces.com/contest/1000/problem/C) | CF | Diff array + coordinate compression |
| [CF 1405B — Array Cancellation](https://codeforces.com/contest/1405/problem/B) | CF | Prefix sum thinking |
| [CF 1355C — Count Triangles](https://codeforces.com/contest/1355/problem/C) | CF | Diff array for counting valid ranges |
| [Leetcode 1094 — Car Pooling](https://leetcode.com/problems/car-pooling/) | LC | Diff array on time axis |
| [Leetcode 253 — Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) | LC | Overlap counting via diff array |

### 🔴 Hard (Advanced / 2D / Higher-Order)
| Problem | Platform | Key Idea |
|---|---|---|
| [CF 1534D — Lost Arithmetic Progression](https://codeforces.com/contest/1534/problem/D) | CF | Diff array reasoning on APs |
| [CF 1622D — Shuffle](https://codeforces.com/contest/1622/problem/D) | CF | Diff array + combinatorics |
| [Leetcode 2536 — Increment Submatrices by One](https://leetcode.com/problems/increment-submatrices-by-one/) | LC | 2D difference array |
| [CF 33C — Wonderful Randomized Sum](https://codeforces.com/contest/33/problem/C) | CF | Subarray manipulation with prefix ideas |

---

## Quick Reference Card

```
┌─────────────────────────────────────────────────────────┐
│              DIFFERENCE ARRAY CHEAT SHEET               │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  Build:     d[i] = a[i] - a[i-1]                       │
│  Recover:   a[i] = prefix_sum(d, 0..i)                 │
│                                                         │
│  Range Update [l, r] += val:                            │
│      d[l]   += val                                      │
│      d[r+1] -= val                                      │
│                                                         │
│  After all updates → prefix sum d[] to get answer       │
│                                                         │
│  Complexity:                                            │
│      Build:       O(n)                                  │
│      Each update: O(1)                                  │
│      Reconstruct: O(n)                                  │
│      Total:       O(n + q)                              │
│                                                         │
│  Memory trick: allocate d[n + 2] to avoid bounds check  │
│  Type trick:   use long long by default                 │
│                                                         │
│  2D version:                                            │
│      d[r1][c1]       += val                             │
│      d[r1][c2+1]     -= val                             │
│      d[r2+1][c1]     -= val                             │
│      d[r2+1][c2+1]   += val                             │
│      Recover with 2D prefix sum                         │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

---

> *"The difference array is one of those techniques that, once internalized, makes you see range-update problems in a completely different light. It's not just a trick — it's a way of thinking. Every time you see 'add X to a range,' your brain should immediately whisper: difference array."*  
> — Grandmaster wisdom
