# Heap Data Structure

This note is written for Competitive Programming and interview preparation. It keeps your original ideas and expands them with the practical patterns, invariants, proofs, and common interview problems that are important in CP and Codeforces.

---

## 1) What is a Heap?

A heap is a complete binary tree that satisfies the heap property.

- Max Heap: parent >= children
- Min Heap: parent <= children

A heap is usually stored in an array for memory efficiency.

### Indexing in array representation

- Parent of index i: (i - 1) / 2
- Left child of index i: 2*i + 1
- Right child of index i: 2*i + 2

This works because the heap is a complete binary tree.

### Why it matters
A heap gives fast access to the smallest or largest element.

- Peek max/min: O(1)
- Insert: O(log n)
- Extract max/min: O(log n)
- Build heap: O(n)

This is why heaps are used in priority queues, scheduling, and greedy problems.

---

## 2) Heap Properties

### Complete Binary Tree
Every level is filled before the next one, except the last level which can be partially filled from left to right.

### Heap Order Property
- In a max heap: parent >= child
- In a min heap: parent <= child

### Original note preserved

```text
A heap is a complete binary tree data structure that satisfies the heap order property.

Heap Property:
- Max Heap: Parent node >= to its children
- Min Heap: Parent Node <= to its children

Complete Binary Tree = Heap order property
Heap Stored as array to optimized space: Indexing
- Parent at index i
- Left child at 2*i + 1
- right child at 2*i + 2

To find index of parent (i - 1) / 2.
```

---

## 3) Heap Operations

### Build Heap
Convert an array into a valid heap.

- Time: O(n)

### Peek (Top / Root)
Return the maximum element for max heap or minimum for min heap.

- Time: O(1)

### Insert
Add an element at the end, then fix upward.

- Time: O(log n)

### Delete / Extract
Remove the root, swap with last element, then fix downward.

- Time: O(log n)

### Heapify Up
Move an element upward while it violates the heap property.

### Heapify Down
Move an element downward while its children violate the heap property.

### Original note preserved

```text
Heap Operations:
---------------
- Build Heap
    * Convert an array into the heap
    * TC: O(N)
- Peek (get Min/Max)
    * Return the root element
    * TC: O(1)
- Insert:
    * Insert at the end, then Heapify Up
    * TC: O(log N)
- Delete (Extract Min/Max):
    * Swap root with last element, then heapify down.
    * TC: O(log N)
- Rearrrange the elements of array such that it symbolizes max heap:
    * Heapify Up
    * Heapify Down
```

---

## 4) Heapify Down

When building a heap from an array, we start from the last non-leaf node and heapify down each parent.

Why last non-leaf?
Because only internal nodes can have children. A leaf is already a valid heap node.

### Formula
Last non-leaf index = (n / 2) - 1

### Original note preserved

```text
Heapify Down:
------------
- Start with the last non-leaf node, because with a child node, we can't push down the node.
- The index of last non-leaf node is the parent of the last leaf node.
```

---

## 5) Heapify Up / Heapify Down

### Heapify Up
Used during insertion.

- Insert at the end
- Compare with parent
- Swap if child is greater than parent (max heap)
- Continue upward until valid

### Heapify Down
Used during deletion or building heap.

- Compare node with left and right child
- Swap with the larger child (max heap) or smaller child (min heap)
- Recursively continue down

### Complexity

```text
TC: O(log n)
```

### Original note preserved

```text
Heapify Up/Down:
----------------
Heapify UP - Move the elements to its correct position to moving up.
Heapify Down - Move the elements to its correct position by moving down.
TC: O(log n)
```

---

## 6) Building a Max Heap (Core CP Pattern)

The standard build process:

```cpp
for (int i = n / 2 - 1; i >= 0; i--) {
    heapify_down(i);
}
```

### Why does this work?
Every node from the last non-leaf to the root is an internal node with possible children. If the subtree rooted at that node is broken, heapify_down fixes it.

### Binary tree height relation

```text
1 + 2^1 + 2^2 ... + 2^h = n
```

This leads to the height of heap being roughly O(log n).

### Original note preserved

```text
Max Heap Algorithm:
------------------
Traverse from Last Non-Leaf node to 0, and heapify down every node.

1 + 2^1 + 2^2 ... 2^n-1 = n

2^h-1 = n
2^h = n + 1
h=log (h + 1)
```

---

## 7) Max Heap Implementation in C++

