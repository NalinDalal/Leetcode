/*3346. Maximum Frequency of an Element After Performing Operations I

You are given an integer array nums and two integers k and numOperations.

You must perform an operation numOperations times on nums, where in each
operation you:

Select an index i that was not selected in any previous operations.
Add an integer in the range [-k, k] to nums[i].
Return the maximum possible frequency of any element in nums after performing
the operations.


Example 1:
Input: nums = [1,4,5], k = 1, numOperations = 2
Output: 2
Explanation:
We can achieve a maximum frequency of two by:
Adding 0 to nums[1]. nums becomes [1, 4, 5].
Adding -1 to nums[2]. nums becomes [1, 4, 4].

Example 2:
Input: nums = [5,11,20,20], k = 5, numOperations = 1
Output: 2
Explanation:
We can achieve a maximum frequency of two by:Adding 0 to nums[1].


Constraints:=
1 <= nums.length <= 105
1 <= nums[i] <= 105
0 <= k <= 105
0 <= numOperations <= nums.length


Hint 1
Sort the array and try each value in range as a candidate.
*/

/*Intuition:
1. Sort the array → this ensures you always move smaller numbers up to match a
larger one.

2. Use a sliding window:
    - Right pointer (`r`) expands the window.
    - Keep track of how many total increments are needed to make all numbers in
the window equal to `nums[r]`.
    - If the required operations exceed `numOperations`, shrink the window from
the left.

3. The largest valid window size is your max frequency.
    */
/*Approach:
### Step 1. Enumerate the target value

Let the minimum and maximum values in `nums` be `num_min` and `num_max`.
The target value we want to maximize frequency for must lie somewhere in
`[num_min, num_max]`.

We can **enumerate** each possible target value `m_i` in that range.
For each `m_i`, we want to find how many elements can be turned into `m_i` using
at most `numOperations` operations.

---

### Step 2. Identify transformable elements (via `k` constraint)

For each `m_i`, only elements within `[m_i − k, m_i + k]` can be converted into
`m_i`.

If we sort `nums`, we can quickly find the range of such elements using **binary
search**:

* `l` = first index where `nums[l] >= m_i − k`
* `r` = last index where `nums[r] <= m_i + k`

All elements in the interval `[l, r]` are candidates that can be transformed
into `m_i`.

---

### Step 3. Apply `numOperations` constraint

Even if there are many candidates, we can use **at most `numOperations`**
transformations. So the maximum number of new elements we can add to frequency
of `m_i` is:

```
f_i = min(r − l + 1, numOperations)
```

---

### Step 4. Include elements already equal to `m_i`

If the value `m_i` already appears in the array, we don’t need to spend any
operations on those occurrences. Let `count_i` be the count of `m_i` in `nums`.

Thus, the final frequency we can achieve for `m_i` is:

```
f_i = min(r − l + 1, numOperations + count_i)
```

We can update our global answer as:

```
ans = max(ans, f_i)
```

---

### Step 5. Complexity Analysis

| Complexity | Explanation | | ---------- |
-----------------------------------------------------------------------------------------------
| | **Time**   | `O(n log n + M log n)` — sorting + binary search per target
value (`M = num_max − num_min + 1`) | | **Space**  | `O(n)` — for storing counts
|

---

### Summary

1. Sort the array.
2. Enumerate possible target values `m_i` in `[num_min, num_max]`.
3. For each `m_i`, use binary search to find range `[m_i − k, m_i + k]`.
4. Compute `f_i = min(r − l + 1, numOperations + count_i)`.
5. Take the maximum `f_i` across all `m_i`.
 */
class Solution {
public:
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    sort(nums.begin(), nums.end());

    int ans = 0;
    unordered_map<int, int> numCount;

    int lastNumIndex = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != nums[lastNumIndex]) {
        numCount[nums[lastNumIndex]] = i - lastNumIndex;
        ans = max(ans, i - lastNumIndex);
        lastNumIndex = i;
      }
    }

    numCount[nums[lastNumIndex]] = nums.size() - lastNumIndex;
    ans = max(ans, (int)nums.size() - lastNumIndex);

    auto leftBound = [&](int value) {
      int left = 0, right = nums.size() - 1;
      while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] < value) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
      return left;
    };

    auto rightBound = [&](int value) {
      int left = 0, right = nums.size() - 1;
      while (left < right) {
        int mid = (left + right + 1) / 2;
        if (nums[mid] > value) {
          right = mid - 1;
        } else {
          left = mid;
        }
      }
      return left;
    };

    for (int i = nums.front(); i <= nums.back(); i++) {
      int l = leftBound(i - k);
      int r = rightBound(i + k);

      int tempAns;
      if (numCount.count(i)) {
        tempAns = min(r - l + 1, numCount[i] + numOperations);
      } else {
        tempAns = min(r - l + 1, numOperations);
      }
      ans = max(ans, tempAns);
    }

    return ans;
  }
};

// sub:
// https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/submissions/1807418767/?envType=daily-question&envId=2025-10-21
// sol:
// https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/solutions/7290165/3346-maximum-frequency-of-an-element-aft-gtjp/
