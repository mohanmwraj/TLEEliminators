# 🚀 C++ Complete Reference for Competitive Programming

> **Goal**: Master (Codeforces) in 2 years  
> **Last Updated**: February 2026

---

## 📚 Table of Contents
1. [Fast I/O & Template](#fast-io--template)
2. [Data Types & Limits](#data-types--limits)
3. [STL Containers](#stl-containers)
4. [STL Algorithms](#stl-algorithms)
5. [Strings](#strings)
6. [Math Functions](#math-functions)
7. [Useful Macros & Shortcuts](#useful-macros--shortcuts)
8. [Lambda Functions](#lambda-functions)
9. [Custom Comparators](#custom-comparators)
10. [Policy Based Data Structures](#policy-based-data-structures)
11. [Common Patterns & Tricks](#common-patterns--tricks)
12. [Time Complexity Reference](#time-complexity-reference)
13. [Debugging Tips](#debugging-tips)
14. [Common Mistakes to Avoid](#common-mistakes-to-avoid)

---

## Fast I/O & Template

### Competitive Programming Template
```cpp
#include <bits/stdc++.h>
using namespace std;

// Type aliases
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vpii = vector<pii>;

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

// Macros
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)

void solve() {
    // Your code here
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
```

### Fast I/O Explained
```cpp
ios::sync_with_stdio(false);  // Disable sync with C stdio (faster)
cin.tie(nullptr);             // Untie cin from cout (no flush before cin)
cout.tie(nullptr);            // Optional: untie cout

// ⚠️ After this, DON'T mix cin/cout with scanf/printf!
```

### Input Methods
```cpp
// Basic input
int n; cin >> n;
string s; cin >> s;           // Reads until whitespace
getline(cin, s);              // Reads entire line (including spaces)

// After cin >> x, use cin.ignore() before getline
cin >> n;
cin.ignore();                 // Ignore the newline character
getline(cin, s);

// Read until EOF
while (cin >> n) { /* process */ }

// Read n integers into vector
vi a(n);
for (int& x : a) cin >> x;

// Read 2D grid
vvi grid(n, vi(m));
for (auto& row : grid)
    for (int& x : row) cin >> x;

// Read pairs
int x, y; cin >> x >> y;
pii p; cin >> p.F >> p.S;
```

### Output Methods
```cpp
// Basic output
cout << x << "\n";            // Faster than endl
cout << x << " " << y << "\n";

// Formatted output
cout << fixed << setprecision(9) << 3.14159265358979;  // 3.141592654

// Print vector
for (int x : v) cout << x << " ";
cout << "\n";

// Print YES/NO
cout << (condition ? "YES" : "NO") << "\n";

// Flush output (rarely needed)
cout << flush;
cout.flush();
```

---

## Data Types & Limits

### Integer Types
| Type | Bytes | Range | Max Value |
|------|-------|-------|-----------|
| `int` | 4 | -2³¹ to 2³¹-1 | ~2.1×10⁹ |
| `unsigned int` | 4 | 0 to 2³²-1 | ~4.3×10⁹ |
| `long long` | 8 | -2⁶³ to 2⁶³-1 | ~9.2×10¹⁸ |
| `unsigned long long` | 8 | 0 to 2⁶⁴-1 | ~1.8×10¹⁹ |
| `__int128` | 16 | -2¹²⁷ to 2¹²⁷-1 | ~1.7×10³⁸ |

### Floating Point Types
| Type | Bytes | Precision | Range |
|------|-------|-----------|-------|
| `float` | 4 | ~7 digits | ~3.4×10³⁸ |
| `double` | 8 | ~15 digits | ~1.8×10³⁰⁸ |
| `long double` | 16 | ~18-21 digits | ~1.2×10⁴⁹³² |

### Type Limits
```cpp
#include <climits>
#include <cfloat>

INT_MAX;      // 2147483647
INT_MIN;      // -2147483648
LLONG_MAX;    // 9223372036854775807
LLONG_MIN;    // -9223372036854775808

// Or use numeric_limits
numeric_limits<int>::max();
numeric_limits<int>::min();
numeric_limits<double>::infinity();
```

### ⚠️ Overflow Prevention
```cpp
// WRONG: Overflow in multiplication
int a = 1e5, b = 1e5;
int c = a * b;  // Overflow!

// CORRECT: Cast to long long first
ll c = (ll)a * b;
ll c = 1LL * a * b;

// WRONG: Overflow in addition for array index
int i = 1e9, j = 1e9;
int mid = (i + j) / 2;  // Overflow!

// CORRECT
int mid = i + (j - i) / 2;
// Or
ll mid = ((ll)i + j) / 2;
```

---

## STL Containers

### 1. `vector<T>` - Dynamic Array
```cpp
// Declaration
vector<int> v;                    // Empty vector
vector<int> v(n);                 // n elements, default initialized (0)
vector<int> v(n, x);              // n elements, all initialized to x
vector<int> v = {1, 2, 3, 4, 5};  // Initializer list
vector<int> v(arr, arr + n);      // From C array
vector<int> v2(v1);               // Copy constructor
vector<int> v2(v1.begin(), v1.end());  // From iterators

// 2D vector
vector<vector<int>> v(n, vector<int>(m, 0));  // n x m, all 0
vvi adj(n);  // Adjacency list

// Access
v[i];                 // O(1), no bounds checking
v.at(i);              // O(1), throws if out of bounds
v.front();            // First element
v.back();             // Last element
v.data();             // Pointer to underlying array

// Size
v.size();             // Number of elements
v.empty();            // True if empty
v.capacity();         // Current allocated capacity
v.max_size();         // Maximum possible size

// Modifiers
v.push_back(x);       // Add to end, O(1) amortized
v.emplace_back(x);    // Construct in place (faster for objects)
v.pop_back();         // Remove last, O(1)
v.insert(it, x);      // Insert before iterator, O(n)
v.insert(it, n, x);   // Insert n copies of x
v.insert(it, first, last);  // Insert range
v.erase(it);          // Remove element, O(n)
v.erase(first, last); // Remove range
v.clear();            // Remove all elements
v.resize(n);          // Resize to n elements
v.resize(n, x);       // Resize, fill new elements with x
v.assign(n, x);       // Replace with n copies of x
v.swap(v2);           // Swap contents, O(1)

// Iterators
v.begin(), v.end();           // Forward iterators
v.rbegin(), v.rend();         // Reverse iterators
v.cbegin(), v.cend();         // Const iterators

// Memory
v.reserve(n);         // Pre-allocate capacity (avoid reallocations)
v.shrink_to_fit();    // Release unused memory
```

### 2. `array<T, N>` - Fixed-Size Array
```cpp
array<int, 5> a = {1, 2, 3, 4, 5};
array<int, 5> a{};    // All zeros

a[i];                 // Access
a.fill(x);            // Fill all with x
a.size();             // Always N
a.front(); a.back();

// Advantages over C array:
// - Knows its size
// - Can be copied with =
// - Can be compared with ==, <, etc.
// - Works with STL algorithms
```

### 3. `string` - Character Sequence
```cpp
// Declaration
string s;                     // Empty string
string s(n, 'a');             // n copies of 'a'
string s = "hello";
string s2(s);                 // Copy
string s2(s, pos, len);       // Substring
string s(it1, it2);           // From iterators

// Access
s[i];                 // O(1)
s.at(i);              // Bounds checked
s.front(); s.back();

// Size
s.size(); s.length(); // Same thing
s.empty();

// Modifiers
s += 'c';             // Append char
s += "str";           // Append string
s.push_back('c');
s.pop_back();
s.append(s2);
s.append(n, 'c');
s.insert(pos, s2);
s.insert(pos, n, 'c');
s.erase(pos, len);
s.replace(pos, len, s2);
s.clear();
s.resize(n);
s.resize(n, 'c');

// Substring & Search
s.substr(pos);        // From pos to end
s.substr(pos, len);   // From pos, length len
s.find(s2);           // First occurrence, string::npos if not found
s.find(s2, pos);      // Search from pos
s.rfind(s2);          // Last occurrence
s.find_first_of("aeiou");    // First vowel position
s.find_last_of("aeiou");
s.find_first_not_of("0123456789");

// Comparison
s1 == s2; s1 != s2;
s1 < s2;              // Lexicographic comparison
s.compare(s2);        // Returns <0, 0, or >0

// Conversion
stoi(s);              // String to int
stoll(s);             // String to long long
stod(s);              // String to double
to_string(123);       // Number to string

// C-string
s.c_str();            // Returns const char*
```

### 4. `pair<T1, T2>` - Two Elements
```cpp
// Declaration
pair<int, int> p;
pair<int, int> p(1, 2);
pair<int, int> p = {1, 2};
auto p = make_pair(1, 2);

// Access
p.first; p.second;
p.F; p.S;             // With macros

// Comparison (lexicographic: first, then second)
p1 == p2; p1 != p2;
p1 < p2;              // Compares first, then second

// Structured binding (C++17)
auto [x, y] = p;

// Useful for sorting by two criteria
vector<pair<int, int>> v;
sort(all(v));         // Sort by first, then second
```

### 5. `tuple<T...>` - Multiple Elements
```cpp
// Declaration
tuple<int, string, double> t(1, "hello", 3.14);
auto t = make_tuple(1, "hello", 3.14);

// Access
get<0>(t);            // First element
get<1>(t);            // Second element

// Structured binding (C++17)
auto [a, b, c] = t;

// Tie (for comparison or assignment)
tie(a, b, c) = t;
tie(a, b) = make_tuple(b, a);  // Swap

// Comparison (lexicographic)
t1 < t2;
```

### 6. `set<T>` - Ordered Unique Elements
```cpp
// Declaration
set<int> s;
set<int> s = {3, 1, 4, 1, 5};  // {1, 3, 4, 5} (sorted, unique)
set<int, greater<int>> s;      // Descending order

// Size
s.size();
s.empty();

// Modifiers
s.insert(x);          // O(log n), returns pair<iterator, bool>
s.emplace(x);         // Construct in place
s.erase(x);           // Remove by value, O(log n)
s.erase(it);          // Remove by iterator, O(1) amortized
s.erase(it1, it2);    // Remove range
s.clear();

// Lookup
s.find(x);            // Returns iterator, O(log n)
s.count(x);           // 0 or 1
s.contains(x);        // C++20: true/false

// Bounds (VERY USEFUL!)
s.lower_bound(x);     // Iterator to first element >= x
s.upper_bound(x);     // Iterator to first element > x

// Example: Find smallest element > x
auto it = s.upper_bound(x);
if (it != s.end()) cout << *it;

// Example: Find largest element <= x
auto it = s.upper_bound(x);
if (it != s.begin()) cout << *prev(it);

// Example: Find largest element < x
auto it = s.lower_bound(x);
if (it != s.begin()) cout << *prev(it);
```

### 7. `multiset<T>` - Ordered Elements with Duplicates
```cpp
multiset<int> ms;
ms.insert(5);
ms.insert(5);         // Can have duplicates
ms.count(5);          // Returns count of 5s

// ⚠️ erase(x) removes ALL occurrences of x
ms.erase(5);          // Removes ALL 5s

// Remove only ONE occurrence
auto it = ms.find(5);
if (it != ms.end()) ms.erase(it);

// Range of equal elements
auto [lo, hi] = ms.equal_range(5);
// lo = lower_bound, hi = upper_bound
```

### 8. `map<K, V>` - Ordered Key-Value Pairs
```cpp
// Declaration
map<string, int> m;
map<string, int> m = {{"one", 1}, {"two", 2}};

// Access & Insert
m["key"] = value;     // Insert or update, O(log n)
m["key"];             // ⚠️ Creates entry with default value if not exists!
m.at("key");          // Throws if not exists

// Safe access
if (m.count("key")) cout << m["key"];
if (m.find("key") != m.end()) cout << m["key"];

// Insert
m.insert({"key", value});
m.insert(make_pair("key", value));
m.emplace("key", value);

// Check insert success
auto [it, success] = m.insert({"key", value});

// Erase
m.erase("key");       // By key
m.erase(it);          // By iterator

// Iteration (sorted by key)
for (auto& [key, val] : m) {
    cout << key << ": " << val << "\n";
}

// Bounds (same as set, but on keys)
m.lower_bound(key);
m.upper_bound(key);
```

### 9. `unordered_set<T>` - Hash Set
```cpp
unordered_set<int> us;

// Same interface as set, but:
// - O(1) average for insert, find, erase
// - O(n) worst case (hash collisions)
// - NOT sorted
// - No lower_bound/upper_bound

// Custom hash for pairs (not built-in!)
struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<long long>()(((long long)p.first << 32) | p.second);
    }
};
unordered_set<pair<int,int>, PairHash> us;
```

### 10. `unordered_map<K, V>` - Hash Map
```cpp
unordered_map<string, int> um;

// Same interface as map, but:
// - O(1) average operations
// - NOT sorted
// - No lower_bound/upper_bound

// Frequency counting
for (int x : arr) um[x]++;

// ⚠️ Can be hacked in Codeforces! Use with caution or custom hash
```

### 11. `stack<T>` - LIFO
```cpp
stack<int> st;

st.push(x);           // Add to top
st.emplace(x);        // Construct in place
st.pop();             // Remove top (returns void!)
st.top();             // Access top
st.size();
st.empty();

// ⚠️ No iteration, no clear()
// To clear: while (!st.empty()) st.pop();
// Or: st = stack<int>();
```

### 12. `queue<T>` - FIFO
```cpp
queue<int> q;

q.push(x);            // Add to back
q.emplace(x);
q.pop();              // Remove front (returns void!)
q.front();            // Access front
q.back();             // Access back
q.size();
q.empty();
```

### 13. `deque<T>` - Double-Ended Queue
```cpp
deque<int> dq;

// Like vector but O(1) push/pop at both ends
dq.push_back(x);
dq.push_front(x);
dq.pop_back();
dq.pop_front();
dq.front();
dq.back();
dq[i];                // Random access O(1)

// Useful for sliding window problems
```

### 14. `priority_queue<T>` - Heap
```cpp
// Max heap (default)
priority_queue<int> pq;

pq.push(x);           // O(log n)
pq.emplace(x);
pq.pop();             // Remove max, O(log n)
pq.top();             // Access max, O(1)
pq.size();
pq.empty();

// Min heap
priority_queue<int, vector<int>, greater<int>> pq;

// Min heap alternative using negation
priority_queue<int> pq;
pq.push(-x);          // Negate on push
int val = -pq.top();  // Negate on access

// Custom comparator
auto cmp = [](pii a, pii b) { return a.second > b.second; };
priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);

// Build heap from vector
vector<int> v = {3, 1, 4, 1, 5};
priority_queue<int> pq(v.begin(), v.end());

// ⚠️ No iteration, no clear, no decrease-key
```

### 15. `bitset<N>` - Fixed-Size Bit Array
```cpp
bitset<32> b;                 // 32 bits, all 0
bitset<8> b(42);              // From integer
bitset<8> b("11001010");      // From string

// Operations
b[i];                 // Access bit i
b.set(); b.set(i);    // Set to 1
b.reset(); b.reset(i);// Set to 0
b.flip(); b.flip(i);  // Toggle
b.count();            // Number of 1s (popcount)
b.any(); b.none(); b.all();

// Bitwise
b1 & b2; b1 | b2; b1 ^ b2; ~b;
b << n; b >> n;

// Conversion
b.to_ulong();
b.to_ullong();
b.to_string();

// GCC extensions (find set bits)
b._Find_first();      // First set bit position
b._Find_next(pos);    // Next set bit after pos
```

---

## STL Algorithms

### Include
```cpp
#include <algorithm>
#include <numeric>    // For accumulate, iota, gcd, etc.
```

### Sorting
```cpp
sort(v.begin(), v.end());           // Ascending
sort(all(v));                       // With macro
sort(all(v), greater<int>());       // Descending
sort(all(v), cmp);                  // Custom comparator

// Partial sort (first k elements sorted)
partial_sort(v.begin(), v.begin() + k, v.end());

// Stable sort (preserves relative order of equal elements)
stable_sort(all(v));

// Sort array
sort(arr, arr + n);

// Is sorted?
is_sorted(all(v));
is_sorted_until(all(v));  // Iterator to first unsorted element
```

### Searching
```cpp
// Binary search (requires sorted range)
binary_search(all(v), x);           // Returns true/false

// Lower/upper bound (returns iterator)
lower_bound(all(v), x);             // First >= x
upper_bound(all(v), x);             // First > x

// Get index
int idx = lower_bound(all(v), x) - v.begin();

// Count elements in range [lo, hi]
int cnt = upper_bound(all(v), hi) - lower_bound(all(v), lo);

// Find (linear search)
find(all(v), x);                    // Returns iterator
find_if(all(v), pred);              // Find first satisfying predicate

// Count
count(all(v), x);                   // Count occurrences
count_if(all(v), pred);             // Count satisfying predicate

// Check if any/all satisfy predicate
any_of(all(v), pred);
all_of(all(v), pred);
none_of(all(v), pred);
```

### Min/Max
```cpp
// Single values
min(a, b);
max(a, b);
min({a, b, c, d});                  // Multiple values
max({a, b, c, d});
minmax(a, b);                       // Returns pair{min, max}

// In container
*min_element(all(v));
*max_element(all(v));
auto [mi, ma] = minmax_element(all(v));

// With custom comparator
min(a, b, cmp);
max_element(all(v), cmp);

// Clamp value to range
clamp(x, lo, hi);                   // Returns max(lo, min(x, hi))
```

### Permutations
```cpp
// Next permutation (lexicographically)
next_permutation(all(v));           // Returns false if last permutation

// Previous permutation
prev_permutation(all(v));

// Generate all permutations
sort(all(v));  // Start from smallest
do {
    // Process current permutation
} while (next_permutation(all(v)));

// Permutation count = n!
```

### Reversing & Rotating
```cpp
reverse(all(v));                    // Reverse entire container
reverse(v.begin(), v.begin() + k);  // Reverse first k elements

rotate(v.begin(), v.begin() + k, v.end());  // Left rotate by k
// [1,2,3,4,5] with k=2 → [3,4,5,1,2]

// Right rotate by k: rotate left by (n - k)
rotate(v.begin(), v.end() - k, v.end());
```

### Removing & Modifying
```cpp
// Remove (doesn't actually delete, just moves to end)
auto it = remove(all(v), x);        // Remove all x
v.erase(it, v.end());               // Actually erase

// Shorthand: erase-remove idiom
v.erase(remove(all(v), x), v.end());

// Remove if
v.erase(remove_if(all(v), pred), v.end());

// Unique (remove consecutive duplicates - sort first for all duplicates)
sort(all(v));
v.erase(unique(all(v)), v.end());

// Replace
replace(all(v), old_val, new_val);
replace_if(all(v), pred, new_val);

// Fill
fill(all(v), x);
fill_n(v.begin(), k, x);            // Fill first k elements

// Generate
generate(all(v), gen);              // Fill with generator function
iota(all(v), 0);                    // Fill with 0, 1, 2, 3, ...
```

### Copying & Transforming
```cpp
// Copy
copy(all(v), dest.begin());
copy_n(v.begin(), k, dest.begin());
copy_if(all(v), back_inserter(dest), pred);

// Transform (apply function to each element)
transform(all(v), v.begin(), [](int x) { return x * 2; });

// Transform two ranges
transform(all(v1), v2.begin(), result.begin(), 
          [](int a, int b) { return a + b; });
```

### Numeric Operations
```cpp
#include <numeric>

// Sum
accumulate(all(v), 0);              // Sum with initial value 0
accumulate(all(v), 0LL);            // Use long long for large sums
accumulate(all(v), 1, multiplies<int>());  // Product

// With custom operation
accumulate(all(v), 0, [](int sum, int x) { return sum + x * x; });

// Partial sums (prefix sums)
partial_sum(all(v), prefix.begin());
// v = [1, 2, 3, 4] → prefix = [1, 3, 6, 10]

// Adjacent difference
adjacent_difference(all(v), diff.begin());
// v = [1, 3, 6, 10] → diff = [1, 2, 3, 4]

// Inner product (dot product)
inner_product(all(v1), v2.begin(), 0);

// Reduce (C++17, can be parallel)
reduce(all(v));                     // Sum
reduce(all(v), 0, op);              // With operation

// Iota (fill with incrementing values)
iota(all(v), start);                // Fill with start, start+1, ...

// GCD and LCM (C++17)
__gcd(a, b);                        // GCC built-in
gcd(a, b);                          // C++17 standard
lcm(a, b);                          // C++17 standard
```

### Set Operations (on sorted ranges)
```cpp
// Requires sorted ranges!

// Union
set_union(all(a), all(b), back_inserter(result));

// Intersection
set_intersection(all(a), all(b), back_inserter(result));

// Difference (a - b)
set_difference(all(a), all(b), back_inserter(result));

// Symmetric difference (elements in a or b but not both)
set_symmetric_difference(all(a), all(b), back_inserter(result));

// Merge two sorted ranges
merge(all(a), all(b), back_inserter(result));
inplace_merge(v.begin(), v.begin() + k, v.end());

// Check if b is subset of a
includes(all(a), all(b));
```

### Heap Operations
```cpp
// Make heap from vector
make_heap(all(v));                  // Max heap, O(n)

// Push (after adding to end)
v.push_back(x);
push_heap(all(v));                  // O(log n)

// Pop (moves max to end)
pop_heap(all(v));                   // O(log n)
v.pop_back();                       // Remove it

// Sort heap
sort_heap(all(v));                  // O(n log n)

// Check if heap
is_heap(all(v));
is_heap_until(all(v));
```

### Other Useful Algorithms
```cpp
// Swap
swap(a, b);
iter_swap(it1, it2);
swap_ranges(all(v1), v2.begin());

// Partition
partition(all(v), pred);            // Elements satisfying pred first
stable_partition(all(v), pred);     // Preserves relative order
partition_point(all(v), pred);      // Iterator to first not satisfying

// Nth element (quickselect)
nth_element(v.begin(), v.begin() + k, v.end());
// v[k] is the k-th smallest, elements before are smaller (unsorted)

// For each
for_each(all(v), [](int& x) { x *= 2; });

// Equal
equal(all(v1), v2.begin());

// Lexicographic compare
lexicographical_compare(all(v1), all(v2));

// Mismatch
auto [it1, it2] = mismatch(all(v1), v2.begin());
```

---

## Strings

### String Operations
```cpp
// Concatenation
string s = s1 + s2;
s += s2;
s.append(s2);

// Comparison
s1 == s2; s1 < s2;    // Lexicographic

// Substring
s.substr(pos, len);
s.substr(pos);        // To end

// Find
s.find(sub);          // First occurrence, string::npos if not found
s.rfind(sub);         // Last occurrence
s.find_first_of(chars);
s.find_last_of(chars);
s.find_first_not_of(chars);

// Check prefix/suffix (C++20 or manual)
s.starts_with(prefix);  // C++20
s.ends_with(suffix);    // C++20

// Manual check
bool startsWith = s.substr(0, prefix.size()) == prefix;
bool endsWith = s.size() >= suffix.size() && 
                s.substr(s.size() - suffix.size()) == suffix;

// Replace
s.replace(pos, len, replacement);

// Erase
s.erase(pos, len);
s.erase(it);
s.erase(it1, it2);

// Insert
s.insert(pos, str);

// Character operations
isalpha(c); isdigit(c); isalnum(c);
isupper(c); islower(c);
isspace(c);
toupper(c); tolower(c);

// Convert case
transform(all(s), s.begin(), ::tolower);
transform(all(s), s.begin(), ::toupper);
```

### String Stream
```cpp
#include <sstream>

// Parse string
stringstream ss(s);
string word;
while (ss >> word) {
    // Process each word
}

// Split by delimiter
stringstream ss(s);
string token;
while (getline(ss, token, ',')) {
    // Process each token
}

// Build string
stringstream ss;
ss << "Value: " << x << ", " << y;
string result = ss.str();
```

### Character to/from Integer
```cpp
char c = '5';
int d = c - '0';      // d = 5

int d = 7;
char c = d + '0';     // c = '7'

// A-Z to 0-25
char c = 'D';
int idx = c - 'A';    // idx = 3

// a-z to 0-25
int idx = c - 'a';
```

---

## Math Functions

### Basic Math
```cpp
#include <cmath>

abs(x);               // Absolute value (int)
fabs(x);              // Absolute value (float/double)
llabs(x);             // Absolute value (long long)

sqrt(x);              // Square root
cbrt(x);              // Cube root
pow(x, y);            // x^y (returns double, may have precision issues!)

ceil(x);              // Round up
floor(x);             // Round down
round(x);             // Round to nearest
trunc(x);             // Round towards zero

fmod(x, y);           // Floating point modulo
remainder(x, y);      // IEEE remainder

log(x);               // Natural log (ln)
log10(x);             // Log base 10
log2(x);              // Log base 2
exp(x);               // e^x

sin(x); cos(x); tan(x);
asin(x); acos(x); atan(x);
atan2(y, x);          // atan(y/x) with correct quadrant

hypot(x, y);          // sqrt(x² + y²) (more stable)
```

### Integer Math
```cpp
// GCD and LCM
__gcd(a, b);          // GCC built-in
gcd(a, b);            // C++17
lcm(a, b);            // C++17

// ⚠️ LCM can overflow! Use: lcm = a / gcd(a, b) * b

// Power of 2 check
bool isPow2 = n > 0 && (n & (n - 1)) == 0;

// Next power of 2
int nextPow2(int n) {
    return 1 << (32 - __builtin_clz(n - 1));
}

// Ceiling division (without floating point)
int ceilDiv(int a, int b) {
    return (a + b - 1) / b;
    // Or: return (a - 1) / b + 1; // a > 0
}

// Modular arithmetic
(a + b) % MOD;
(a - b % MOD + MOD) % MOD;  // Prevent negative
(1LL * a * b) % MOD;        // Prevent overflow

// Modular exponentiation
ll power(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

// Modular inverse (when mod is prime)
ll modInverse(ll a, ll mod) {
    return power(a, mod - 2, mod);
}
```

### Random Numbers
```cpp
#include <random>

// Modern C++ (preferred)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// Or: mt19937 rng(random_device{}());

int randInt = rng();                           // Full range
int randInt = rng() % n;                       // [0, n-1]
int randInt = uniform_int_distribution<int>(a, b)(rng);  // [a, b]
double randDouble = uniform_real_distribution<double>(0, 1)(rng);

// Shuffle
shuffle(all(v), rng);

// Legacy (avoid in contests due to predictability)
srand(time(0));
rand() % n;
```

---

## Useful Macros & Shortcuts

### Common Macros
```cpp
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define each(x, a) for (auto& x : a)

#define yes cout << "YES\n"
#define no cout << "NO\n"
```

### Debug Macro
```cpp
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = ["; for(auto& x : v) cerr << x << ", "; cerr << "]" << endl; }
#else
#define debug(x)
#define debugv(v)
#endif

// Usage:
debug(n);           // Prints: n = 5
debugv(v);          // Prints: v = [1, 2, 3, ]
```

### Compile with DEBUG
```bash
g++ -DLOCAL -o solution solution.cpp
```

---

## Lambda Functions

### Syntax
```cpp
// Basic lambda
auto f = []() { cout << "Hello\n"; };
f();

// With parameters
auto add = [](int a, int b) { return a + b; };
cout << add(2, 3);  // 5

// With return type
auto divide = [](int a, int b) -> double { return (double)a / b; };

// Capture by value
int x = 5;
auto f = [x]() { return x; };

// Capture by reference
auto f = [&x]() { x++; };

// Capture all by value
auto f = [=]() { return x + y; };

// Capture all by reference
auto f = [&]() { x++; y++; };

// Mixed capture
auto f = [&x, y]() { x = y; };
```

### Common Uses in CP
```cpp
// Custom sort
sort(all(v), [](const pii& a, const pii& b) {
    return a.second < b.second;  // Sort by second element
});

// Count with condition
int cnt = count_if(all(v), [](int x) { return x > 0; });

// Find with condition
auto it = find_if(all(v), [&target](int x) { return x == target; });

// Priority queue with custom comparator
auto cmp = [](pii a, pii b) { return a.first > b.first; };
priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);

// Recursive lambda (C++14)
function<int(int)> factorial = [&](int n) -> int {
    return n <= 1 ? 1 : n * factorial(n - 1);
};

// Or use auto with explicit capture (C++14)
auto dfs = [&](auto& self, int u) -> void {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) self(self, v);
    }
};
dfs(dfs, 0);
```

---

## Custom Comparators

### For `sort`
```cpp
// Function
bool cmp(int a, int b) {
    return a > b;  // Descending
}
sort(all(v), cmp);

// Lambda
sort(all(v), [](int a, int b) { return a > b; });

// Sort pairs by second element
sort(all(v), [](pii a, pii b) {
    if (a.S != b.S) return a.S < b.S;
    return a.F < b.F;
});

// Sort by absolute value
sort(all(v), [](int a, int b) { return abs(a) < abs(b); });

// Sort strings by length, then lexicographically
sort(all(v), [](string& a, string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
});
```

### For `set` and `map`
```cpp
// Struct comparator
struct Cmp {
    bool operator()(int a, int b) const {
        return a > b;  // Descending
    }
};
set<int, Cmp> s;
map<int, int, Cmp> m;

// Lambda (C++20 or with extra work)
auto cmp = [](int a, int b) { return a > b; };
set<int, decltype(cmp)> s(cmp);
```

### For `priority_queue`
```cpp
// ⚠️ priority_queue comparator is OPPOSITE of sort!
// Returns true if a has LOWER priority than b

// Min heap using greater
priority_queue<int, vector<int>, greater<int>> pq;

// Custom struct
struct Cmp {
    bool operator()(pii a, pii b) {
        return a.F > b.F;  // Min by first (opposite!)
    }
};
priority_queue<pii, vector<pii>, Cmp> pq;

// Lambda
auto cmp = [](pii a, pii b) { return a.F > b.F; };
priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
```

---

## Policy Based Data Structures

### Order Statistics Tree
```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;

ordered_set os;
os.insert(1);
os.insert(3);
os.insert(5);
os.insert(7);

// Find k-th smallest (0-indexed)
*os.find_by_order(0);  // 1 (smallest)
*os.find_by_order(2);  // 5 (3rd smallest)

// Count elements strictly less than x
os.order_of_key(4);    // 2 (elements 1, 3 are < 4)
os.order_of_key(5);    // 2 (elements 1, 3 are < 5)

// Erase
os.erase(3);

// ⚠️ For multiset, use pair<int, int> with unique second element
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, 
             rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
```

### Indexed Set Operations Summary
| Operation | Time | Description |
|-----------|------|-------------|
| `insert(x)` | O(log n) | Insert element |
| `erase(x)` | O(log n) | Remove element |
| `find_by_order(k)` | O(log n) | Iterator to k-th element (0-indexed) |
| `order_of_key(x)` | O(log n) | Count elements < x |

---

## Common Patterns & Tricks

### 1. Frequency Counting
```cpp
map<int, int> freq;
for (int x : arr) freq[x]++;

// Or with vector if values are small
vector<int> freq(MAX_VAL + 1, 0);
for (int x : arr) freq[x]++;

// Or with unordered_map for O(1) average
unordered_map<int, int> freq;
for (int x : arr) freq[x]++;
```

### 2. Prefix Sums
```cpp
vector<ll> prefix(n + 1, 0);
for (int i = 0; i < n; i++)
    prefix[i + 1] = prefix[i] + arr[i];

// Sum of range [l, r]
ll sum = prefix[r + 1] - prefix[l];
```

### 3. Difference Array
```cpp
// Add val to range [l, r]
vector<ll> diff(n + 1, 0);
diff[l] += val;
diff[r + 1] -= val;

// Get actual values
partial_sum(all(diff), diff.begin());
```

### 4. Two Pointers
```cpp
// Two pointers from both ends
int l = 0, r = n - 1;
while (l < r) {
    // Process
    if (condition) l++;
    else r--;
}

// Sliding window (variable size)
int l = 0;
for (int r = 0; r < n; r++) {
    // Expand window by including arr[r]
    while (/* window invalid */) {
        // Shrink window by excluding arr[l]
        l++;
    }
    // Process valid window [l, r]
}
```

### 5. Binary Search Template
```cpp
// Find minimum x such that check(x) is true
int lo = MIN_VAL, hi = MAX_VAL;
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (check(mid)) hi = mid;
    else lo = mid + 1;
}
// Answer: lo

// Find maximum x such that check(x) is true
int lo = MIN_VAL, hi = MAX_VAL;
while (lo < hi) {
    int mid = lo + (hi - lo + 1) / 2;  // Round up!
    if (check(mid)) lo = mid;
    else hi = mid - 1;
}
// Answer: lo

// Binary search on answer (floating point)
double lo = 0, hi = 1e9;
for (int i = 0; i < 100; i++) {  // 100 iterations ≈ 10^-30 precision
    double mid = (lo + hi) / 2;
    if (check(mid)) lo = mid;
    else hi = mid;
}
```

### 6. Coordinate Compression
```cpp
vector<int> vals = arr;  // Copy
sort(all(vals));
vals.erase(unique(all(vals)), vals.end());

// Compress
for (int& x : arr) {
    x = lower_bound(all(vals), x) - vals.begin();
}

// Now arr values are in range [0, vals.size() - 1]
```

### 7. Counting Inversions with Merge Sort
```cpp
ll mergeCount(vector<int>& arr, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    ll cnt = mergeCount(arr, l, mid) + mergeCount(arr, mid + 1, r);
    
    vector<int> temp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else {
            temp.push_back(arr[j++]);
            cnt += mid - i + 1;
        }
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);
    copy(all(temp), arr.begin() + l);
    return cnt;
}
```

### 8. Graph Representations
```cpp
// Adjacency list (unweighted)
vector<vector<int>> adj(n);
adj[u].push_back(v);

// Adjacency list (weighted)
vector<vector<pair<int, int>>> adj(n);  // {neighbor, weight}
adj[u].push_back({v, w});

// Edge list
vector<tuple<int, int, int>> edges;  // {u, v, weight}
edges.emplace_back(u, v, w);

// Adjacency matrix
vector<vector<int>> adj(n, vector<int>(n, 0));
adj[u][v] = 1;
```

### 9. DSU (Disjoint Set Union)
```cpp
class DSU {
    vector<int> parent, rank_;
public:
    DSU(int n) : parent(n), rank_(n, 0) {
        iota(all(parent), 0);
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rank_[x] < rank_[y]) swap(x, y);
        parent[y] = x;
        if (rank_[x] == rank_[y]) rank_[x]++;
        return true;
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
```

### 10. Modular Arithmetic Class
```cpp
const int MOD = 1e9 + 7;

struct Mint {
    int val;
    Mint(ll x = 0) : val((x % MOD + MOD) % MOD) {}
    
    Mint operator+(Mint o) const { return val + o.val; }
    Mint operator-(Mint o) const { return val - o.val; }
    Mint operator*(Mint o) const { return 1LL * val * o.val; }
    Mint operator/(Mint o) const { return *this * o.pow(MOD - 2); }
    
    Mint& operator+=(Mint o) { return *this = *this + o; }
    Mint& operator-=(Mint o) { return *this = *this - o; }
    Mint& operator*=(Mint o) { return *this = *this * o; }
    Mint& operator/=(Mint o) { return *this = *this / o; }
    
    Mint pow(ll e) const {
        Mint res = 1, base = *this;
        while (e > 0) {
            if (e & 1) res *= base;
            base *= base;
            e >>= 1;
        }
        return res;
    }
    
    friend ostream& operator<<(ostream& os, Mint m) {
        return os << m.val;
    }
};
```

---

## Time Complexity Reference

### Container Operations
| Container | Access | Search | Insert | Delete |
|-----------|--------|--------|--------|--------|
| `vector` | O(1) | O(n) | O(n)* | O(n) |
| `deque` | O(1) | O(n) | O(n)* | O(n) |
| `list` | O(n) | O(n) | O(1)** | O(1)** |
| `set/map` | O(log n) | O(log n) | O(log n) | O(log n) |
| `unordered_set/map` | O(1)† | O(1)† | O(1)† | O(1)† |
| `priority_queue` | O(1) top | - | O(log n) | O(log n) |

\* Amortized O(1) at end  
\** With iterator  
† Average case, O(n) worst case

### Algorithm Complexities
| Algorithm | Time | Space |
|-----------|------|-------|
| `sort` | O(n log n) | O(log n) |
| `stable_sort` | O(n log n) | O(n) |
| `partial_sort` | O(n log k) | O(1) |
| `nth_element` | O(n) average | O(1) |
| `binary_search` | O(log n) | O(1) |
| `lower/upper_bound` | O(log n) | O(1) |
| `unique` | O(n) | O(1) |
| `reverse` | O(n) | O(1) |
| `rotate` | O(n) | O(1) |
| `next_permutation` | O(n) | O(1) |
| `accumulate` | O(n) | O(1) |
| `make_heap` | O(n) | O(1) |

### Constraints Guide
| n | Safe Complexity |
|---|-----------------|
| ≤ 10 | O(n!), O(n⁶) |
| ≤ 20 | O(2ⁿ), O(n⁵) |
| ≤ 100 | O(n⁴) |
| ≤ 500 | O(n³) |
| ≤ 5000 | O(n²) |
| ≤ 10⁶ | O(n log n) |
| ≤ 10⁸ | O(n) |
| > 10⁸ | O(log n), O(1) |

---

## Debugging Tips

### Print Anything
```cpp
// Debug template
template<typename T>
void print(T x) { cerr << x; }

template<typename T, typename U>
void print(pair<T, U> p) { cerr << "(" << p.F << ", " << p.S << ")"; }

template<typename T>
void print(vector<T> v) {
    cerr << "[";
    for (int i = 0; i < sz(v); i++) {
        if (i) cerr << ", ";
        print(v[i]);
    }
    cerr << "]";
}

#define dbg(x) cerr << #x << " = ", print(x), cerr << endl
```

### Common Debug Prints
```cpp
// Print with index
for (int i = 0; i < n; i++)
    cerr << i << ": " << arr[i] << "\n";

// Print map
for (auto& [k, v] : mp)
    cerr << k << " -> " << v << "\n";

// Print set
for (auto& x : s) cerr << x << " ";
cerr << "\n";

// Print 2D grid
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
        cerr << grid[i][j] << " ";
    cerr << "\n";
}
```

### Stress Testing
```cpp
// Generate random test and compare with brute force
mt19937 rng(42);
for (int test = 0; test < 1000; test++) {
    int n = rng() % 10 + 1;
    vector<int> arr(n);
    for (int& x : arr) x = rng() % 100;
    
    int expected = brute(arr);
    int actual = solve(arr);
    
    if (expected != actual) {
        cerr << "FAIL: ";
        for (int x : arr) cerr << x << " ";
        cerr << "\nExpected: " << expected << ", Got: " << actual << "\n";
        break;
    }
}
cerr << "All tests passed!\n";
```

---

## Common Mistakes to Avoid

### 1. Integer Overflow
```cpp
// ❌ WRONG
int a = 1e9, b = 1e9;
int c = a * b;  // Overflow!

// ✅ CORRECT
ll c = (ll)a * b;
ll c = 1LL * a * b;
```

### 2. Array Index Out of Bounds
```cpp
// ❌ WRONG
vector<int> v(n);
cout << v[n];  // Out of bounds!

// ✅ Use .at() during debugging
cout << v.at(n);  // Throws exception
```

### 3. Comparing Floating Point
```cpp
// ❌ WRONG
if (a == b)

// ✅ CORRECT
if (abs(a - b) < EPS)
```

### 4. Uninitialized Variables
```cpp
// ❌ WRONG
int x;
if (x > 0)  // Undefined behavior!

// ✅ CORRECT
int x = 0;
```

### 5. Modifying While Iterating
```cpp
// ❌ WRONG
for (auto it = s.begin(); it != s.end(); it++) {
    if (*it < 0) s.erase(it);  // Iterator invalidated!
}

// ✅ CORRECT
for (auto it = s.begin(); it != s.end(); ) {
    if (*it < 0) it = s.erase(it);
    else it++;
}
```

### 6. Wrong Loop Bounds
```cpp
// ❌ WRONG
for (int i = 0; i <= n; i++)  // Goes to n, might be out of bounds
for (int i = n; i >= 0; i--)  // Includes 0, might cause issues

// ✅ Be careful with bounds
```

### 7. Operator Precedence
```cpp
// ❌ WRONG
if (x & 1 == 1)  // Parsed as x & (1 == 1)

// ✅ CORRECT
if ((x & 1) == 1)
```

### 8. Using `endl` Instead of `"\n"`
```cpp
// ❌ SLOW (flushes buffer)
cout << x << endl;

// ✅ FAST
cout << x << "\n";
```

### 9. Not Clearing Global State
```cpp
// ❌ WRONG (for multiple test cases)
int main() {
    int t; cin >> t;
    while (t--) {
        // globalVector might still have data from previous test!
    }
}

// ✅ CORRECT
while (t--) {
    globalVector.clear();
    // Process test case
}
```

### 10. Forgetting Long Long
```cpp
// ❌ WRONG
int answer = 0;
for (int x : arr) answer += x;  // Might overflow

// ✅ CORRECT
ll answer = 0;
for (int x : arr) answer += x;
```

---

## Quick Reference Card

```cpp
// ============= I/O =============
ios::sync_with_stdio(false); cin.tie(0);

// ============= CONTAINERS =============
vector<int> v(n), v(n, x);
set<int> s; s.insert(x); s.erase(x); s.count(x); s.find(x);
map<int,int> m; m[k]=v; m.count(k);
priority_queue<int> pq; // max heap
priority_queue<int, vector<int>, greater<int>> pq; // min heap

// ============= ALGORITHMS =============
sort(all(v)); sort(all(v), cmp);
*min_element(all(v)); *max_element(all(v));
lower_bound(all(v), x); upper_bound(all(v), x);
accumulate(all(v), 0LL);
unique(all(v)); // remove consecutive duplicates
next_permutation(all(v));
reverse(all(v));
count(all(v), x); count_if(all(v), pred);

// ============= MATH =============
__gcd(a,b); gcd(a,b); lcm(a,b);
__builtin_popcount(x); // count 1 bits
__builtin_clz(x); // leading zeros
__builtin_ctz(x); // trailing zeros

// ============= USEFUL =============
(a % MOD + MOD) % MOD; // safe mod
1LL * a * b % MOD; // prevent overflow
(a + b - 1) / b; // ceil division
```

---

> 💡 **Remember**: The best way to master these is through practice. Solve problems daily and you'll internalize these patterns!

*Happy Coding & Good Luck on your Master journey! 🚀*