```cpp
#include <bits/stdc++.h>
using namespace std;

class Max_Heap {
    vector<int> heap;

    void heapify_down(int ind) {
        int n = heap.size();
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        int largest = ind;

        if (left < n && heap[left] > heap[ind]) {
            largest = left;
        }
        if (right < n && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest == ind) return;

        swap(heap[ind], heap[largest]);
        heapify_down(largest);
    }

    void heapify_up(int ind) {
        if (ind == 0) return;
        int parent = (ind - 1) / 2;
        if (heap[ind] > heap[parent]) {
            swap(heap[ind], heap[parent]);
            heapify_up(parent);
        }
    }

public:
    Max_Heap(vector<int> arr) {
        heap = arr;
    }

    void build() {
        int n = heap.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify_down(i);
        }
    }

    int get_max() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    void insert(int val) {
        heap.push_back(val);
        heapify_up(heap.size() - 1);
    }

    void remove() {
        int n = heap.size();
        if (n == 0) return;

        swap(heap[0], heap[n - 1]);
        heap.pop_back();

        if (!heap.empty()) {
            heapify_down(0);
        }
    }
};

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};
    Max_Heap pq(arr);
    pq.build();

    cout << pq.get_max() << "\n"; // 10
    pq.remove();
    cout << pq.get_max() << "\n"; // 5
    pq.insert(40);
    cout << pq.get_max() << "\n"; // 40

    return 0;
}
```

---

## 8) Java Implementation

```java
import java.util.*;

class MaxHeap {
    private ArrayList<Integer> heap;

    public MaxHeap(ArrayList<Integer> arr) {
        heap = new ArrayList<>(arr);
    }

    private void heapifyDown(int idx) {
        int n = heap.size();
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int largest = idx;

        if (left < n && heap.get(left) > heap.get(largest)) {
            largest = left;
        }
        if (right < n && heap.get(right) > heap.get(largest)) {
            largest = right;
        }

        if (largest == idx) return;

        Collections.swap(heap, idx, largest);
        heapifyDown(largest);
    }

    private void heapifyUp(int idx) {
        if (idx == 0) return;
        int parent = (idx - 1) / 2;
        if (heap.get(idx) > heap.get(parent)) {
            Collections.swap(heap, idx, parent);
            heapifyUp(parent);
        }
    }

    public void build() {
        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    public int getMax() {
        if (heap.isEmpty()) return -1;
        return heap.get(0);
    }

    public void insert(int val) {
        heap.add(val);
        heapifyUp(heap.size() - 1);
    }

    public void remove() {
        if (heap.isEmpty()) return;
        Collections.swap(heap, 0, heap.size() - 1);
        heap.remove(heap.size() - 1);
        if (!heap.isEmpty()) heapifyDown(0);
    }

    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>(Arrays.asList(4, 10, 3, 5, 1));
        MaxHeap pq = new MaxHeap(arr);
        pq.build();

        System.out.println(pq.getMax()); // 10
        pq.remove();
        System.out.println(pq.getMax()); // 5
        pq.insert(40);
        System.out.println(pq.getMax()); // 40
    }
}
```

---

## 9) Interview Concepts That Use Heaps

### 1. Top K Largest Elements
Use a min-heap of size k.

Key idea:
- Keep only the k largest values seen so far.
- If a new value is larger than the heap root, replace it.

### 2. Top K Smallest Elements
Use a max-heap of size k.

### 3. Merge K Sorted Arrays
Use a min-heap to always pick the smallest current element across arrays.

### 4. Priority Queue / Scheduling
Used when tasks need to be processed in order of highest/lowest priority.

### 5. Median Maintenance
Use two heaps: max-heap for left half and min-heap for right half.

### 6. Dijkstra's Algorithm
Heap is used for efficient selection of the smallest distance node.

### 7. Huffman Coding
Heap is used to repeatedly merge the smallest frequencies.

---

## 10) Important Competitive Programming Problems

### Problem 1: K Largest Elements
Use a min heap of size k.

C++:

```cpp
vector<int> kLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x : arr) {
        pq.push(x);
        if (pq.size() > k) pq.pop();
    }

    vector<int> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}
```

Java:

```java
import java.util.*;

class Solution {
    public int[] kLargest(int[] arr, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int x : arr) {
            pq.offer(x);
            if (pq.size() > k) pq.poll();
        }

        int[] ans = new int[pq.size()];
        int i = ans.length - 1;
        while (!pq.isEmpty()) {
            ans[i--] = pq.poll();
        }
        Arrays.sort(ans);
        return ans;
    }
}
```

### Problem 2: K Smallest Elements
Use a max heap of size k.

C++:

```cpp
vector<int> kSmallest(vector<int>& arr, int k) {
    priority_queue<int> pq;
    for (int x : arr) {
        pq.push(x);
        if (pq.size() > k) pq.pop();
    }

    vector<int> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}
```

