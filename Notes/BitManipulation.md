# 🔥 Bit Manipulation - Complete Guide for Competitive Programming

> **Goal**: Master (Codeforces) in 2 years  
> **Last Updated**: January 2026

---

## 📚 Table of Contents
1. [Basics & Binary Representation](#basics--binary-representation)
2. [Bitwise Operators](#bitwise-operators)
3. [Essential Tricks & Operations](#essential-tricks--operations)
4. [Power of 2 Operations](#power-of-2-operations)
5. [Bit Counting Techniques](#bit-counting-techniques)
6. [Subset Enumeration](#subset-enumeration)
7. [XOR Properties & Tricks](#xor-properties--tricks)
8. [Bitmask DP](#bitmask-dp)
9. [Advanced Techniques](#advanced-techniques)
10. [Common Patterns in CP](#common-patterns-in-cp)
11. [Practice Problems](#practice-problems)

---

## Basics & Binary Representation

### Number Systems
```
Decimal:  13 = 1×10¹ + 3×10⁰
Binary:   13 = 1101₂ = 1×2³ + 1×2² + 0×2¹ + 1×2⁰ = 8 + 4 + 0 + 1
```

### Bit Positions (0-indexed from right)
```
Binary:  1 1 0 1
Position: 3 2 1 0
Value:    8 4 2 1
```

### Range of n-bit numbers
- **Unsigned**: `0` to `2ⁿ - 1`
- **Signed** (2's complement): `-2ⁿ⁻¹` to `2ⁿ⁻¹ - 1`

| Type | Bits | Range |
|------|------|-------|
| `int` | 32 | -2³¹ to 2³¹-1 (~2×10⁹) |
| `long long` | 64 | -2⁶³ to 2⁶³-1 (~9×10¹⁸) |
| `unsigned int` | 32 | 0 to 2³²-1 (~4×10⁹) |

---

## Bitwise Operators

### Basic Operators

| Operator | Symbol | Description | Example |
|----------|--------|-------------|---------|
| AND | `&` | 1 if both bits are 1 | `5 & 3 = 1` (101 & 011 = 001) |
| OR | `\|` | 1 if at least one bit is 1 | `5 \| 3 = 7` (101 \| 011 = 111) |
| XOR | `^` | 1 if bits are different | `5 ^ 3 = 6` (101 ^ 011 = 110) |
| NOT | `~` | Flip all bits | `~5 = -6` (inverts all 32/64 bits) |
| Left Shift | `<<` | Shift bits left | `5 << 1 = 10` (101 → 1010) |
| Right Shift | `>>` | Shift bits right | `5 >> 1 = 2` (101 → 10) |

### Truth Table
```
A | B | A&B | A|B | A^B
0 | 0 |  0  |  0  |  0
0 | 1 |  0  |  1  |  1
1 | 0 |  0  |  1  |  1
1 | 1 |  1  |  1  |  0
```

### ⚠️ Operator Precedence (Common Pitfall!)
```cpp
// WRONG: == has higher precedence than &
if (x & 1 == 1)   // Parsed as: x & (1 == 1) → x & 1

// CORRECT: Use parentheses!
if ((x & 1) == 1)
```

**Precedence Order**: `~` > `<<, >>` > `&` > `^` > `|` > `==, !=`

---

## Essential Tricks & Operations

### 1. Check if i-th bit is set
```cpp
bool isSet = (n >> i) & 1;
// OR
bool isSet = n & (1LL << i);

// Example: n = 13 (1101), i = 2
// (13 >> 2) & 1 = (11) & 1 = 1 ✓ (bit 2 is set)
```

### 2. Set the i-th bit (make it 1)
```cpp
n = n | (1LL << i);
// OR
n |= (1LL << i);

// Example: n = 9 (1001), i = 1
// 9 | (1 << 1) = 1001 | 0010 = 1011 = 11
```

### 3. Clear the i-th bit (make it 0)
```cpp
n = n & ~(1LL << i);
// OR
n &= ~(1LL << i);

// Example: n = 13 (1101), i = 2
// 13 & ~(1 << 2) = 1101 & 1011 = 1001 = 9
```

### 4. Toggle the i-th bit (flip it)
```cpp
n = n ^ (1LL << i);
// OR
n ^= (1LL << i);

// Example: n = 13 (1101), i = 2
// 13 ^ (1 << 2) = 1101 ^ 0100 = 1001 = 9
```

### 5. Check if n is odd or even
```cpp
bool isOdd = n & 1;      // Last bit is 1 → odd
bool isEven = !(n & 1);  // Last bit is 0 → even

// Faster than n % 2!
```

### 6. Multiply/Divide by 2
```cpp
n << 1;  // n * 2
n >> 1;  // n / 2 (integer division)
n << k;  // n * 2^k
n >> k;  // n / 2^k

// Example: 5 << 3 = 5 * 8 = 40
```

### 7. Get the rightmost set bit (isolated)
```cpp
int rightmostBit = n & (-n);
// OR
int rightmostBit = n & ~(n - 1);

// Example: n = 12 (1100)
// 12 & (-12) = 1100 & 0100 = 0100 = 4
```

### 8. Turn off the rightmost set bit
```cpp
n = n & (n - 1);

// Example: n = 12 (1100)
// 12 & 11 = 1100 & 1011 = 1000 = 8

// ⭐ VERY USEFUL for counting set bits!
```

### 9. Check if n is a power of 2
```cpp
bool isPowerOf2 = n && !(n & (n - 1));
// OR
bool isPowerOf2 = n && ((n & -n) == n);

// Power of 2 has exactly one set bit
// Example: 8 (1000) → 8 & 7 = 1000 & 0111 = 0
```

### 10. Turn on all bits up to position i
```cpp
int mask = (1LL << (i + 1)) - 1;

// Example: i = 3
// (1 << 4) - 1 = 16 - 1 = 15 = 1111
```

### 11. Get the lowest i bits of n
```cpp
int lowest_i_bits = n & ((1LL << i) - 1);

// Example: n = 29 (11101), i = 3
// 29 & 7 = 11101 & 00111 = 00101 = 5
```

### 12. Clear all bits from position i to 0
```cpp
n = n & ~((1LL << (i + 1)) - 1);

// Example: n = 29 (11101), i = 2
// 29 & ~7 = 11101 & 11000 = 11000 = 24
```

### 13. Swap two numbers (without temp)
```cpp
a ^= b;
b ^= a;
a ^= b;

// Or in one line:
a ^= b ^= a ^= b;  // ⚠️ Undefined behavior in C++, avoid!
```

### 14. Check if two numbers have opposite signs
```cpp
bool oppositeSigns = (a ^ b) < 0;
// XOR of opposite signs → MSB is 1 → negative
```

### 15. Compute absolute value (branchless)
```cpp
int mask = n >> 31;  // -1 if negative, 0 if positive
int abs_n = (n + mask) ^ mask;
// Or: (n ^ mask) - mask
```

---

## Power of 2 Operations

### Check if power of 2
```cpp
bool isPow2(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

### Next power of 2 (>= n)
```cpp
int nextPow2(int n) {
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n + 1;
}

// Built-in (GCC):
int nextPow2(int n) {
    return n <= 1 ? 1 : 1 << (32 - __builtin_clz(n - 1));
}
```

### Log base 2 (position of highest set bit)
```cpp
// Built-in (GCC) - 0-indexed from left
int log2_floor = 31 - __builtin_clz(n);  // for int
int log2_floor = 63 - __builtin_clzll(n); // for long long

// Example: n = 13 (1101)
// 31 - __builtin_clz(13) = 31 - 28 = 3
```

---

## Bit Counting Techniques

### Built-in Functions (GCC)
```cpp
__builtin_popcount(n);    // Count set bits (int)
__builtin_popcountll(n);  // Count set bits (long long)

__builtin_clz(n);         // Count leading zeros (int)
__builtin_clzll(n);       // Count leading zeros (long long)

__builtin_ctz(n);         // Count trailing zeros (int)
__builtin_ctzll(n);       // Count trailing zeros (long long)

__builtin_parity(n);      // 1 if odd number of set bits, 0 otherwise
```

### Manual popcount (Brian Kernighan's Algorithm)
```cpp
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);  // Remove rightmost set bit
        count++;
    }
    return count;
}
// Time: O(number of set bits)
```

### Position of rightmost set bit (1-indexed)
```cpp
int pos = __builtin_ctz(n) + 1;
// OR
int pos = log2(n & -n) + 1;

// Example: n = 12 (1100)
// __builtin_ctz(12) + 1 = 2 + 1 = 3
```

### Position of highest set bit (1-indexed)
```cpp
int pos = 32 - __builtin_clz(n);
// OR
int pos = (int)log2(n) + 1;

// Example: n = 13 (1101)
// 32 - __builtin_clz(13) = 32 - 28 = 4
```

---

## STL `bitset<N>` - Fixed-Size Bit Container

### Declaration & Initialization
```cpp
#include <bitset>

bitset<32> b1;              // 32 bits, all initialized to 0
bitset<8> b2(42);           // From integer: 00101010
bitset<8> b3("11001010");   // From string (left to right = MSB to LSB)
bitset<8> b4(0b11001010);   // From binary literal (C++14)

// ⚠️ Size must be a compile-time constant!
// bitset<n> is INVALID if n is a variable
```

### Basic Operations
```cpp
bitset<8> b(42);  // 00101010

// Access
b[0];            // Get bit at position 0 (rightmost) → 0
b[1];            // Get bit at position 1 → 1
b.test(3);       // Same as b[3], but throws if out of range

// Modify
b.set();         // Set all bits to 1 → 11111111
b.set(3);        // Set bit 3 to 1
b.set(3, 0);     // Set bit 3 to 0
b.reset();       // Set all bits to 0 → 00000000
b.reset(3);      // Set bit 3 to 0
b.flip();        // Flip all bits
b.flip(3);       // Flip bit 3

// Query
b.count();       // Number of set bits (popcount)
b.size();        // Total number of bits (32 here)
b.any();         // True if any bit is set
b.none();        // True if no bit is set
b.all();         // True if all bits are set (C++11)
```

### Conversion
```cpp
bitset<8> b("11001010");

b.to_ulong();    // Convert to unsigned long → 202
b.to_ullong();   // Convert to unsigned long long (C++11)
b.to_string();   // Convert to string → "11001010"

// ⚠️ Throws overflow_error if value doesn't fit in ulong/ullong
```

### Bitwise Operations
```cpp
bitset<8> a(0b11001010);
bitset<8> b(0b10101100);

a & b;           // AND → 10001000
a | b;           // OR  → 11101110
a ^ b;           // XOR → 01100110
~a;              // NOT → 00110101

a &= b;          // Compound assignment versions
a |= b;
a ^= b;

a << 2;          // Left shift → 00101000
a >> 2;          // Right shift → 00110010
a <<= 2;         // Shift and assign
a >>= 2;
```

### ⭐ Finding Set Bits Efficiently
```cpp
bitset<64> b(0b1010100);

// Find first set bit (from position 0)
int firstSet = b._Find_first();  // Returns 2 (GCC extension)
// Returns b.size() if no bit is set

// Find next set bit after position pos
int nextSet = b._Find_next(2);   // Returns 4 (GCC extension)
// Returns b.size() if no more bits

// Iterate through all set bits
for (int i = b._Find_first(); i < b.size(); i = b._Find_next(i)) {
    cout << i << " ";  // Outputs: 2 4 6
}
```

### I/O Operations
```cpp
bitset<8> b;
cin >> b;         // Input binary string directly
cout << b;        // Output as binary string

// Example: Input "10101" → b = 00010101
```

---

## Comparison: `bitset<N>` vs `vector<bool>` vs `bool arr[N]`

| Feature | `bitset<N>` | `vector<bool>` | `bool arr[N]` |
|---------|-------------|----------------|---------------|
| **Size** | Compile-time constant | Runtime (dynamic) | Compile-time (VLA in C99) |
| **Memory** | N bits (~N/8 bytes) | ~N bits (packed) | N bytes |
| **Cache** | Very efficient | Efficient | Less efficient |
| **Bitwise ops** | ✅ Native (`&`, `\|`, `^`) | ❌ Manual loop | ❌ Manual loop |
| **`count()`** | ✅ O(N/64) optimized | ❌ O(N) loop | ❌ O(N) loop |
| **Random access** | O(1) | O(1) | O(1) |
| **Set/Reset all** | O(N/64) | O(N) | O(N) |
| **STL compatible** | Partially | Yes | No |

### Memory Comparison
```cpp
// For N = 10^6 bits:
bitset<1000000> b;      // ~125 KB (N/8 bytes)
vector<bool> v(1e6);    // ~125 KB (packed, but varies)
bool arr[1000000];      // ~1 MB (1 byte per bool)

// bitset and vector<bool> use 8x less memory!
```

### Performance Comparison
```cpp
// Counting set bits in 10^6 elements:

// bitset - FASTEST (uses popcount on 64-bit chunks)
bitset<1000000> b;
int cnt = b.count();  // ~15,625 operations (N/64)

// vector<bool> - SLOW
vector<bool> v(1e6);
int cnt = count(v.begin(), v.end(), true);  // 10^6 operations

// bool array - SLOW
bool arr[1000000];
int cnt = 0;
for (int i = 0; i < 1e6; i++) cnt += arr[i];  // 10^6 operations
```

### Bitwise Operations Speed
```cpp
// XOR two arrays of 10^6 bits:

// bitset - FASTEST (operates on 64-bit words)
bitset<1000000> a, b;
a ^= b;  // ~15,625 XOR operations

// vector<bool> - SLOW
vector<bool> va(1e6), vb(1e6);
for (int i = 0; i < 1e6; i++) va[i] = va[i] ^ vb[i];  // 10^6 ops

// bool array - SLOW (same as vector<bool>)
```

### When to Use Each?

| Use Case | Best Choice |
|----------|-------------|
| Fixed size known at compile time | `bitset<N>` |
| Size determined at runtime | `vector<bool>` or manual `vector<uint64_t>` |
| Need fast bitwise operations | `bitset<N>` |
| Need fast `count()` | `bitset<N>` |
| Simple flag array, no bit ops needed | `vector<bool>` |
| Need pointer to elements | `bool arr[N]` (vector<bool> has proxy issues) |
| Interop with C APIs | `bool arr[N]` |
| N > 10^7 and dynamic | Manual `vector<uint64_t>` with bit ops |

### ⚠️ `vector<bool>` Pitfalls
```cpp
vector<bool> v(10);

// ❌ FAILS - doesn't return actual bool reference
bool* ptr = &v[0];  // Compilation error!

// ❌ FAILS - auto deduces proxy type
auto bit = v[0];    // bit is vector<bool>::reference, not bool!

// ✅ CORRECT
bool bit = v[0];    // Explicit bool conversion
```

### Custom Bitset for Runtime Size
```cpp
// When you need runtime-sized bitset with fast operations:
class DynamicBitset {
    vector<uint64_t> data;
    int n;
public:
    DynamicBitset(int size) : n(size), data((size + 63) / 64, 0) {}
    
    void set(int i) { data[i / 64] |= (1ULL << (i % 64)); }
    void reset(int i) { data[i / 64] &= ~(1ULL << (i % 64)); }
    bool test(int i) { return data[i / 64] & (1ULL << (i % 64)); }
    
    int count() {
        int cnt = 0;
        for (auto x : data) cnt += __builtin_popcountll(x);
        return cnt;
    }
    
    DynamicBitset& operator^=(DynamicBitset& other) {
        for (int i = 0; i < data.size(); i++)
            data[i] ^= other.data[i];
        return *this;
    }
};
```

---

## Subset Enumeration

### Iterate through all subsets of {0, 1, ..., n-1}
```cpp
for (int mask = 0; mask < (1 << n); mask++) {
    // Process subset represented by mask
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            // Element i is in the subset
        }
    }
}
```

### ⭐ Iterate through all subsets of a given set
```cpp
// Iterate all subsets of mask (including empty set)
for (int sub = mask; ; sub = (sub - 1) & mask) {
    // Process subset 'sub'
    if (sub == 0) break;
}

// Include empty set explicitly
int sub = mask;
do {
    // Process subset 'sub'
    sub = (sub - 1) & mask;
} while (sub != mask);  // Wraps around when sub becomes -1 & mask = mask

// Time: O(3^n) for all masks - because each element is in mask, in sub, or neither
```

### Iterate through all masks with exactly k bits set
```cpp
// Gosper's Hack - next permutation of bits
void iterateKBits(int n, int k) {
    int mask = (1 << k) - 1;  // Start with lowest k bits set
    while (mask < (1 << n)) {
        // Process mask
        
        // Get next permutation
        int c = mask & -mask;
        int r = mask + c;
        mask = (((r ^ mask) >> 2) / c) | r;
    }
}
```

### Print all elements in a subset
```cpp
void printSubset(int mask) {
    while (mask) {
        int bit = __builtin_ctz(mask);
        cout << bit << " ";
        mask &= (mask - 1);  // Remove this bit
    }
}
```

---

## XOR Properties & Tricks

### Fundamental Properties
```cpp
a ^ 0 = a           // XOR with 0 → unchanged
a ^ a = 0           // XOR with itself → 0
a ^ b = b ^ a       // Commutative
(a ^ b) ^ c = a ^ (b ^ c)  // Associative
```

### ⭐ XOR of all elements
```cpp
// If a number appears twice, it cancels out!
// Find the single element that appears once
int findSingle(vector<int>& arr) {
    int result = 0;
    for (int x : arr) result ^= x;
    return result;
}
```

### XOR from 1 to n (Pattern!)
```cpp
int xorUptoN(int n) {
    switch (n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }
}

// Pattern: n%4 → result
// 0 → n
// 1 → 1
// 2 → n+1
// 3 → 0

// Example: XOR(1 to 7) = n%4=3 → 0
// Verify: 1^2^3^4^5^6^7 = 0 ✓
```

### XOR in range [L, R]
```cpp
int xorRange(int L, int R) {
    return xorUptoN(R) ^ xorUptoN(L - 1);
}
```

### Find two unique elements (all others appear twice)
```cpp
void findTwoUnique(vector<int>& arr) {
    int xorAll = 0;
    for (int x : arr) xorAll ^= x;
    
    // xorAll = a ^ b (the two unique numbers)
    // Find rightmost set bit (where a and b differ)
    int rightmostBit = xorAll & (-xorAll);
    
    int a = 0, b = 0;
    for (int x : arr) {
        if (x & rightmostBit)
            a ^= x;
        else
            b ^= x;
    }
    // a and b are the two unique elements
}
```

### Prefix XOR Array
```cpp
// prefix[i] = arr[0] ^ arr[1] ^ ... ^ arr[i-1]
vector<int> prefix(n + 1);
prefix[0] = 0;
for (int i = 0; i < n; i++)
    prefix[i + 1] = prefix[i] ^ arr[i];

// XOR of range [L, R]
int rangeXOR = prefix[R + 1] ^ prefix[L];
```

---

## Bitmask DP

### Classic: Traveling Salesman Problem (TSP)
```cpp
// dp[mask][i] = min cost to visit all cities in mask, ending at city i
int n;
vector<vector<int>> dist;  // dist[i][j] = distance from i to j

int tsp() {
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));
    dp[1][0] = 0;  // Start at city 0
    
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int last = 0; last < n; last++) {
            if (!(mask & (1 << last))) continue;
            if (dp[mask][last] == INF) continue;
            
            for (int next = 0; next < n; next++) {
                if (mask & (1 << next)) continue;
                int newMask = mask | (1 << next);
                dp[newMask][next] = min(dp[newMask][next], 
                                        dp[mask][last] + dist[last][next]);
            }
        }
    }
    
    int ans = INF;
    for (int i = 0; i < n; i++)
        ans = min(ans, dp[(1 << n) - 1][i] + dist[i][0]);
    return ans;
}
```

### Subset Sum with Bitmask
```cpp
// dp[mask] = true if subset represented by mask achieves target sum
vector<bool> dp(1 << n, false);
dp[0] = true;

for (int mask = 0; mask < (1 << n); mask++) {
    if (!dp[mask]) continue;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            dp[mask | (1 << i)] = true;
        }
    }
}
```

### Assignment Problem (Hungarian alternative)
```cpp
// dp[mask] = min cost to assign first popcount(mask) people to jobs in mask
vector<int> dp(1 << n, INF);
dp[0] = 0;

for (int mask = 0; mask < (1 << n); mask++) {
    int person = __builtin_popcount(mask);
    if (person >= n) continue;
    
    for (int job = 0; job < n; job++) {
        if (mask & (1 << job)) continue;
        dp[mask | (1 << job)] = min(dp[mask | (1 << job)], 
                                     dp[mask] + cost[person][job]);
    }
}

cout << dp[(1 << n) - 1];
```

### SOS DP (Sum over Subsets)
```cpp
// dp[mask] = sum of f[sub] for all subsets sub of mask
// O(n * 2^n) instead of O(3^n)

for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < (1 << n); mask++) {
        if (mask & (1 << i)) {
            dp[mask] += dp[mask ^ (1 << i)];
        }
    }
}
```

---

## Advanced Techniques

### Gray Code (adjacent codes differ by 1 bit)
```cpp
int grayCode(int n) {
    return n ^ (n >> 1);
}

