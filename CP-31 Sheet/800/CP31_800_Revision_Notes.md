# CP-31 Sheet (800) - Revision Notes

This file consolidates solved 800-rated problems with the exact ideas, misses, memory tricks, and APIs/concepts used.

## 1) A. Cover in Water
- Problem: https://codeforces.com/problemset/problem/1900/A
- Core idea:
  - Count total `'.'` cells.
  - If there exists any `"..."` (three consecutive empty cells), answer is `2`.
  - Otherwise, answer is total count of `'.'`.
- What I missed:
  - The special rule around three consecutive empty cells that immediately fixes the answer to `2`.
- How to remember:
  - `Triple dot => fixed answer 2`.
  - In scan problems, always check for a strong shortcut condition before final counting.
- APIs / concepts used:
  - `string`
  - Single pass loop
  - Boolean flag + counter
- Complexity:
  - Time: `O(n)`
  - Space: `O(1)`

## 2) A. Game with Integers
- Problem: https://codeforces.com/problemset/problem/1899/A
- Core idea:
  - If `n % 3 == 0` => `Second`
  - Else => `First`
- What I missed:
  - Missed reading operation details carefully: each move allows `+1` or `-1`.
  - Initially overthought with simulation instead of direct game-state rule.
- How to remember:
  - For game problems: first check invariants/modulo classes.
  - `mod 3` is the whole game here.
- APIs / concepts used:
  - Modulo arithmetic (`%`)
  - Conditional output
- Complexity:
  - Time: `O(1)` per test case
  - Space: `O(1)`

## 3) A. Halloumi Boxes
- Problem: https://codeforces.com/problemset/problem/1903/A
- Core idea:
  - If `k > 1`, any permutation is achievable => always `YES`.
  - If `k == 1`, array must already be sorted for `YES`; else `NO`.
- What I missed:
  - Needed explicit check: already sorted when `k == 1`.
- How to remember:
  - `k == 1` means no real freedom; only current order matters.
  - `k > 1` means reorder freedom.
- APIs / concepts used:
  - `vector<ll>`
  - Copy vector
  - `sort(begin, end)`
  - Vector equality (`copy_a == a`)
- Complexity:
  - Time: `O(n log n)`
  - Space: `O(n)`

## 4) A. Jagged Swaps
- Problem: https://codeforces.com/problemset/problem/1896/A
- Core idea:
  - Sortability condition reduces to checking first element.
  - If `a[0] == 1` => `YES`, else `NO`.
- What I missed:
  - The crucial permutation condition: first number must be `1`.
- How to remember:
  - For operation-based permutation problems, identify non-movable anchors.
  - Here, `1` must be in front to enable full sorting process.
- APIs / concepts used:
  - `vector<ll>`
  - Direct index access (`a[0]`)
- Complexity:
  - Time: `O(1)` logic after input
  - Space: `O(1)` extra

## 5) A. Line Trip
- Problem: https://codeforces.com/problemset/problem/1901/A
- Core idea:
  - Insert virtual points `0` and `x`.
  - Compute max gap between consecutive points.
  - Last stretch contributes `2 * (x - last_station)` because return from the last station side matters.
  - Answer is max of all these required distances.
- What I missed:
  - Missing the doubled tail distance (`2 * (x - last_station)`).
- How to remember:
  - Start-end trick for coordinate problems: add boundary points first.
  - Tail case often differs; isolate it explicitly.
- APIs / concepts used:
  - `vector<int>` with `push_back`
  - Consecutive difference scan
  - `max(...)`
- Complexity:
  - Time: `O(n)`
  - Space: `O(n)`

---

## Fast Revision Checklist (for similar 800 problems)
- Read operations carefully before coding.
- Check for shortcut pattern conditions (like `"..."`) before full logic.
- Try modulo/invariant reasoning in game problems.
- For rearrangement constraints, ask: `When is order fixed?` (`k == 1` type conditions).
- For coordinate/gap problems, add boundary points (`0`, `x`) and handle tail separately.
- Prefer simplest valid condition over simulation.