Java:

```java
import java.util.*;

class Solution {
    public int[] kSmallest(int[] arr, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int x : arr) {
            pq.offer(x);
            if (pq.size() > k) pq.poll();
        }

        int[] ans = new int[pq.size()];
        int i = 0;
        while (!pq.isEmpty()) {
            ans[i++] = pq.poll();
        }
        Arrays.sort(ans);
        return ans;
    }
}
```

### Problem 3: Merge K Sorted Lists
Use a min heap for the current element from each list.

C++:

```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* a, ListNode* b) {
        return a->val > b->val;
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

    for (auto node : lists) if (node) pq.push(node);

    ListNode dummy(0), *tail = &dummy;
    while (!pq.empty()) {
        ListNode* cur = pq.top();
        pq.pop();
        tail->next = cur;
        tail = tail->next;
        if (cur->next) pq.push(cur->next);
    }
    return dummy.next;
}
```

Java:

```java
import java.util.*;

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> a.val - b.val);
        for (ListNode node : lists) {
            if (node != null) pq.offer(node);
        }

        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        while (!pq.isEmpty()) {
            ListNode cur = pq.poll();
            tail.next = cur;
            tail = tail.next;
            if (cur.next != null) pq.offer(cur.next);
        }
        return dummy.next;
    }
}
```

### Problem 4: K Closest Points to Origin
Use a max heap of size k.

C++:

```cpp
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int, pair<int,int>>> pq;
    for (auto &p : points) {
        int dist = p[0]*p[0] + p[1]*p[1];
        pq.push({dist, {p[0], p[1]}});
        if (pq.size() > k) pq.pop();
    }

    vector<vector<int>> ans;
    while (!pq.empty()) {
        auto v = pq.top().second;
        ans.push_back({v.first, v.second});
        pq.pop();
    }
    return ans;
}
```

Java:

```java
import java.util.*;

class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            int da = a[0] * a[0] + a[1] * a[1];
            int db = b[0] * b[0] + b[1] * b[1];
            return db - da;
        });

        for (int[] p : points) {
            pq.offer(p);
            if (pq.size() > k) pq.poll();
        }

        int[][] ans = new int[k][2];
        for (int i = 0; i < k; i++) {
            ans[i] = pq.poll();
        }
        return ans;
    }
}
```

### Problem 5: Running Median
Use two heaps.

C++:

```cpp
priority_queue<int> left;                  // max-heap
priority_queue<int, vector<int>, greater<int>> right; // min-heap
```

Java:

```java
PriorityQueue<Integer> left = new PriorityQueue<>((a, b) -> b - a);
PriorityQueue<Integer> right = new PriorityQueue<>();
```

---

## 11) Heap Sort

Heap sort is a comparison-based sorting algorithm that uses a heap.

### Steps
- Convert the array into a max heap (for ascending order)
- Swap the root with the last element
- Reduce heap size
- Heapify the root
- Repeat until array is sorted

### Complexity
- Time: O(n log n)
- Space: O(1) auxiliary space

### Original note preserved

```text
Heap Sort:
----------

- Heap sort is a comparison-based algorithm that uses a binary heap.
- Steps:
    * Convery the array into max heap(for ascending order sorting).
    * swap the root(largest element) with the last element.
    * reduce heap size and heapify the root.
    * repeat the process until heap has the size greater than one.

TC: O(n log n)
SC: O(1)
```

### Heap Sort Sample Code in C++

```cpp
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapSort(arr);

    for (int x : arr) cout << x << " ";
    cout << "\n";
    return 0;
}
```

### Heap Sort Sample Code in Java

```java
import java.util.*;

class HeapSort {
    static void heapify(int[] arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(arr, n, largest);
        }
    }

    static void heapSort(int[] arr) {
        int n = arr.length;

        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, i, 0);
        }
    }

    public static void main(String[] args) {
        int[] arr = {12, 11, 13, 5, 6, 7};
        heapSort(arr);

        System.out.println(Arrays.toString(arr));
    }
}
```

---

## 12) Final Takeaways

- Heap is a complete binary tree used for fast max/min retrieval.
- Insertion and deletion are O(log n).
- Building heap is O(n).
- Priority queue and many greedy algorithms rely on heaps.
- Heap sort is O(n log n) and sorts in-place with O(1) extra auxiliary space.

### CP mindset
When a problem asks for:
- k smallest / largest values
- minimum cost repeatedly
- shortest path / greedy ordering
- merge sorted streams

think heap.

This is one of the most important structures in competitive programming and interviews.