int inverseGray(int g) {
    int n = 0;
    while (g) {
        n ^= g;
        g >>= 1;
    }
    return n;
}

// Generate all gray codes of n bits
for (int i = 0; i < (1 << n); i++) {
    int gray = i ^ (i >> 1);
    // Process gray code
}
```

### Bit Reversal
```cpp
unsigned int reverseBits(unsigned int n) {
    n = ((n >> 1) & 0x55555555) | ((n & 0x55555555) << 1);
    n = ((n >> 2) & 0x33333333) | ((n & 0x33333333) << 2);
    n = ((n >> 4) & 0x0F0F0F0F) | ((n & 0x0F0F0F0F) << 4);
    n = ((n >> 8) & 0x00FF00FF) | ((n & 0x00FF00FF) << 8);
    n = (n >> 16) | (n << 16);
    return n;
}
```

### Bitwise AND/OR of Range [L, R]
```cpp
// AND of all numbers from L to R
int rangeAND(int L, int R) {
    while (R > L) {
        R &= (R - 1);  // Remove rightmost bit
    }
    return R;
}

// Common prefix approach
int rangeAND(int L, int R) {
    int shift = 0;
    while (L != R) {
        L >>= 1;
        R >>= 1;
        shift++;
    }
    return L << shift;
}
```

### Maximum XOR of Two Numbers in Array
```cpp
// Using Trie - O(n * 32)
struct TrieNode {
    TrieNode* children[2] = {nullptr, nullptr};
};

