# Module 07 & 08 Problem Summary
> **Theme**: Binary Search, Sorting, Greedy Algorithms, and Hash Maps

---

## 📚 Module 07 - Binary Search and Sorting

### 1. 69_sqrt_x (Square Root)
**📎 Problem**: [LeetCode 69](https://leetcode.com/problems/sqrtx/description/)

**Summary**: Find the integer square root of x (floor of √x).

**Solution Logic**:
- **Binary Search**: Search in range [2, x/2] for largest num where num² ≤ x
- Alternative: Use math formula `e^(0.5 * log(x))`

```cpp
int sqrtBS(int x) {
    if(x < 2) return x;
    int left = 2, right = x / 2;
    while(left <= right) {
        long mid = left + (right - left) / 2;
        long num = mid * mid;
        if(num == x) return mid;
        else if(num < x) left = mid + 1;
        else right = mid - 1;
    }
    return right;  // Return right (floor value)
}
```

**💡 Key Points**:
- **Binary Search on Answer**: Search for value satisfying condition
- Use `long long` to prevent overflow in `mid * mid`
- Return `right` for floor, `left` for ceiling
- Time: O(log n), Space: O(1)

---

### 2. 852_Peak_Index_In_a_Mountain_Array
**📎 Problem**: [LeetCode 852](https://leetcode.com/problems/peak-index-in-a-mountain-array/description/)

**Summary**: Find peak element in mountain array (increases then decreases).

**Solution Logic**:
- **Binary Search**: Compare mid with mid+1
- If arr[mid] < arr[mid+1] → peak is on right
- Else → peak is on left (including mid)

```cpp
int l = 0, r = n - 1;
while(l < r) {
    int mid = l + (r - l) / 2;
    if(arr[mid] < arr[mid + 1])
        l = mid + 1;
    else
        r = mid;
}
return l;  // l == r == peak index
```

**💡 Key Points**:
- **Binary Search on monotonic property**: Direction of slope changes
- Peak satisfies: arr[i-1] < arr[i] > arr[i+1]
- Use `l < r` (not `l <= r`) to converge to single element
- Time: O(log n) vs O(n) brute force

---

### 3. A_Cubes_Sorting
**📎 Problem**: [Codeforces 1420A](https://codeforces.com/contest/1420/problem/A)

**Summary**: Can array be sorted in < n(n-1)/2 adjacent swaps?

**Solution Logic**:
- **Key insight**: Only strictly decreasing array with all unique elements needs exactly n(n-1)/2 swaps
- If array has any a[i] ≤ a[i+1], answer is YES
- If strictly decreasing → NO

```cpp
bool flag = true;
for(int i = 0; i < n - 1; ++i) {
    if(arr[i] <= arr[i + 1]) {  // Not strictly decreasing
        flag = false;
        break;
    }
}
cout << (flag ? "NO" : "YES");
```

**💡 Key Points**:
- **Bubble sort analysis**: Max swaps = inversions = n(n-1)/2 for reverse sorted
- Duplicate elements or any non-decreasing pair reduces swaps needed
- Think about worst case vs given case

---

### 4. A_Gravity_Flip
**📎 Problem**: [Codeforces 405A](https://codeforces.com/problemset/problem/405/A)

**Summary**: Simulate gravity flip - boxes fall to the right.

**Solution Logic**:
- After gravity flip, column heights become sorted (ascending left to right)
- Simply **sort the array** and output

```cpp
sort(arr.begin(), arr.end());
for(int i = 0; i < n; i++) cout << arr[i] << " ";
```

**💡 Key Points**:
- **Simulation simplification**: Gravity flip = sorting
- Physical phenomena often translate to simple algorithms
- Sometimes brute force simulation is unnecessary

---

### 5. B_Closest_to_the_Left
**📎 Problem**: [Codeforces EDU Binary Search](https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B)

**Summary**: For each query x, find max index where arr[i] ≤ x.

**Solution Logic**:
- **Binary search for rightmost element ≤ x**
- Track answer when condition is met, move left pointer right

```cpp
int binarySearch(int n, vector<int>& arr, int x) {
    int left = 0, right = n - 1, ans = -1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] <= x) {
            ans = mid;
            left = mid + 1;  // Search for larger index
        } else {
            right = mid - 1;
        }
    }
    return ans + 1;  // 1-indexed
}
```

**💡 Key Points**:
- **Lower/Upper bound variations**: Know when to use each
- `upper_bound(x) - 1` gives rightmost element ≤ x
- STL: `upper_bound()` returns iterator to first element > x

---

### 6. B_Equal_Candies
**📎 Problem**: [Codeforces 1676B](https://codeforces.com/problemset/problem/1676/B)

**Summary**: Minimum candies to remove so all boxes have equal candies.

**Solution Logic**:
- To minimize removal, keep boxes at **minimum value**
- Sort array, target = minimum element
- Answer = sum of (arr[i] - min) for all i

```cpp
sort(arr.begin(), arr.end());
int ans = 0;
for(int i = 1; i < n; ++i) {
    ans += (arr[i] - arr[0]);
}
```

**💡 Key Points**:
- **Greedy insight**: Can only remove, so target is minimum
- Sum formula: total - n × min = Σarr - n × arr[0]
- Sorting helps identify min and simplifies calculation

---

### 7. D_Even_Odd_Game
**📎 Problem**: [Codeforces 1472D](https://codeforces.com/problemset/problem/1472/D)

**Summary**: Alice scores even picks, Bob scores odd picks. Optimal play, who wins?

**Solution Logic**:
- **Greedy strategy**: Always pick largest element (maximize own score OR deny opponent)
- Sort descending, alternate picks
- Alice takes even values, Bob takes odd values

```cpp
sort(a.begin(), a.end(), greater<ll>());
for(int i = 0; i < n; i++) {
    if(i % 2 == 0) {  // Alice's turn
        if(a[i] % 2 == 0) aliceSum += a[i];
    } else {  // Bob's turn
        if(a[i] % 2 != 0) bobSum += a[i];
    }
}
```

**💡 Key Points**:
- **Game theory greedy**: Taking max denies opponent even if doesn't help self
- Both players play optimally = both use same strategy
- Sort once, simulate turns

---

### 8. D_Fast_search
**📎 Problem**: [Codeforces EDU Binary Search](https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D)

**Summary**: Count elements in range [l, r] for multiple queries.

**Solution Logic**:
- Sort array once
- For each query: count(≤ r) - count(≤ l-1)
- Use binary search for both counts

```cpp
// Count elements <= x
int helper(int x, int n, int a[]) {
    int low = 0, high = n - 1, ans = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(a[mid] <= x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans + 1;
}

// Range query
int count = helper(r, n, a) - helper(l - 1, n, a);
```

**💡 Key Points**:
- **Range counting trick**: count[l,r] = count[1,r] - count[1,l-1]
- Time: O(n log n + k log n) for k queries
- Same pattern as prefix sums but with binary search

---

## 📚 Module 08 - Hash Maps, Sets, and Greedy

### 1. B_1_Wonderful_Coloring_1
**📎 Problem**: [Codeforces 1551B1](https://codeforces.com/contest/1551/problem/B1)

**Summary**: Color string with red/green, same color must have different letters, maximize balanced coloring.

**Solution Logic**:
- Letters with freq ≥ 2 can contribute 1 to each color
- Letters with freq = 1 can only contribute to one color
- Answer = count(freq ≥ 2) + count(freq = 1) / 2

```cpp
vector<int> freq(26, 0);
for(char c : s) freq[c - 'a']++;

int cnt1 = 0, cnt2 = 0;
for(int i = 0; i < 26; i++) {
    if(freq[i] == 1) cnt1++;
    else if(freq[i] >= 2) cnt2++;
}
cout << cnt2 + cnt1 / 2;
```

**💡 Key Points**:
- **Frequency analysis**: Group by count
- Letters with freq ≥ 2 are "flexible" (can go either color)
- Pair up single-occurrence letters

---

### 2. B_Chat_Order
**📎 Problem**: [Codeforces 637B](https://codeforces.com/problemset/problem/637/B)

**Summary**: Show chat list with most recent messages first, no duplicates.

**Solution Logic**:
- Iterate from end (most recent)
- Use set to track seen names
- Print first occurrence of each name

```cpp
set<string> st;
for(int i = n - 1; i >= 0; i--) {
    if(st.find(v[i]) == st.end()) {
        cout << v[i] << endl;
        st.insert(v[i]);
    }
}
```

**💡 Key Points**:
- **Reverse iteration**: Recent first
- **Set for deduplication**: O(log n) lookup
- Alternative: Use `unordered_set` for O(1) average

---

### 3. B_Different_Divisors
**📎 Problem**: [Codeforces 1474B](https://codeforces.com/problemset/problem/1474/B)

**Summary**: Find smallest number with ≥ 4 divisors where any two differ by ≥ d.

**Solution Logic**:
- Number with 4 divisors: either p³ or p×q (distinct primes)
- For p×q: divisors are 1, p, q, pq
- Need: p - 1 ≥ d, q - p ≥ d
- Find smallest prime p ≥ d+1, then smallest prime q ≥ p+d
- Compare p×q with p³, take minimum

```cpp
ll p = *lower_bound(primes.begin(), primes.end(), d + 1);
ll q = *lower_bound(primes.begin(), primes.end(), p + d);
ll a = min(p * q, p * p * p);
```

**💡 Key Points**:
- **Divisor counting**: n = p₁^a₁ × p₂^a₂ × ... has (a₁+1)(a₂+1)... divisors
- **4 divisors** = 1×4 (p³) or 2×2 (p×q)
- Precompute primes, use `lower_bound` for queries

---

### 4. B_Helmets_in_Night_Light
**📎 Problem**: [Codeforces 1877B](https://codeforces.com/problemset/problem/1877/B)

**Summary**: Minimize cost to spread announcement to n residents.

**Solution Logic**:
- Must initially announce to at least 1 person (cost p)
- Greedily use cheapest spreaders first
- Sort by cost, use each spreader's full capacity until done

```cpp
sort(v.begin(), v.end());  // Sort by cost
ll cost = p;  // Initial announcement
ll reached = 1;

for(auto [spread_cost, capacity] : v) {
    if(spread_cost >= p) break;  // Not worth it
    ll use = min(capacity, n - reached);
    cost += use * spread_cost;
    reached += use;
}
cost += (n - reached) * p;  // Remaining at cost p
```

**💡 Key Points**:
- **Greedy by cost**: Always use cheapest option first
- Compare spreader cost with direct announcement cost p
- Sort once, iterate once: O(n log n)

---

### 5. B_Make_Them_Odd
**📎 Problem**: [Codeforces 1277B](https://codeforces.com/problemset/problem/1277/B)

**Summary**: Minimum operations to make all elements odd (divide even numbers by 2).

**Solution Logic**:
- Use set to track unique values
- Process largest to smallest
- When dividing even number, result may already exist in set

```cpp
set<int> st(a.begin(), a.end());
int ans = 0;
while(!st.empty()) {
    int val = *st.rbegin();  // Largest
    st.erase(val);
    if(val % 2 == 0) {
        ans++;
        st.insert(val / 2);  // May already exist
    }
}
```

**💡 Key Points**:
- **Set handles duplicates automatically**
- Process largest first to avoid redundant work
- `rbegin()` gives largest element in set

---

### 6. B_Olya_and_Game_with_Arrays
**📎 Problem**: [Codeforces 1859B](https://codeforces.com/problemset/problem/1859/B)

**Summary**: Maximize sum of minimums after moving at most 1 element from each array.

**Solution Logic**:
- Move all smallest elements to one "trash" array
- That array contributes its second smallest (after receiving trash)
- Other arrays contribute their second smallest
- Global minimum goes to trash → contributes global min

```cpp
// Store {second_min, first_min} for each array
sort(first_2_mins.begin(), first_2_mins.end());

ll answer = 0;
ll global_min = first_2_mins[0].second;
for(int i = 1; i < n; ++i) {
    answer += first_2_mins[i].first;  // second min
    global_min = min(global_min, first_2_mins[i].second);
}
answer += global_min;  // Trash array contributes this
```

**💡 Key Points**:
- **Greedy optimization**: One array becomes "dump"
- Track both min and second-min for each array
- Sort by second-min to choose optimal trash array

---

### 7. C_Good_Sequence
**📎 Problem**: [AtCoder ARC087A](https://atcoder.jp/contests/arc087/tasks/arc087_a)

**Summary**: Remove minimum elements so each value x appears exactly x times (or 0 times).

**Solution Logic**:
- Count frequency of each value
- For value x: keep min(freq[x], x) occurrences
- Remove = total - kept

```cpp
map<int, int> freq;
for(int x : a) freq[x]++;

int keep = 0;
for(auto [val, cnt] : freq) {
    if(cnt >= val) keep += val;  // Keep exactly 'val' occurrences
    // else keep 0 (remove all)
}
cout << n - keep;
```

**💡 Key Points**:
- **Frequency map**: Count occurrences
- Decision per value: keep x or 0
- If freq < x, must remove all (can't add elements)

---

### 8. C_gacha
**📎 Problem**: [AtCoder ABC164C](https://atcoder.jp/contests/abc164/tasks/abc164_c)

**Summary**: Count distinct strings.

**Solution Logic**:
- Insert all strings into a set
- Set size = distinct count

```cpp
set<string> st;
for(int i = 0; i < n; i++) {
    string s; cin >> s;
    st.insert(s);
}
cout << st.size();
```

**💡 Key Points**:
- **Set for uniqueness**: Automatic deduplication
- Time: O(n × L log n) where L = string length
- Alternative: `unordered_set` for O(n × L) average

---

### 9. Sum_of_Two_Values
**📎 Problem**: [CSES 1640](https://www.cses.fi/problemset/task/1640)

**Summary**: Find two indices i, j where a[i] + a[j] = x (Two Sum).

**Solution Logic**:
- Use hash map to store seen values and their indices
- For each element, check if complement (x - a[i]) exists

```cpp
map<int, int> mp;  // value -> index
for(int i = 0; i < n; i++) {
    if(mp.find(x - a[i]) != mp.end()) {
        cout << i + 1 << " " << mp[x - a[i]] + 1;
        return;
    }
    mp[a[i]] = i;
}
cout << "IMPOSSIBLE";
```

**💡 Key Points**:
- **Classic Two Sum pattern**: Hash map for O(1) complement lookup
- Store index, not just existence
- Alternative: Sort + two pointers (loses original indices)
- Time: O(n), Space: O(n)

---

## 🎯 Module 07 & 08 Key Takeaways

### Binary Search Patterns

| Pattern | Condition | Return |
|---------|-----------|--------|
| Find exact | `arr[mid] == x` | mid |
| Leftmost ≥ x | `arr[mid] >= x` → go left | left |
| Rightmost ≤ x | `arr[mid] <= x` → go right | right |
| Peak finding | Compare mid with neighbor | convergence point |

### Common Data Structures Usage

| Data Structure | Use Case | Time |
|----------------|----------|------|
| `set<T>` | Unique elements, sorted | O(log n) |
| `unordered_set<T>` | Unique elements, unsorted | O(1) avg |
| `map<K,V>` | Key-value, sorted keys | O(log n) |
| `unordered_map<K,V>` | Key-value, hash-based | O(1) avg |

### Greedy Strategy Indicators

1. **Sort first**: When order matters for optimal choice
2. **Take max/min**: Extreme values often optimal
3. **Process in order**: Largest/smallest first
4. **Local optimal = Global optimal**: No need for backtracking

### Problem-Solving Tips

1. **Binary Search**:
   - Identify monotonic property
   - Define search space clearly
   - Handle boundary conditions (l < r vs l <= r)

2. **Hash Maps**:
   - Two Sum pattern: store complement
   - Frequency counting: `map[x]++`
   - Deduplication: set insertion

3. **Greedy**:
   - Prove greedy choice property
   - Sort by relevant criteria
   - Make locally optimal decisions

### Common Mistakes to Avoid

- ❌ Integer overflow in `mid * mid` (use long long)
- ❌ Wrong binary search boundary (`<` vs `<=`)
- ❌ Forgetting to handle "IMPOSSIBLE" cases
- ❌ Using wrong index (0-indexed vs 1-indexed)
- ❌ Not sorting before binary search

### Time Complexity Reference

| Operation | Complexity |
|-----------|------------|
| Binary search | O(log n) |
| Sort | O(n log n) |
| Hash map lookup | O(1) average |
| Set insertion | O(log n) |
| Two Sum with hash | O(n) |
| Range count with BS | O(log n) per query |

---

> **📝 Note**: Module 07 focuses on binary search fundamentals and sorting applications, while Module 08 introduces hash-based data structures and greedy algorithms. These form the foundation for more advanced algorithmic techniques!
