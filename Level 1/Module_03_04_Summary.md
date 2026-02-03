# 📝 Level 1 - Module 03 & 04 Problem Summary

> A comprehensive summary of problems, tips, and key learnings from Module 03 and Module 04

---

## 📚 Table of Contents
- [Module 03 - Intermediate Logic & Simulation](#module-03---intermediate-logic--simulation)
- [Module 04 - Problem Solving Patterns](#module-04---problem-solving-patterns)
- [Key Takeaways](#key-takeaways)

---

# Module 03 - Intermediate Logic & Simulation

## 1. A_Again_Twenty_Five
**Problem**: [Codeforces 630/A](https://codeforces.com/problemset/problem/630/A)

**Summary**: Find last two digits of 5^n.

**Solution Logic**:
```cpp
cout << 25 << endl;  // 5^n always ends in 25 for n >= 2
```

**💡 Key Points**:
- Pattern recognition: 5² = 25, 5³ = 125, 5⁴ = 625...
- Always ends in 25!
- Sometimes the answer is a constant - read the pattern!

---

## 2. A_Beautiful_Year
**Problem**: [Codeforces 271/A](https://codeforces.com/problemset/problem/271/A)

**Summary**: Find next year after n where all 4 digits are distinct.

**Solution Logic**:
```cpp
while (true) {
    n++;
    int a = n % 10;
    int b = (n / 10) % 10;
    int c = (n / 100) % 10;
    int d = (n / 1000) % 10;
    
    if (a != b && a != c && a != d && b != c && b != d && c != d)
        break;
}
```

**💡 Key Points**:
- **Digit extraction**: `n % 10` (last), `(n / 10) % 10` (second last), etc.
- Brute force is fine here - years are bounded
- Check ALL pairs for distinctness

---

## 3. A_Everybody_Likes_Good_Arrays
**Problem**: [Codeforces 1777/A](https://codeforces.com/problemset/problem/1777/A)

**Summary**: Count minimum removals to make no adjacent elements have same parity.

**Solution Logic**:
- Count consecutive elements with same parity
- For k consecutive same-parity elements, need to remove k-1

```cpp
for (int i = 0; i < n; i++) {
    if (i == 0 || a[i-1] % 2 == a[i] % 2) {
        k++;
    } else {
        totalOps += k - 1;
        k = 1;
    }
}
totalOps += k - 1;  // Don't forget the last group!
```

**💡 Key Points**:
- **Grouping consecutive elements** - common pattern
- From k consecutive same elements, keep 1, remove k-1
- Don't forget to process the **last group** after the loop!

---

## 4. A_Everyone_Loves_to_Sleep
**Problem**: [Codeforces 1714/A](https://codeforces.com/problemset/problem/1714/A)

**Summary**: Find minimum time until next alarm after sleep time.

**Solution Logic**:
```cpp
int sleepTime = h * 60 + m;  // Convert to minutes
int ans = 1e7;

for (each alarm) {
    int alarmTime = hour_i * 60 + min_i;
    int diff = alarmTime - sleepTime;
    if (diff < 0) diff += 1440;  // Wrap around midnight
    ans = min(ans, diff);
}

cout << ans / 60 << " " << ans % 60;
```

**💡 Key Points**:
- **Convert time to minutes** for easier calculation
- Handle **wrap-around** (next day): add 1440 (24×60) if negative
- Convert back: `/ 60` for hours, `% 60` for minutes

---

## 5. A_Full_House
**Problem**: [AtCoder ABC263/A](https://atcoder.jp/contests/abc263/tasks/abc263_a)

**Summary**: Check if 5 cards form a Full House (3 of one kind + 2 of another).

**Solution Logic**:
```cpp
int freq[14] = {0};
for (5 cards) freq[card]++;

bool hasTwo = false, hasThree = false;
for (int i = 0; i < 14; i++) {
    if (freq[i] == 2) hasTwo = true;
    if (freq[i] == 3) hasThree = true;
}

cout << (hasTwo && hasThree ? "Yes" : "No");
```

**💡 Key Points**:
- **Frequency counting** for card problems
- Full House = exactly one pair + exactly one triple
- Array indexing works great for small value ranges

---

## 6. A_Subset_Mex
**Problem**: [Codeforces 1406/A](https://codeforces.com/problemset/problem/1406/A)

**Summary**: Split array into two sets to maximize sum of their MEX values.

**Solution Logic**:
```cpp
int count[101] = {0};
for (auto x : arr) count[x]++;

int mexa = 0;
while (count[mexa] >= 1) mexa++;  // MEX of first set

int mexb = 0;
while (count[mexb] >= 2) mexb++;  // MEX of second set (needs 2 copies)

cout << mexa + mexb;
```

**💡 Key Points**:
- **MEX** = Minimum Excludant (smallest non-negative integer not in set)
- First set can use elements appearing ≥1 time
- Second set can use elements appearing ≥2 times
- Greedy: maximize first MEX, then second

---

## 7. A_Two_Permutations
**Problem**: [Codeforces 1761/A](https://codeforces.com/problemset/problem/1761/A)

**Summary**: Check if two permutations of lengths a and b can be interleaved in array of length n.

**Solution Logic**:
```cpp
// Either: n == a && a == b (both full arrays)
// Or: a + b + 1 < n (room for gap)
cout << ((n == a && a == b) || (a + b + 1 < n) ? "Yes" : "No");
```

**💡 Key Points**:
- Permutation of length k contains elements 1 to k
- Need non-overlapping positions
- Edge cases: when both permutations cover entire array

---

## 8. A_Unimodal_Array
**Problem**: [Codeforces 831/A](https://codeforces.com/problemset/problem/831/A)

**Summary**: Check if array is unimodal (strictly increasing, then constant, then strictly decreasing).

**Solution Logic**:
1. Find where increasing part ends (pos1)
2. Find where decreasing part starts (pos2)
3. Check if middle part [pos1, pos2] is all equal

**💡 Key Points**:
- **State machine**: three states (increasing → constant → decreasing)
- Can traverse from both ends
- Middle "peak" can be a plateau (same values)

---

## 9. A_Water_Station
**Problem**: [AtCoder ABC305/A](https://atcoder.jp/contests/abc305/tasks/abc305_a)

**Summary**: Round to nearest multiple of 5.

**Solution Logic**:
```cpp
int val1 = n % 5;        // Distance to lower multiple
int val2 = 5 - (n % 5);  // Distance to upper multiple

if (val1 > val2)
    cout << n + val2;
else
    cout << n - val1;
```

**💡 Key Points**:
- Rounding to nearest multiple: compare distances
- `n % 5` gives distance to floor
- `5 - n % 5` gives distance to ceiling

---

## 10. A_When
**Problem**: [AtCoder ABC258/A](https://atcoder.jp/contests/abc258/tasks/abc258_a)

**Summary**: Convert minutes from 21:00 to HH:MM format.

**Solution Logic**:
```cpp
if (n >= 60) {
    cout << "22:" << setfill('0') << setw(2) << n % 60;
} else {
    cout << "21:" << setfill('0') << setw(2) << n;
}
```

**💡 Key Points**:
- Time formatting: handle leading zeros
- Use `setw(2)` and `setfill('0')` for padding
- Or manual: `if (x < 10) cout << "0" << x;`

---

## 11. B_Array_Cancellation
**Problem**: [Codeforces 1405/B](https://codeforces.com/problemset/problem/1405/B)

**Summary**: Make array all zeros. Free operation: decrease a[i], increase a[j] where i < j. Paid: i > j.

**Solution Logic**:
```cpp
ll pos = 0, neg = 0;
for (int i = 0; i < n; i++) {
    if (arr[i] >= 0) {
        pos += arr[i];
    } else {
        if (pos >= abs(arr[i])) {
            pos -= abs(arr[i]);
        } else {
            neg += abs(arr[i]) - pos;
            pos = 0;
        }
    }
}
cout << neg;
```

**💡 Key Points**:
- **Prefix sum thinking**: positives before can cancel negatives for free
- Track accumulated positive "credit"
- Only pay when negative exceeds available positive credit

---

## 12. B_Card_Game
**Problem**: [Codeforces 1999/B](https://codeforces.com/problemset/problem/1999/B)

**Summary**: Two players with 2 cards each. Count wins based on card comparison rules.

**💡 Key Points**:
- Careful case analysis
- Consider all pairings
- Use logical AND/OR for combining conditions

---

## 13. B_Discord
**Problem**: [AtCoder ABC303/B](https://atcoder.jp/contests/abc303/tasks/abc303_b)

**Summary**: Count pairs of people who were never adjacent in any photo.

**Solution Logic**:
- For each person, mark who they were adjacent to
- Count unmarked pairs

**💡 Key Points**:
- **Adjacency tracking** using 2D boolean array
- Divide final count by 2 (each pair counted twice)
- Watch for boundary checks in adjacency

---

## 14. B_Fill_the_Gaps
**Problem**: [AtCoder ABC301/B](https://atcoder.jp/contests/abc301/tasks/abc301_b)

**Summary**: Fill missing integers between consecutive elements.

**Solution Logic**:
```cpp
for (int i = 0; i < n - 1; i++) {
    cout << arr[i] << " ";
    if (arr[i] < arr[i+1]) {
        for (int j = arr[i] + 1; j < arr[i+1]; j++)
            cout << j << " ";
    } else {
        for (int j = arr[i] - 1; j > arr[i+1]; j--)
            cout << j << " ";
    }
}
cout << arr[n-1];
```

**💡 Key Points**:
- Handle both increasing and decreasing gaps
- Don't duplicate endpoints
- Output the last element separately

---

## 15. B_Mark_the_Dust_Sweeper
**Problem**: [Codeforces 1705/B](https://codeforces.com/problemset/problem/1705/B)

**Summary**: Sweep dust to the right. Count operations needed.

**Solution Logic**:
```cpp
ll zeros = 0, sum = 0;
bool flag = false;

for (int i = 1; i <= n - 1; i++) {
    sum += arr[i];
    if (arr[i] > 0) flag = true;
    if (arr[i] == 0 && flag) zeros++;
}

cout << sum + zeros;
```

**💡 Key Points**:
- **Skip leading zeros** - they don't need operations
- Each non-leading zero adds one extra operation
- Sum of elements = base operations

---

## 16. B_Multiply_by_2_divide_by_6
**Problem**: [Codeforces 1374/B](https://codeforces.com/problemset/problem/1374/B)

**Summary**: Transform n to 1 using operations: multiply by 2 or divide by 6.

**Solution Logic**:
```cpp
int ops = 0;
while (n != 1) {
    if (n % 6 == 0) {
        n /= 6;
        ops++;
    } else if ((n * 2) % 6 == 0) {
        n = (n * 2) / 6;
        ops += 2;
    } else {
        break;  // Impossible
    }
}
cout << (n == 1 ? ops : -1);
```

**💡 Key Points**:
- Work backwards: what's needed to reach 1?
- n must be of form 2^a × 3^b where a ≤ b
- Greedy: divide by 6 when possible

---

## 17. B_Perfect_Number
**Problem**: [Codeforces 919/B](https://codeforces.com/problemset/problem/919/B)

**Summary**: Find n-th number whose digit sum is 10.

**Solution Logic**:
```cpp
int count = 0;
for (int i = 19; ; i += 9) {  // Optimization: digit sum pattern
    if (sumOfDigits(i) == 10) {
        if (++count == n) {
            cout << i;
            break;
        }
    }
}
```

**💡 Key Points**:
- First number with digit sum 10 is 19
- Numbers with same digit sum differ by multiples of 9
- Precomputation can speed up multiple queries

---

## 18. B_Rotate
**Problem**: [AtCoder ABC309/B](https://atcoder.jp/contests/abc309/tasks/abc309_b)

**Summary**: Rotate outer ring of matrix clockwise by 1.

**Solution Logic**:
1. Save top-left corner
2. Shift left column up
3. Shift bottom row left
4. Shift right column down
5. Shift top row right
6. Place saved value

**💡 Key Points**:
- **Rotate in steps** to avoid overwriting
- Save the element that would be overwritten first
- Or use a temporary array for the entire ring

---

## 19. B_Same_Map_in_the_RPG_World
**Problem**: [AtCoder ABC300/B](https://atcoder.jp/contests/abc300/tasks/abc300_b)

**Summary**: Check if two grids are equal after some cyclic shifts.

**Solution Logic**:
```cpp
for (int s = 0; s < h; s++) {
    for (int t = 0; t < w; t++) {
        bool match = true;
        for (int i = 0; i < h && match; i++) {
            for (int j = 0; j < w && match; j++) {
                if (a[i][j] != b[(i + s) % h][(j + t) % w])
                    match = false;
            }
        }
        if (match) return "Yes";
    }
}
return "No";
```

**💡 Key Points**:
- **Cyclic shift**: use modulo `(i + shift) % size`
- Try all possible (vertical, horizontal) shift combinations
- Early exit on mismatch for efficiency

---

## 20. Z_Three_Numbers
**Problem**: [Assiut Sheet](https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/Z)

**Summary**: Count triplets (x, y, z) where 0 ≤ x, y, z ≤ k and x + y + z = s.

**Solution Logic**:
```cpp
int count = 0;
for (int x = 0; x <= k; x++) {
    for (int y = 0; y <= k; y++) {
        int z = s - x - y;
        if (z >= 0 && z <= k)
            count++;
    }
}
```

**💡 Key Points**:
- **Fix two variables, compute third**: z = s - x - y
- Check if computed value is in valid range
- Reduces O(n³) to O(n²)

---

# Module 04 - Problem Solving Patterns

## 1. A_Equation
**Problem**: [Codeforces 1269/A](https://codeforces.com/problemset/problem/1269/A)

**Summary**: Find two composite numbers a and b such that a - b = n.

**Solution Logic**:
```cpp
cout << 9 * n << " " << 8 * n;
// 9n and 8n are always composite (multiples of 9 and 8)
// 9n - 8n = n ✓
```

**💡 Key Points**:
- **Constructive**: find a pattern that always works
- 9n and 8n are composite for any n ≥ 1
- Think about multiples when dealing with composite numbers

---

## 2. A_Holiday_Of_Equality
**Problem**: [Codeforces 758/A](https://codeforces.com/problemset/problem/758/A)

**Summary**: Make all elements equal by only increasing. Find minimum operations.

**Solution Logic**:
```cpp
int maxEle = *max_element(arr, arr + n);
int ans = 0;
for (int x : arr)
    ans += maxEle - x;
```

**💡 Key Points**:
- Can only increase → target is maximum element
- Answer = sum of (max - each element)
- **Greedy**: all must reach the max

---

## 3. A_XXYYX
**Problem**: [AtCoder ARC157/A](https://atcoder.jp/contests/arc157/tasks/arc157_a)

**Summary**: Check if string with given counts of "XX", "XY", "YX", "YY" substrings exists.

**Solution Logic**:
```cpp
// B = XY count, C = YX count
// Need |B - C| <= 1
// If A > 0 and D > 0, need B > 0 or C > 0 (to connect X's and Y's)
```

**💡 Key Points**:
- **Construction constraints**: XY and YX counts differ by at most 1
- String must be connected - can't have isolated groups
- Edge cases when some counts are 0

---

## 4. B_At_Most_3_Judge_ver
**Problem**: [AtCoder ABC251/B](https://atcoder.jp/contests/abc251/tasks/abc251_b)

**Summary**: Count distinct sums achievable using at most 3 weights.

**Solution Logic**:
```cpp
bool cnt[3000001] = {false};

// Single weights
for (int i = 0; i < n; i++) cnt[arr[i]] = true;

// Pairs
for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
        cnt[arr[i] + arr[j]] = true;

// Triples
for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
        for (int k = j + 1; k < n; k++)
            cnt[arr[i] + arr[j] + arr[k]] = true;

// Count true values up to W
```

**💡 Key Points**:
- **Boolean array** for marking achievable sums
- Enumerate all combinations (1, 2, 3 elements)
- Use indices i < j < k to avoid duplicates

---

## 5. B_Divan_and_a_New_Project
**Problem**: [Codeforces 1614/B](https://codeforces.com/problemset/problem/1614/B)

**Summary**: Place buildings to minimize total travel distance from HQ.

**Solution Logic**:
```cpp
// Sort by visit count (descending)
// Place most visited buildings closest to HQ (position 0)
// Alternate positions: 1, -1, 2, -2, 3, -3, ...
```

**💡 Key Points**:
- **Greedy**: place frequently visited places closer
- Alternating positive/negative positions is optimal
- Total distance = 2 × sum(visits × distance)

---

## 6. B_Go_Straight_and_Turn_Right
**Problem**: [AtCoder ABC244/B](https://atcoder.jp/contests/abc244/tasks/abc244_b)

**Summary**: Simulate robot movement (S = forward, R = turn right).

**Solution Logic**:
```cpp
int x = 0, y = 0;
char dir = 'r';  // right, left, top, down

for (char c : s) {
    if (c == 'S') {
        // Move in current direction
        if (dir == 'r') x++;
        else if (dir == 'l') x--;
        else if (dir == 't') y++;
        else y--;
    } else {
        // Turn right: r→d→l→t→r
        if (dir == 'r') dir = 'd';
        else if (dir == 'd') dir = 'l';
        else if (dir == 'l') dir = 't';
        else dir = 'r';
    }
}
```

**💡 Key Points**:
- **State machine** for direction
- Right turn cycle: R → D → L → U → R
- Separate position update from direction update

---

## 7. B_Make_It_Ugly
**Problem**: [Codeforces 1954/B](https://codeforces.com/problemset/problem/1954/B)

**Summary**: Remove minimum elements to make array "not beautiful" (first element not repeated throughout).

**Solution Logic**:
```cpp
// If all same → impossible
if (allSame) return -1;

// Find minimum gap between non-first-element values
int ans = n, gap = 0;
for (int i = 0; i < n; i++) {
    if (arr[i] == arr[0]) {
        gap++;
    } else {
        ans = min(ans, gap);
        gap = 0;
    }
}
ans = min(ans, gap);
```

**💡 Key Points**:
- Find shortest run of arr[0] values
- Removing this run breaks the "beautiful" property
- Handle edge case: all elements same

---

## 8. B_Minimize_Ordering
**Problem**: [AtCoder ABC242/B](https://atcoder.jp/contests/abc242/tasks/abc242_b)

**Summary**: Rearrange string to get lexicographically smallest permutation.

**Solution Logic**:
```cpp
int freq[26] = {0};
for (char c : s) freq[c - 'a']++;

string ans = "";
for (int i = 0; i < 26; i++) {
    while (freq[i] > 0) {
        ans += (char)(i + 'a');
        freq[i]--;
    }
}
```

**💡 Key Points**:
- **Sorting characters** = lexicographically smallest
- Frequency array approach is O(n + 26)
- Or simply: `sort(s.begin(), s.end())`

---

## 9. B_Pasta
**Problem**: [AtCoder ABC241/B](https://atcoder.jp/contests/abc241/tasks/abc241_b)

**Summary**: Check if all needed pasta lengths are available (each can be used once).

**Solution Logic**:
```cpp
for (each needed length) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (available[i] == needed) {
            available[i] = 0;  // Mark as used
            found = true;
            break;
        }
    }
    if (!found) return "No";
}
return "Yes";
```

**💡 Key Points**:
- **Matching problem**: mark used items
- Can't reuse: set to 0 or use boolean array
- Order of checking doesn't matter here

---

## 10. B_TMT_Document
**Problem**: [Codeforces 1509/B](https://codeforces.com/problemset/problem/1509/B)

**Summary**: Check if string can be partitioned into "TMT" substrings.

**Solution Logic**:
```cpp
// Count positions of T's and M's
// Need #T = 2 × #M
// For each M at position i, need one T before and one T after
vector<int> T_pos, M_pos;
// ...
for (int i = 0; i < M_pos.size(); i++) {
    if (!(T_pos[i] < M_pos[i] && M_pos[i] < T_pos[i + M_pos.size()]))
        return false;
}
```

**💡 Key Points**:
- **Position tracking** for pattern matching
- Each M needs exactly one T before and one T after
- First half of T's pair with M's, second half comes after

---

## 11. Counting_Divisors
**Problem**: [CSES 1713](https://cses.fi/problemset/task/1713)

**Summary**: Count divisors of n efficiently.

**Solution Logic**:
```cpp
int ans = 0;
for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
        ans++;
        if (n / i != i)  // Avoid counting sqrt twice
            ans++;
    }
}
```

**💡 Key Points**:
- **O(√n)** instead of O(n)
- Divisors come in pairs: (i, n/i)
- Special case: perfect squares (i = n/i)

---

## 12. E_Mirror_Grid
**Problem**: [Codeforces 1703/E](https://codeforces.com/contest/1703/problem/E)

**Summary**: Minimum flips to make grid same after 90°, 180°, 270° rotations.

**Solution Logic**:
```cpp
// 4 corresponding positions for any (i, j):
// (i, j), (j, n-i-1), (n-i-1, n-j-1), (n-j-1, i)

for (int i = 0; i < n/2; i++) {
    for (int j = 0; j < (n+1)/2; j++) {
        int ones = count 1's at all 4 positions;
        // Need all same: flip min(ones, 4-ones)
        if (ones == 2) ans += 2;
        else if (ones == 1 || ones == 3) ans += 1;
    }
}
```

**💡 Key Points**:
- **Rotation formulas**:
  - 90°: (i, j) → (j, n-1-i)
  - 180°: (i, j) → (n-1-i, n-1-j)
  - 270°: (i, j) → (n-1-j, i)
- Group related positions, make them all same
- Only iterate over one "quadrant" to avoid double counting

---

## 13. Number_Groups
**Problem**: [HackerRank](https://www.hackerrank.com/challenges/number-groups/problem)

**Summary**: Find sum of k-th group where groups have 1, 2, 3, ... elements.

**Solution Logic**:
```cpp
// Group k starts at position (k-1)*k/2 + 1
// Has k elements
// Using arithmetic progression formula: sum = k³
cout << k * k * k;
```

**💡 Key Points**:
- **Arithmetic Progression** formula: S = n(2a + (n-1)d) / 2
- Pattern recognition leads to closed-form formula
- k-th group sum = k³ (beautiful result!)

---

# Key Takeaways

## 🎯 Problem-Solving Patterns Learned

### 1. Time Conversion
```cpp
// Convert HH:MM to minutes
int totalMinutes = hours * 60 + minutes;

// Convert back
int hours = totalMinutes / 60;
int minutes = totalMinutes % 60;

// Handle wrap-around (next day)
if (diff < 0) diff += 1440;  // 24 * 60
```

### 2. Cyclic Array Access
```cpp
// Shift by k positions
newIndex = (index + k) % size;

// 2D cyclic shift
newRow = (row + rowShift) % height;
newCol = (col + colShift) % width;
```

### 3. Matrix Rotation Coordinates
```cpp
// 90° clockwise: (i, j) → (j, n-1-i)
// 180°: (i, j) → (n-1-i, n-1-j)
// 270° clockwise: (i, j) → (n-1-j, i)
```

### 4. Consecutive Group Processing
```cpp
int groupSize = 0;
for (int i = 0; i < n; i++) {
    if (/* same group condition */) {
        groupSize++;
    } else {
        // Process completed group
        processGroup(groupSize);
        groupSize = 1;  // Start new group
    }
}
processGroup(groupSize);  // Don't forget last group!
```

### 5. Divisor Counting (O(√n))
```cpp
int count = 0;
for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
        count++;
        if (i != n / i) count++;  // Pair divisor
    }
}
```

### 6. Constructive Problems
```cpp
// When asked to "construct" or "find any", look for patterns:
// - Multiples of small numbers are often composite
// - Sort and place greedily
// - Use simple formulas that always work
```

### 7. Digit Manipulation
```cpp
// Extract digits
int lastDigit = n % 10;
int secondLast = (n / 10) % 10;
int thirdLast = (n / 100) % 10;

// Sum of digits
int sum = 0;
while (n) { sum += n % 10; n /= 10; }
```

## ⚠️ Common Mistakes to Avoid

1. **Forgetting the last group** in consecutive element processing
2. **Off-by-one in rotation** formulas (n-1 vs n)
3. **Integer overflow** in multiplication before division
4. **Perfect square double-counting** in divisor problems
5. **Leading zeros** handling in number problems
6. **Edge cases**: n=1, empty arrays, all same elements

## 📊 Complexity Reminders

| Problem Type | Typical Approach | Complexity |
|--------------|------------------|------------|
| Digit sum = k | Iterate + check | O(answer) |
| Divisor count | √n loop | O(√n) |
| All shifts | Nested loops | O(n × m × h × w) |
| 3-element sums | Triple loop | O(n³) |
| Pattern match | State machine | O(n) |

---

> 💪 **Module 3 & 4 focus on simulation, pattern recognition, and mathematical insights. Master these and you'll handle implementation-heavy problems with ease!**

*Last Updated: February 2026*