class MaxXOR {
    TrieNode* root = new TrieNode();
    
public:
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit])
                node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
    }
    
    int maxXorWith(int num) {
        TrieNode* node = root;
        int result = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppBit = 1 - bit;
            if (node->children[oppBit]) {
                result |= (1 << i);
                node = node->children[oppBit];
            } else {
                node = node->children[bit];
            }
        }
        return result;
    }
};
```

### Minimum XOR Pair
```cpp
// Sort the array, min XOR is between adjacent elements
// Because XOR of adjacent sorted numbers tends to be smaller
sort(arr.begin(), arr.end());
int minXor = INT_MAX;
for (int i = 1; i < n; i++) {
    minXor = min(minXor, arr[i] ^ arr[i-1]);
}
```

---

## Common Patterns in CP

### Pattern 1: Bitwise Operations on Each Bit Position
```cpp
// Process each bit independently
// Useful for AND, OR, XOR problems

for (int bit = 0; bit < 30; bit++) {  // or 60 for long long
    int countOnes = 0;
    for (int x : arr) {
        if (x & (1 << bit)) countOnes++;
    }
    // Process based on countOnes and (n - countOnes) zeros
}
```

### Pattern 2: XOR Pair Counting
```cpp
// Count pairs with XOR having bit i set
// Pairs where exactly one has bit i set

