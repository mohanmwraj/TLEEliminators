# Module 05 & 06 Problem Summary
> **Theme**: Number Theory - GCD, LCM, Primes, Divisibility

---

## 📚 Module 05 - GCD, Coprime, and Prime Number Theory

### 1. A_Co_prime_Array
**📎 Problem**: [Codeforces 660A](https://codeforces.com/problemset/problem/660/A)

**Summary**: Given an array, make all adjacent pairs coprime (GCD = 1) by inserting minimum numbers.

**Solution Logic**:
- Key insight: **1 is coprime with every number** (gcd(1, n) = 1 for any n)
- Insert `1` between any two adjacent elements that aren't coprime
- Count pairs where gcd(a[i], a[i+1]) ≠ 1

**💡 Key Points**:
- GCD(a, b) = 1 means a and b are coprime
- 1 is the universal coprime number - always works as separator
- Use Euclidean algorithm for GCD: `gcd(a, b) = gcd(b, a % b)`

---

### 2. A_Divide_and_Conquer
**📎 Problem**: [Codeforces 1762A](https://codeforces.com/problemset/problem/1762/A)

**Summary**: Find minimum operations to change array sum parity by dividing elements by 2.

**Solution Logic**:
- Sum is odd only if count of odd numbers is odd
- If odd count is even → already achievable (answer = 0)
- Otherwise, find minimum divisions by 2 to flip any element's parity
  - For even numbers: divide until odd (count divisions)
  - For odd numbers: one division makes it even (but result is floor division)

**💡 Key Points**:
- **Parity trick**: sum parity depends on count of odd elements
- Dividing by 2 changes parity after certain steps
- Track minimum operations across all elements

---

### 3. A_Lucky_Division
**📎 Problem**: [Codeforces 122A](https://codeforces.com/problemset/problem/122/A)

**Summary**: Check if n is divisible by any "lucky number" (containing only digits 4 and 7).

**Solution Logic**:
- Generate all lucky numbers up to n (4, 7, 44, 47, 74, 77, 444, ...)
- Or iterate through all divisors and check if lucky
- Lucky check: all digits must be 4 or 7

```cpp
bool isLucky(int n) {
    while(n > 0) {
        if(n % 10 != 4 && n % 10 != 7) return false;
        n /= 10;
    }
    return true;
}
```

**💡 Key Points**:
- There are very few lucky numbers (2^k for k digits)
- Can precompute lucky numbers or check on the fly
- Digit extraction: `n % 10` gives last digit, `n /= 10` removes it

---

### 4. A_Maximum_GCD
**📎 Problem**: [Codeforces 1370A](https://codeforces.com/problemset/problem/1370/A)

**Summary**: Find maximum GCD of any two distinct numbers from 1 to n.

**Solution Logic**:
- **Key insight**: Maximum GCD is achieved by `n/2` and `n`
- GCD(n/2, n) = n/2 (when n is even, or floor(n/2) when odd)
- Answer is always `n / 2`

**💡 Key Points**:
- **Pattern recognition**: Don't brute force, find mathematical relation
- If `b = 2a`, then `gcd(a, b) = a`
- Maximize by choosing largest such pair: `(n/2, n)`

---

### 5. A_Noldbach_problem
**📎 Problem**: [Codeforces 17A](https://codeforces.com/problemset/problem/17/A)

**Summary**: Count primes p ≤ n where p = q + r + 1 for consecutive primes q, r.

**Solution Logic**:
1. Generate all primes up to n using sieve or trial division
2. For each pair of consecutive primes (p[i], p[i+1])
3. Check if p[i] + p[i+1] + 1 is also prime
4. Count such cases and compare with k

**💡 Key Points**:
- **Consecutive prime pairs**: (2,3), (3,5), (5,7), (7,11)...
- Sieve of Eratosthenes is efficient for prime generation
- Store primes in vector for easy consecutive access

---

### 6. A_Odd_Divisor
**📎 Problem**: [Codeforces 1475A](https://codeforces.com/problemset/problem/1475/A)

**Summary**: Check if n has any odd divisor greater than 1.

**Solution Logic**:
- **Key insight**: n has odd divisor > 1 ⟺ n is NOT a power of 2
- Remove all factors of 2: `while(n % 2 == 0) n /= 2`
- If remaining n > 1, it has odd divisor

```cpp
// Number is power of 2 check
bool isPowerOf2 = (n & (n-1)) == 0;  // Alternative method
```

**💡 Key Points**:
- **Powers of 2 have NO odd divisors** (except 1)
- Any composite number not a power of 2 has an odd prime factor
- Bit trick: `n & (n-1) == 0` checks if n is power of 2

---

### 7. B_GCD_Arrays
**📎 Problem**: [Codeforces 1629B](https://codeforces.com/contest/1629/problem/B)

**Summary**: With at most k operations (multiply any two elements), can you make GCD > 1?

**Solution Logic**:
- **Strategy**: Make all elements even (divisible by 2)
- Every second number is even, others are odd
- Number of operations needed = count of odd numbers
- Answer: YES if `odd_count ≤ k`

**💡 Key Points**:
- **2 is the most common prime factor** (50% of numbers are even)
- Multiplying two numbers combines their factors
- Edge case: single element already > 1 means GCD > 1

---

### 8. B_GCD_Problem
**📎 Problem**: [Codeforces 1617B](https://codeforces.com/problemset/problem/1617/B)

**Summary**: Split n into a + b + c where gcd(a,b) = gcd(b,c) = gcd(a,c) = 1.

**Solution Logic**:
- Fix c = 1 (since gcd(x, 1) = 1 for any x)
- Now find a + b = n - 1 where gcd(a, b) = 1
- **Consecutive integers are coprime**: gcd(k, k+1) = 1
- If n is even: use (n-1)/2 and (n-1)/2 + 1
- If n is odd: need consecutive odd numbers (both odd → coprime)

**💡 Key Points**:
- **Consecutive integers are always coprime**
- **Two consecutive odd numbers are coprime**: gcd(2k+1, 2k+3) = 1
- Fix one variable (c = 1) to simplify problem

---

### 9. B_Proper_Nutrition
**📎 Problem**: [Codeforces 898B](https://codeforces.com/problemset/problem/898/B)

**Summary**: Find non-negative integers x, y such that x·a + y·b = n (Linear Diophantine).

**Solution Logic**:
- Fix y, compute x = (n - y·b) / a
- Iterate y from 0 to n/b
- Check if (n - y·b) is divisible by a and non-negative

```cpp
for(y = 0; y * b <= n; ++y) {
    if((n - y * b) % a == 0) {
        x = (n - y * b) / a;
        // Found solution!
    }
}
```

**💡 Key Points**:
- **Linear Diophantine equation**: ax + by = c
- Solution exists iff gcd(a, b) | c
- Brute force one variable, compute the other
- Optimize: iterate over smaller coefficient

---

### 10. B_Square_Difference
**📎 Problem**: [Codeforces 1033B](https://codeforces.com/problemset/problem/1033/B)

**Summary**: Check if a² - b² is prime (a > b).

**Solution Logic**:
- **Factorization**: a² - b² = (a+b)(a-b)
- For result to be prime, one factor must be 1
- Since a > b ≥ 1, we need (a - b) = 1
- Then check if (a + b) is prime

```cpp
if((a - b == 1) && isPrime(a + b)) {
    cout << "YES";
}
```

**💡 Key Points**:
- **Difference of squares**: a² - b² = (a+b)(a-b)
- Prime = product of 1 and itself only
- Always factor algebraic expressions!
- Use efficient primality test: check divisors up to √n

---

## 📚 Module 06 - Advanced Divisibility and Modular Arithmetic

### 1. A_Array_Balancing
**📎 Problem**: [Codeforces 1661A](https://codeforces.com/problemset/problem/1661/A)

**Summary**: Minimize sum of |a[i] - a[i+1]| + |b[i] - b[i+1]| by optionally swapping a[i], b[i].

**Solution Logic**:
- **Greedy approach**: At each position, decide to swap or not
- Compare cost without swap vs with swap
- Swap if: `|a[i]-a[i+1]| + |b[i]-b[i+1]| > |a[i]-b[i+1]| + |b[i]-a[i+1]|`

**💡 Key Points**:
- **Local optimization** works for this problem
- Each decision is independent of future decisions
- When operations are reversible/independent, try greedy

---

### 2. A_Divisibility_Problem
**📎 Problem**: [Codeforces 1328A](https://codeforces.com/contest/1328/problem/A)

**Summary**: Find minimum x to add to a so that (a + x) is divisible by b.

**Solution Logic**:
- If a % b == 0, answer is 0
- Otherwise: x = b - (a % b)
- This makes (a + x) the next multiple of b

```cpp
int x = (a % b == 0) ? 0 : (b - a % b);
```

**💡 Key Points**:
- **Next multiple formula**: next_mult = ((a / b) + 1) * b
- **Distance to next multiple**: b - (a % b)
- Common pattern in modular arithmetic problems

---

### 3. A_Gregor_and_Cryptography
**📎 Problem**: [Codeforces 1549A](https://codeforces.com/contest/1549/problem/A)

**Summary**: For prime p, find a, b such that p % a == p % b (a ≠ b).

**Solution Logic**:
- **Key insight**: For any number N, (N + 1) % d = 1 for all divisors d of N
- For prime p: p % 2 = 1 (since p is odd, p > 2)
- p % (p-1) = 1 (since p = (p-1) + 1)
- Answer: a = 2, b = p - 1

**💡 Key Points**:
- **Property**: For divisors d of N, (N + 1) mod d = 1
- Primes > 2 are all odd
- Think about remainders when dividing by related numbers

---

### 4. B_K_th_Common_Divisor
**📎 Problem**: [AtCoder ABC120B](https://atcoder.jp/contests/abc120/tasks/abc120_b)

**Summary**: Find the k-th largest common divisor of a and b.

**Solution Logic**:
1. Find all common divisors: iterate 1 to min(a, b)
2. Check if both a % i == 0 and b % i == 0
3. Sort divisors, return the k-th from end

**💡 Key Points**:
- Common divisors are divisors of gcd(a, b)
- **Optimization**: Only check divisors up to √gcd(a, b)
- Store in sorted order, access by index

---

### 5. B_Longest_Divisors_Interval
**📎 Problem**: [Codeforces 1855B](https://codeforces.com/problemset/problem/1855/B)

**Summary**: Find longest interval [l, r] where all numbers l, l+1, ..., r divide n.

**Solution Logic**:
- **Key observation**: n divisible by 1,2,3,...,k means n divisible by LCM(1,2,...,k)
- LCM grows very fast: LCM(1..50) > 10^18
- Start from 1, find longest consecutive sequence of divisors

```cpp
int i = 1;
while(n % i == 0) i++;
cout << i - 1;  // Length of interval [1, i-1]
```

**💡 Key Points**:
- **LCM growth**: LCM(1,2,...,k) grows exponentially
- Answer is always small (≤ ~50 for n ≤ 10^18)
- Simple loop suffices - no need for complex algorithm

---

### 6. B_Multiplication_2
**📎 Problem**: [AtCoder ABC169B](https://atcoder.jp/contests/abc169/tasks/abc169_b)

**Summary**: Compute product of array, detect overflow (> 10^18) or return -1.

**Solution Logic**:
- Check for 0 first (product = 0)
- Before multiplying: check if `prod > LIMIT / arr[i]`
- If yes, would overflow → return -1

```cpp
ll ub = 1e18;
if(prod > ub / arr[i]) {
    cout << -1;  // Overflow
} else {
    prod *= arr[i];
}
```

**💡 Key Points**:
- **Overflow detection**: Check BEFORE multiplication
- If any element is 0, product is 0 (special case)
- `a * b > LIMIT` ⟺ `a > LIMIT / b` (safe check)

---

### 7. B_Vlad_and_Candies
**📎 Problem**: [Codeforces 1660B](https://codeforces.com/contest/1660/problem/B)

**Summary**: Check if candies can be eaten alternating (no same type twice consecutively).

**Solution Logic**:
- Sort the array, check top two elements
- If max - second_max > 1, impossible (must eat max twice consecutively)
- Edge case: n = 1 and count > 1 → impossible

```cpp
if(n == 1) return a[0] <= 1 ? "YES" : "NO";
return (a[n-1] - a[n-2] <= 1) ? "YES" : "NO";
```

**💡 Key Points**:
- **Greedy eating**: Always eat from largest pile
- Difference between top two determines feasibility
- Sort and analyze extremes

---

### 8. C_Anti_Division
**📎 Problem**: [AtCoder ABC131C](https://atcoder.jp/contests/abc131/tasks/abc131_c)

**Summary**: Count numbers in [A, B] NOT divisible by C or D.

**Solution Logic**:
- Use **Inclusion-Exclusion Principle**
- Count divisible by C: ⌊B/C⌋ - ⌊(A-1)/C⌋
- Count divisible by D: ⌊B/D⌋ - ⌊(A-1)/D⌋
- Count divisible by both (LCM): subtract once (added twice)

```cpp
removed = f(C) + f(D) - f(lcm(C, D));
answer = (B - A + 1) - removed;
```

**💡 Key Points**:
- **Counting in range [A,B]**: f(B) - f(A-1)
- **Inclusion-Exclusion**: |A∪B| = |A| + |B| - |A∩B|
- Divisible by both C and D = divisible by LCM(C, D)

---

### 9. C_Max_GCD_2
**📎 Problem**: [AtCoder JSC2021C](https://atcoder.jp/contests/jsc2021/tasks/jsc2021_c)

**Summary**: Find maximum GCD of any two numbers in range [A, B].

**Solution Logic**:
- **Key insight**: If [A, B] contains ≥ 2 multiples of g, then g is achievable
- Iterate g from B down to 1
- Check if ⌊B/g⌋ > ⌊(A-1)/g⌋ (means at least 2 multiples exist)

```cpp
for(int g = B; g >= 1; --g) {
    if((A + g - 1) / g < B / g) {  // ceil(A/g) < floor(B/g)
        return g;
    }
}
```

**💡 Key Points**:
- **Multiples in range**: Count of multiples of g in [1,N] is ⌊N/g⌋
- Start from maximum possible answer
- GCD(kg, (k+1)g) = g for consecutive multiples

---

### 10. C_Modulo_Summation
**📎 Problem**: [AtCoder ABC103C](https://atcoder.jp/contests/abc103/tasks/abc103_c)

**Summary**: Find maximum value of f(m) = Σ(m % a[i]) over all m.

**Solution Logic**:
- **Maximum of m % a[i]** is a[i] - 1 (achieved when m = a[i] - 1)
- We can achieve maximum for ALL terms simultaneously
- Choose m = LCM(all a[i]) - 1
- Answer = Σ(a[i] - 1) = sum - n

```cpp
ll answer = 0;
for(int i = 0; i < n; i++) {
    answer += (arr[i] - 1);
}
```

**💡 Key Points**:
- **Range of m % a**: [0, a-1], max is a-1
- **m = LCM - 1** gives remainder (a-1) for all divisors a
- No need to compute LCM, just sum (a[i] - 1)

---

### 11. C_Product_and_GCD
**📎 Problem**: [AtCoder Caddi2018](https://atcoder.jp/contests/caddi2018b/tasks/caddi2018_a)

**Summary**: Given product P of N numbers, find maximum possible GCD.

**Solution Logic**:
- If gcd(a1,...,aN) = g, then g^N divides P
- Maximum g is largest where g^N | P
- Using prime factorization: g = Π p_i^⌊e_i/N⌋
- Brute force: check each g, compute g^N, check divisibility

```cpp
for(g = 2; g <= 1e6; ++g) {
    ll pow = power(g, N);
    if(pow == -1) break;  // Overflow
    if(P % pow == 0) ans = g;
}
```

**💡 Key Points**:
- **If g is GCD, then g^N | P** (fundamental property)
- For large N (> 45), answer is always 1 (2^45 > 10^12)
- Prime factorization approach is more efficient

---

### 12. D_Divide_by_2_or_3
**📎 Problem**: [AtCoder ABC276D](https://atcoder.jp/contests/abc276/tasks/abc276_d)

**Summary**: Make all elements equal by dividing by 2 or 3. Find minimum operations or -1.

**Solution Logic**:
- Each number = 2^x · 3^y · k (where k has no factors of 2 or 3)
- All k values must be equal (else impossible)
- Target: reduce all to 2^min_x · 3^min_y · k
- Operations: sum of excess powers of 2 and 3

```cpp
g = gcd(all elements);
for each a[i]:
    temp = a[i] / g;
    count divisions by 2 and 3
    if(temp != 1) return -1;  // Has other prime factors
```

**💡 Key Points**:
- **Prime factorization insight**: Only 2s and 3s can be removed
- **GCD gives common factor** to reduce to
- If a[i]/gcd has factors other than 2,3 → impossible

---

### 13. Integer_Factorization_15_digits
**📎 Problem**: [SPOJ FACT0](https://www.spoj.com/problems/FACT0/)

**Summary**: Find complete prime factorization of N (up to 10^15).

**Solution Logic**:
1. Handle factor of 2 separately
2. Trial division for odd factors up to √N
3. If N > 1 after, it's a prime factor itself

```cpp
while(n % 2 == 0) { factors[2]++; n /= 2; }
for(ll i = 3; i * i <= n; i += 2) {
    while(n % i == 0) { factors[i]++; n /= i; }
}
if(n > 1) factors[n]++;
```

**💡 Key Points**:
- **Trial division complexity**: O(√N)
- Handle 2 separately, then only check odd numbers
- After all divisions, remaining n (if > 1) is prime
- For larger N, use Pollard's Rho algorithm

---

## 🎯 Module 05 & 06 Key Takeaways

### Number Theory Essentials

| Concept | Formula/Property |
|---------|------------------|
| GCD | gcd(a, b) = gcd(b, a % b) |
| LCM | lcm(a, b) = (a × b) / gcd(a, b) |
| Coprime | gcd(a, b) = 1 |
| Power of 2 | n & (n-1) == 0 |
| Consecutive coprime | gcd(n, n+1) = 1 always |

### Important Patterns

1. **Difference of Squares**: a² - b² = (a+b)(a-b)
2. **Multiples in Range [1,N]**: Count of multiples of d = ⌊N/d⌋
3. **Next Multiple**: next_mult(a, b) = a + (b - a%b)
4. **Inclusion-Exclusion**: |A∪B| = |A| + |B| - |A∩B|

### Problem-Solving Tips

1. **When dealing with GCD**:
   - 1 is coprime with everything
   - Consecutive numbers are always coprime
   - Factor the expression algebraically

2. **When dealing with divisibility**:
   - Use modular arithmetic properties
   - Count via floor division
   - Think about prime factorization

3. **Overflow Prevention**:
   - Check before multiplication: `a > LIMIT/b`
   - Use `long long` for intermediate results
   - Handle 0 cases separately

4. **Optimization Hints**:
   - LCM grows fast (≤50 consecutive numbers exceed 10^18)
   - Max GCD of pair in [1,n] is n/2
   - Trial division is O(√N) for factorization

### Common Mistakes to Avoid

- ❌ Integer overflow in multiplication
- ❌ Forgetting edge case when n = 1
- ❌ Not handling 0 in product calculations
- ❌ Using int instead of long long for large numbers
- ❌ Brute forcing when mathematical formula exists

---

> **📝 Note**: Module 05 focuses on GCD/coprime properties, while Module 06 extends to divisibility counting and modular arithmetic. Master these foundations for harder number theory problems!
