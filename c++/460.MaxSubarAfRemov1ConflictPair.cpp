/*3480. Maximize Subarrays After Removing One Conflicting Pair
You are given an integer n which represents an array nums containing the numbers
from 1 to n in order. Additionally, you are given a 2D array conflictingPairs,
where conflictingPairs[i] = [a, b] indicates that a and b form a conflicting
pair.

Remove exactly one element from conflictingPairs. Afterward, count the number of
non-empty subarrays of nums which do not contain both a and b for any remaining
conflicting pair [a, b].

Return the maximum number of subarrays possible after removing exactly one
conflicting pair.



Example 1:

Input: n = 4, conflictingPairs = [[2,3],[1,4]]

Output: 9

Explanation:

Remove [2, 3] from conflictingPairs. Now, conflictingPairs = [[1, 4]].
There are 9 subarrays in nums where [1, 4] do not appear together. They are [1],
[2], [3], [4], [1, 2], [2, 3], [3, 4], [1, 2, 3] and [2, 3, 4]. The maximum
number of subarrays we can achieve after removing one element from
conflictingPairs is 9. Example 2:

Input: n = 5, conflictingPairs = [[1,2],[2,5],[3,5]]

Output: 12

Explanation:

Remove [1, 2] from conflictingPairs. Now, conflictingPairs = [[2, 5], [3, 5]].
There are 12 subarrays in nums where [2, 5] and [3, 5] do not appear together.
The maximum number of subarrays we can achieve after removing one element from
conflictingPairs is 12.


Constraints:

2 <= n <= 105
1 <= conflictingPairs.length <= 2 * n
conflictingPairs[i].length == 2
1 <= conflictingPairs[i][j] <= n
conflictingPairs[i][0] != conflictingPairs[i][1]

Hint 1
Let f[i] (where i = 1, 2, 3, ..., n) be the end index of the longest valid
subarray (without any conflicting pair) starting at index i. Hint 2 The answer
is: sigma(f[i] - i + 1) for i in [1..n], which simplifies to: sigma(f[i]) - n *
(n + 1) / 2 + n. Hint 3 Focus on maintaining f[i]. Hint 4 If we have a
conflicting pair (x, y) with x < y: 1. Sort the conflicting pairs by y values in
non-increasing order. 2. Update each prefix of the f array accordingly. Hint 5
Use a segment tree or another suitable data structure to maintain the range
update and sum query efficiently.
*/