for (int bit = 0; bit < 30; bit++) {
    int ones = 0, zeros = 0;
    for (int x : arr) {
        if (x & (1 << bit)) ones++;
        else zeros++;
    }
    // Pairs with bit i set = ones * zeros
    contribution += (1LL << bit) * ones * zeros;
}
```

### Pattern 3: Find Missing/Duplicate
```cpp
// Array of 1 to n with one missing
int findMissing(vector<int>& arr, int n) {
    int xorAll = 0;
    for (int i = 1; i <= n; i++) xorAll ^= i;
    for (int x : arr) xorAll ^= x;
    return xorAll;  // Missing number
}

// Array of 1 to n with one duplicate
int findDuplicate(vector<int>& arr, int n) {
    int xorAll = 0;
    for (int i = 1; i <= n - 1; i++) xorAll ^= i;
    for (int x : arr) xorAll ^= x;
    return xorAll;  // Duplicate number
}
```

### Pattern 4: Maximize/Minimize XOR with Constraints
```cpp
// Greedy: Build answer bit by bit from MSB
// Check if setting current bit to 1 (for max) or 0 (for min) is feasible
```

### Pattern 5: Bitmasking for Small Sets
```cpp
// When n ≤ 20, use bitmask to represent subsets
// When n ≤ 15-18, bitmask DP is feasible
// Time complexity: O(2^n) or O(n * 2^n)
```

---

## Quick Reference Card

```cpp
// ============= COMMON OPERATIONS =============
n & 1              // Check if odd
n & (n - 1)        // Remove rightmost set bit
n & (-n)           // Isolate rightmost set bit
n | (1 << i)       // Set bit i
n & ~(1 << i)      // Clear bit i
n ^ (1 << i)       // Toggle bit i
(n >> i) & 1       // Get bit i
(1 << n) - 1       // n bits all set to 1

