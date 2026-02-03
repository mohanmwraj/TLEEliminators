# 📝 Level 1 - Module 01 & 02 Problem Summary

> A comprehensive summary of problems, tips, and key learnings from Module 01 and Module 02

---

## 📚 Table of Contents
- [Module 01 - Basics](#module-01---basics)
- [Module 02 - Loops & Arrays](#module-02---loops--arrays)
- [Key Takeaways](#key-takeaways)

---

# Module 01 - Basics

## 1. A_Watermelon
**Problem**: [Codeforces 4/A](https://codeforces.com/problemset/problem/4/A)

**Summary**: Divide a watermelon of weight `n` into two parts, each with even weight.

**Solution Logic**:
- If `n` is odd → impossible (can't split odd into two evens)
- If `n == 2` → impossible (1+1, both odd)
- Otherwise → YES

```cpp
if (n % 2 == 1 || n == 2)
    cout << "NO";
else
    cout << "YES";
```

**💡 Key Points**:
- Edge case: `n = 2` is the tricky case
- Even + Even = Even, so n must be even AND > 2

---

## 2. A_Catch_the_Coin
**Problem**: [Codeforces 1989/A](https://codeforces.com/problemset/problem/1989/A)

**Summary**: Monocarp can catch a coin at position (x, y). Each step he moves, the coin falls down by 1.

**Solution Logic**:
- If `y < -1` → coin falls faster than we can reach it
- Otherwise → always possible

```cpp
if (y < -1)
    cout << "NO";
else
    cout << "YES";
```

**💡 Key Points**:
- Think about the **relative movement** between player and target
- Boundary condition: `y = -1` is still catchable (move diagonally)

---

## 3. A_Is_It_a_Cat
**Problem**: [Codeforces 1800/A](https://codeforces.com/problemset/problem/1800/A)

**Summary**: Check if string represents "meow" with any number of repeated consecutive letters (case insensitive).

**Solution Logic**:
1. Convert entire string to lowercase
2. Check if it matches pattern: m+ e+ o+ w+ (one or more of each in order)

**💡 Key Points**:
- Use `tolower()` for case-insensitive comparison
- State machine approach: track which character you're expecting
- Must consume ALL characters - string must end after 'w's

---

## 4. A_Politics
**Problem**: [Codeforces 1818/A](https://codeforces.com/problemset/problem/1818/A)

**Summary**: Count people who agree with the first person on all opinions.

**Solution Logic**:
- Store first person's opinions
- Compare everyone else with the first person

```cpp
int ans = 1;  // First person counts
for (int i = 1; i < n; i++)
    ans += (v[0] == v[i]);
```

**💡 Key Points**:
- String comparison makes this simple
- Don't forget to count the first person themselves!

---

## 5. B_Memo_and_Momo
**Problem**: [Assiut Sheet](https://codeforces.com/group/MWSDmqGsZm/contest/326175/problem/B)

**Summary**: Given three numbers a, b, k - check divisibility conditions.

**Solution Logic**:
```cpp
bool memo = (a % k == 0);
bool momo = (b % k == 0);

if (memo && momo) cout << "Both";
else if (memo) cout << "Memo";
else if (momo) cout << "Momo";
else cout << "No One";
```

**💡 Key Points**:
- Use modulo operator `%` for divisibility check
- Handle all 4 cases systematically

---

## 6. D_Ali_Baba_and_Puzzles
**Problem**: [Assiut Sheet](https://codeforces.com/group/MWSDmqGsZm/contest/326175/problem/D)

**Summary**: Given a, b, c, d - check if any combination of +, -, * between a, b, c equals d.

**Solution Logic**:
```cpp
if (a + b - c == d) output = "YES";
if (a + b * c == d) output = "YES";
if (a - b + c == d) output = "YES";
// ... check all 6 combinations
```

**⚠️ CRITICAL - OVERFLOW TRAP**:
```
Input: -432300451 509430974 -600857890 -220227239212711384
```
Using `int` causes overflow! Must use `long long`.

**💡 Key Points**:
- **Always consider overflow** when multiplying large numbers
- Use `long long` when values can exceed ~2×10⁹
- Remember operator precedence: `*` before `+` and `-`

---

## 7. F_Digits_Summation
**Problem**: [Assiut Sheet](https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/F)

**Summary**: Add the last digits of two numbers.

**Solution Logic**:
```cpp
cout << n % 10 + m % 10;
```

**💡 Key Points**:
- `n % 10` extracts the last digit of any number
- Simple modulo trick for digit extraction

---

## 8. I_Welcome_for_you_with_Conditions
**Problem**: [Assiut Sheet](https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/I)

**Summary**: Check if a >= b.

**💡 Key Points**:
- Basic comparison operators
- Watch for the >= vs > distinction

---

## 9. J_Multiples
**Problem**: [Assiut Sheet](https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/J)

**Summary**: Check if one number is a multiple of the other.

**Solution Logic**:
```cpp
if ((a % b == 0) || (b % a == 0))
    cout << "Multiples";
else
    cout << "No Multiples";
```

**💡 Key Points**:
- Check BOTH directions: a divides b OR b divides a
- No need to sort or find which is larger

---

## 10. K_Max_and_Min
**Problem**: [Assiut Sheet](https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/K)

**Summary**: Find min and max of three numbers.

**Solution Logic**:
```cpp
int mini = a;
if (mini > b) mini = b;
if (mini > c) mini = c;
// Similar for max
```

**💡 Key Points**:
- Can use `min({a, b, c})` and `max({a, b, c})` in C++
- Manual comparison helps understand the logic

---

## 11. L_The_Brothers
**Problem**: [Assiut Sheet](https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/L)

**Summary**: Check if two people are brothers by comparing their father's name.

**Solution Logic**:
- Input: First name + Father's name for two people
- Compare the father names (second word)

**💡 Key Points**:
- String comparison is straightforward with `==`
- Careful with input format (multiple strings)

---

## 12. V_Comparison
**Problem**: [Assiut Sheet](https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/V)

**Summary**: Given "a op b", check if the comparison is correct.

**Solution Logic**:
```cpp
char s;
cin >> a >> s >> b;

if (s == '>') result = (a > b);
else if (s == '<') result = (a < b);
else if (s == '=') result = (a == b);
```

**💡 Key Points**:
- Can read a single character with `char` and `cin >>`
- Use if-else chain for multiple conditions

---

# Module 02 - Loops & Arrays

## 1. A_In_Search_of_an_Easy_Problem
**Problem**: [Codeforces 1030/A](https://codeforces.com/problemset/problem/1030/A)

**Summary**: If ANY person thinks problem is hard (1), output "HARD". Otherwise "EASY".

**Solution Logic**:
```cpp
for (int i = 0; i < n; i++) {
    int val; cin >> val;
    if (val == 1) {
        cout << "HARD";
        return;  // Early exit!
    }
}
cout << "EASY";
```

**💡 Key Points**:
- **Early return** pattern - exit as soon as condition is met
- Don't process remaining input unnecessarily

---

## 2. A_Lucky_Year
**Problem**: [Codeforces 808/A](https://codeforces.com/problemset/problem/808/A)

**Summary**: Find minimum years until next "lucky year" (only one non-zero digit).

**Solution Logic**:
1. Find number of digits and first digit
2. Next lucky year = (firstDigit + 1) × 10^(digits-1)
3. Answer = nextLucky - n

```cpp
// Examples of lucky years: 1, 2, ..., 9, 10, 20, ..., 90, 100, 200, ...
```

**💡 Key Points**:
- Extract first digit: divide by 10 until < 10
- Handle edge case: first digit = 9 → next is 10...0
- Pattern recognition in number theory problems

---

## 3. A_Word
**Problem**: [Codeforces 59/A](https://codeforces.com/problemset/problem/59/A)

**Summary**: If more uppercase → convert all to upper. Otherwise → convert all to lower.

**Solution Logic**:
```cpp
int lower = 0, upper = 0;
for (char c : s) {
    if (c >= 'a' && c <= 'z') lower++;
    else upper++;
}

if (lower >= upper)  // Note: >= means ties go to lowercase
    // convert to lowercase
```

**💡 Key Points**:
- `tolower(c)` and `toupper(c)` for conversion
- Tie-breaker: when equal, prefer lowercase (read problem carefully!)
- Character range check: `'a' <= c && c <= 'z'`

---

## 4. B_Even_Array
**Problem**: [Codeforces 1367/B](https://codeforces.com/problemset/problem/1367/B)

**Summary**: Make array "good" where a[i] and i have same parity. Find minimum swaps.

**Solution Logic**:
```cpp
// Count mismatches at even indices vs odd indices
// Count available even/odd numbers
// If counts don't match → impossible
// Answer = number_of_mismatches / 2
```

**💡 Key Points**:
- **Parity matching** - common pattern
- Count what you have vs what you need
- Mismatched pairs can swap → answer is mismatches / 2
- Impossible when counts don't balance

---

## 5. B_Queue_at_the_School
**Problem**: [Codeforces 266/B](https://codeforces.com/problemset/problem/266/B)

**Summary**: Boys (B) and Girls (G) in queue. Each second, every "BG" pair swaps. Simulate t seconds.

**Solution Logic**:
```cpp
for (int i = 0; i < t; i++) {
    for (int j = 0; j < n - 1; j++) {
        if (s[j] == 'B' && s[j+1] == 'G') {
            swap(s[j], s[j+1]);
            j++;  // Skip next position (already processed)
        }
    }
}
```

**💡 Key Points**:
- **Simulation** - sometimes brute force is the answer
- Important: after swap, skip the next character (`j++`)
- All swaps in one second are "simultaneous"

---

## 6. B_Symmetric_Matrix
**Problem**: [Codeforces 1426/B](https://codeforces.com/problemset/problem/1426/B)

**Summary**: Can we build m×m symmetric matrix using n 2×2 tiles?

**Solution Logic**:
```cpp
if (m % 2 != 0) return "NO";  // Odd size impossible

// Need at least one symmetric tile (where top-right == bottom-left)
for (int i = 0; i < n; i++) {
    if (arr[i][0][1] == arr[i][1][0]) return "YES";
}
return "NO";
```

**💡 Key Points**:
- Matrix symmetry: `a[i][j] == a[j][i]`
- For 2×2 tiles: diagonal elements can be anything, but [0][1] must equal [1][0]
- Odd-sized matrix can't be built with 2×2 tiles

---

## 7. C_Clock_and_Strings
**Problem**: [Codeforces 1971/C](https://codeforces.com/problemset/problem/1971/C)

**Summary**: Two strings on clock (1-12). Check if they intersect.

**Solution Logic**:
```cpp
// Build string of positions in clockwise order
for (int i = 1; i <= 12; i++) {
    if (i == a || i == b) s += "a";
    if (i == c || i == d) s += "b";
}
// Strings intersect if pattern is "abab" or "baba"
cout << (s == "abab" || s == "baba" ? "YES" : "NO");
```

**💡 Key Points**:
- **Geometric insight**: strings cross if endpoints alternate
- Convert geometry to string pattern matching
- Elegant solution avoids complex intersection math

---

## 8. C_Even_Odd_Positive_and_Negative
**Problem**: [Assiut Sheet](https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/c)

**Summary**: Count even, odd, positive, and negative numbers in array.

**💡 Key Points**:
- Basic counting with conditions
- Remember: 0 is even but neither positive nor negative!
- Use `% 2` for even/odd check

---

## 9. H_One_Prime
**Problem**: [Assiut Sheet](https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/H)

**Summary**: Check if a number is prime.

**Solution Logic**:
```cpp
if (n == 2 || n == 3) return true;
if (n < 2) return false;

for (int i = 2; i <= n / 2; i++) {  // Can optimize to sqrt(n)
    if (n % i == 0) return false;
}
return true;
```

**💡 Key Points**:
- **Optimization**: Only check up to √n, not n/2
- Edge cases: 0, 1 are NOT prime; 2 is the only even prime
- `i * i <= n` is better than `i <= sqrt(n)` (avoids floating point)

---

## 10. K_Divisors
**Problem**: [Assiut Sheet](https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/K)

**Summary**: Print all divisors of n.

**Solution Logic**:
```cpp
for (int i = 1; i <= n; i++) {
    if (n % i == 0) cout << i << endl;
}
```

**💡 Key Points**:
- Brute force: O(n)
- **Optimized**: Check up to √n, print both i and n/i
- Careful with perfect squares (don't print √n twice)

---

## 11. O_Fibonacci
**Problem**: [Assiut Sheet](https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/O)

**Summary**: Print nth Fibonacci number.

**Solution Logic**:
```cpp
ll fib[n];
fib[0] = 0;
fib[1] = 1;
for (int i = 2; i < n; i++)
    fib[i] = fib[i-1] + fib[i-2];
```

**💡 Key Points**:
- **DP approach** vs recursion (recursion is exponential!)
- Use `long long` - Fibonacci grows fast
- F(45) ≈ 10⁹, F(90) ≈ 10¹⁸ → overflow territory

---

## 12. R_Permutation_with_arrays
**Problem**: [Assiut Sheet](https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/R)

**Summary**: Check if two arrays are permutations of each other.

**Solution Logic**:
```cpp
sort(a, a + n);
sort(b, b + n);
// Compare element by element
for (int i = 0; i < n; i++)
    if (a[i] != b[i]) return false;
return true;
```

**💡 Key Points**:
- **Sort and compare** - classic technique
- Alternative: Use frequency map/array
- Arrays are permutations iff sorted versions are identical

---

## 13. Pattern Problems

### Pattern (Stars - Right aligned triangle)
```
*****
   *
  *
 *
*****
```

### Diamond Pattern
```
   *
  * *
 * * *
* * * *
* * * *
 * * *
  * *
   *
```

### Zigzag Numbers
```
1
2 3
6 5 4
7 8 9 10
```

**💡 Key Points for Pattern Problems**:
- Think in terms of **rows and columns**
- Identify: spaces before, characters, spaces after
- Use `reverse()` for alternating direction
- Nested loops: outer for rows, inner for columns
- Formula for spaces usually involves `(n - i - 1)` or similar

---

# Key Takeaways

## 🎯 Common Patterns Learned

### 1. Data Type Selection
```cpp
// ALWAYS think about overflow!
// int: up to ~2×10⁹
// long long: up to ~9×10¹⁸
// When multiplying, cast first: (ll)a * b
```

### 2. Early Exit Pattern
```cpp
// Don't continue when answer is found
if (condition) {
    cout << answer;
    return;
}
```

### 3. Parity Check
```cpp
n % 2 == 0  // even
n % 2 == 1  // odd (for positive n)
n & 1       // odd (bitwise, faster)
```

### 4. Divisibility
```cpp
a % b == 0  // a is divisible by b
```

### 5. Digit Extraction
```cpp
n % 10      // last digit
n / 10      // remove last digit
```

### 6. Character Case
```cpp
tolower(c)  // convert to lowercase
toupper(c)  // convert to uppercase
c >= 'a' && c <= 'z'  // is lowercase
c >= 'A' && c <= 'Z'  // is uppercase
```

### 7. Sorting for Comparison
```cpp
sort(a, a + n);
sort(b, b + n);
// Now compare sorted arrays
```

## ⚠️ Common Mistakes to Avoid

1. **Integer Overflow** - Use `long long` for large values
2. **Off-by-one errors** - Check loop bounds carefully
3. **Edge cases** - n=0, n=1, n=2 often special
4. **Tie-breakers** - Read problem statement for `>=` vs `>`
5. **Forgetting early return** - Can cause TLE or wrong answer
6. **Not reading full input** - Can mess up next test case

## 📈 Complexity Guidelines

| n limit | Safe complexity |
|---------|-----------------|
| ≤ 10⁶ | O(n log n) |
| ≤ 10⁴ | O(n²) |
| ≤ 500 | O(n³) |
| ≤ 20 | O(2ⁿ) |

---

> 💪 **Keep practicing! These fundamentals are the building blocks for harder problems.**

*Last Updated: February 2026*