/*maximize the number of non-empty subarrays such that no subarray contains both
elements of any conflicting pair, after removing exactly one conflicting pair.
- total subarray=n(n+1)/2
- pair [a,b] is conflicting if a,b are in same subarray

- for conflict:
    - For each conflicting pair removal, compute the number of valid subarrays
after removing that one conflicting pair.
    - Keep the maximum over all such choices.

## Algorithm:
use sliding window approach.
- Fix one pair to remove at a time.

- Build an array `latest` such that `latest[i]` keeps track of the latest
starting index of a subarray that doesn't violate any remaining conflicting
pair.

- Iterate over `nums`, and for each index `i`, expand the right end of the
subarray as far as possible while maintaining the constraint.

- Count all subarrays using:
$$
\text{Count} = \sum_{i=1}^{n} (f[i] - i + 1)
$$

where f[i] is the furthest index such that the subarray [i, f[i]] is valid.

tle 😭
*/
/*# Approach:

We are given:

* An array `nums = [1, 2, ..., n]`
* A list of `conflictingPairs`, where no subarray should include both elements
of any conflicting pair.

We want to:

* **Count the number of valid subarrays**, i.e., subarrays that do **not**
contain any entire conflicting pair.
* Then, **maximize** this number by **removing one conflicting pair**.


### **Step 1: Fix a Starting Point `i`**

For every subarray starting at index `i`, figure out **how far you can go to the
right (`j`)** before you hit a conflicting pair.

Let’s say we want subarrays like:

```
[i, i]
[i, i+1]
...
[i, j]
```

We need to make sure **no conflicting pair \[a, b]** is fully inside `[i, j]`.


### **Step 2: For Each Conflicting Pair \[a, b]**

We standardize each pair as:

```
if a > b: swap them so a < b
```

Now check:

* If `a < i`: then the left element of the pair is **before i**, so this pair
can’t be fully inside any subarray starting at `i`. ✅ Safe.
* If `a ≥ i`: then to avoid including both `a` and `b`, you must stop the
subarray **before b**. That is:

  ```
  j < b
  ```

So for every conflicting pair starting at or after `i`, we need:

```
j < min of all such b's
```

We define this minimum as:

```
b₁ = min(b such that a ≥ i)
```

So the valid values of `j` lie in the range:

```
[i, min(b₁, n+1) - 1]
```

The number of valid subarrays starting at `i` is:

```
min(b₁, n+1) - i
```

---

### **Step 3: Speeding This Up With Suffix Min Arrays**

We want to compute `b₁` quickly for each `i`.

So:

* Create an array `bMin1[i]`: the smallest b for conflicting pairs where `a ==
i`
* Also track `bMin2[i]`: second smallest b (used later for deletion logic)

Then compute:

```cpp
suffixMin1[i] = min(bMin1[i], suffixMin1[i+1])
```

Now for each index `i`, `suffixMin1[i]` gives us `b₁`, and lets us compute valid
subarray count in `O(1)`.

---

### **Step 4: Consider Deleting a Conflicting Pair**

Suppose we want to delete a specific conflicting pair that affects `b₁` at index
`i`.

* After deletion, `b₁` might change → more `j` values become valid.
* Let’s denote the **new b₁** after deletion as `b₁′ = min(b₂, bMin2[i])`

So the **additional valid subarrays** we gain at index `i` is:

```
min(b₁′, n+1) - min(b₁, n+1)
```

We record this in:

```
delCount[i] += min(b₁′, n+1) - min(b₁, n+1)
```

---

### **Step 5: Final Result**

The final answer is:

```
baseCount + max(delCount)
```

Where:

* `baseCount` is the total number of valid subarrays **without deleting
anything**
* `max(delCount)` is the best improvement we can get by deleting one pair

---

## ✅ Why This is Fast

* You avoid checking all pairs individually per subarray
* Use **preprocessing + suffix mins** to get optimal j ranges
* Then, simulate the effect of deleting just one pair efficiently

### ⏱ Time Complexity

* Preprocessing: `O(n + m)`
* For each i, subarray count: `O(n)`
* Deletion impact: `O(m)`

Total: `O(n + m)`


## 🧠 Visual Summary

| Step                   | What Happens                                  |
| ---------------------- | --------------------------------------------- |
| Fix `i`                | Consider subarrays starting at `i`            |
| For each `[a,b]`       | Restrict `j < b` if `a ≥ i`                   |
| Use `b₁ = min(b_k)`    | Gives you max `j` for each `i`                |
| Track `bMin1`, `bMin2` | Fast suffix min lookup                        |
| Try deleting one pair  | See if it improves `b₁` → gain more subarrays |
| Final answer           | `baseCount + max extra from any one deletion` |



    */

class Solution {
public:
  long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
    vector<int> bMin1(n + 1, INT_MAX), bMin2(n + 1, INT_MAX);
    for (const auto& pair : conflictingPairs) {
      int a = min(pair[0], pair[1]), b = max(pair[0], pair[1]);
      if (bMin1[a] > b) {
        bMin2[a] = bMin1[a];
        bMin1[a] = b;
      } else if (bMin2[a] > b) {
        bMin2[a] = b;
      }
    }
    long long res = 0;
    int ib1 = n, b2 = INT_MAX;
    vector<long long> delCount(n + 1, 0);
    for (int i = n; i >= 1; i--) {
      if (bMin1[ib1] > bMin1[i]) {
        b2 = min(b2, bMin1[ib1]);
        ib1 = i;
      } else {
        b2 = min(b2, bMin1[i]);
      }
      res += min(bMin1[ib1], n + 1) - i;
      delCount[ib1] += min(min(b2, bMin2[ib1]), n + 1) - min(bMin1[ib1], n + 1);
    }
    return res + *max_element(delCount.begin(), delCount.end());
  }
};
// sub:
// https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/submissions/1711884830/
// sol:
// https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/solutions/7006574/3480-maximize-subarrays-after-removing-o-ojey/
//  time: O(n)
//  space: O(n)