// ============= BUILT-IN FUNCTIONS =============
__builtin_popcount(n)     // Count set bits
__builtin_ctz(n)          // Trailing zeros (rightmost set bit position)
__builtin_clz(n)          // Leading zeros
__builtin_parity(n)       // Parity (1 if odd number of set bits)

// ============= COMMON CHECKS =============
n > 0 && !(n & (n-1))    // Is power of 2?
(n & (1 << i)) != 0      // Is bit i set?

// ============= XOR PROPERTIES =============
a ^ 0 = a
a ^ a = 0
a ^ b ^ a = b
XOR(1 to n): n%4 → [n, 1, n+1, 0]
```

---

## Practice Problems

### Easy
- [ ] [Codeforces 1097A - Gennady and a Card Game](https://codeforces.com/problemset/problem/1097/A)
- [ ] [Codeforces 1527A - And Then There Were K](https://codeforces.com/problemset/problem/1527/A)
- [ ] [LeetCode 136 - Single Number](https://leetcode.com/problems/single-number/)
- [ ] [LeetCode 191 - Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)

### Medium
- [ ] [Codeforces 1285D - Dr. Evil Underscores](https://codeforces.com/problemset/problem/1285/D)
- [ ] [Codeforces 1879D - Sum of XOR Functions](https://codeforces.com/problemset/problem/1879/D)
- [ ] [Codeforces 1614D1 - Divan and Kostomuksha](https://codeforces.com/problemset/problem/1614/D1)
- [ ] [LeetCode 421 - Maximum XOR of Two Numbers](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)
- [ ] [LeetCode 1863 - Sum of All Subset XOR Totals](https://leetcode.com/problems/sum-of-all-subset-xor-totals/)

### Hard
- [ ] [Codeforces 1554C - Mikasa](https://codeforces.com/problemset/problem/1554/C)
- [ ] [Codeforces 1823F - Random Walk](https://codeforces.com/problemset/problem/1823/F)
- [ ] [Codeforces 165E - Compatible Numbers](https://codeforces.com/problemset/problem/165/E) (SOS DP)
- [ ] [AtCoder ABC 187E - Through Path](https://atcoder.jp/contests/abc187/tasks/abc187_e)

### Bitmask DP
- [ ] [CSES - Hamiltonian Flights](https://cses.fi/problemset/task/1690)
- [ ] [Codeforces 580D - Kefa and Dishes](https://codeforces.com/problemset/problem/580/D)
- [ ] [LeetCode 1986 - Minimum Number of Work Sessions](https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/)

---

## ⚡ Pro Tips

1. **Use `1LL` for 64-bit shifts**: `1 << 40` overflows, use `1LL << 40`
2. **Parenthesize bitwise ops**: `x & 1 == 1` is `x & (1 == 1)`, not `(x & 1) == 1`
3. **Avoid shifting by ≥ word size**: `1 << 32` is undefined behavior for 32-bit int
4. **Right shift of negatives**: Implementation-defined; avoid or use unsigned
5. **n ≤ 20**: Bitmask enumeration feasible
6. **n ≤ 15-18**: Bitmask DP feasible
7. **Think bit-by-bit**: Many problems become easier when you consider each bit position independently

---

> 💡 **Remember**: Master these techniques and you'll handle 80% of bit manipulation problems in contests!

*Happy Coding & Good Luck on your Master journey! 🚀*
