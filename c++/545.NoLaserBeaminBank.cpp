/*2125. Number of Laser Beams in a Bank
Anti-theft security devices are activated inside a bank. You are given a
0-indexed binary string array bank representing the floor plan of the bank,
which is an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's
and '1's. '0' means the cell is empty, while'1' means the cell has a security
device.

There is one laser beam between any two security devices if both conditions are
met:

The two devices are located on two different rows: r1 and r2, where r1 < r2.
For each row i where r1 < i < r2, there are no security devices in the ith row.
Laser beams are independent, i.e., one beam does not interfere nor join with
another.

Return the total number of laser beams in the bank.



Example 1:


Input: bank = ["011001","000000","010100","001000"]
Output: 8
Explanation: Between each of the following device pairs, there is one beam. In
total, there are 8 beams:
 * bank[0][1] -- bank[2][1]
 * bank[0][1] -- bank[2][3]
 * bank[0][2] -- bank[2][1]
 * bank[0][2] -- bank[2][3]
 * bank[0][5] -- bank[2][1]
 * bank[0][5] -- bank[2][3]
 * bank[2][1] -- bank[3][2]
 * bank[2][3] -- bank[3][2]
Note that there is no beam between any device on the 0th row with any on the 3rd
row. This is because the 2nd row contains security devices, which breaks the
second condition. Example 2:


Input: bank = ["000","111","000"]
Output: 0
Explanation: There does not exist two devices located on two different rows.


Constraints:

m == bank.length
n == bank[i].length
1 <= m, n <= 500
bank[i][j] is either '0' or '1'.


Hint 1
What is the commonality between security devices on the same row?
Hint 2
Each device on the same row has the same number of beams pointing towards the
devices on the next row with devices. Hint 3 If you were given an integer array
where each element is the number of security devices on each row, can you solve
it? Hint 4 Convert the input to such an array, skip any row with no security
device, then find the sum of the product between adjacent elements.
*/
/*# Intuition

We have a **bank security system** represented as a grid of strings, where:

* Each string is a row (e.g. `"011001"`).
* Each character is either:

  * `'1'` → a **security device**
  * `'0'` → an **empty space**

Each **security device emits beams horizontally and vertically** (but only
*downward* is relevant here). The key rule (from the problem “**Number of Laser
Beams in a Bank**” — LeetCode #2125) is:

> A laser beam is formed **between every pair of devices** in *two consecutive
non-empty rows*.

That means:

* If one row has `x` devices and the next non-empty row has `y` devices,
  → total beams between them = `x * y`.

---

# Approach Breakdown (based on hints)

#### Hint 1 & 2:

Devices on the same row are not connected — beams only form **between rows**.

#### Hint 3:

We only care about how many devices each row has, not their positions.
So for each row, count the number of `'1'`.

Example:

```cpp
bank = ["011001", "000000", "010100", "001000"]

→ device counts = [3, 0, 2, 1]
```

#### Hint 4:

Ignore any row with zero devices → `[3, 2, 1]`.

Now, for each **pair of consecutive non-empty rows**, multiply:

```
(3 * 2) + (2 * 1) = 6 + 2 = 8 beams total
```

---

## Steps (Algorithm)

1. Initialize `prev = 0`, `ans = 0`.
2. Loop through each row in `bank`:

   * Count devices in that row: `count = number of '1's`.
   * If `count > 0`:

     * `ans += prev * count`  // beams between this and previous non-empty row
     * `prev = count`         // current becomes the new previous non-empty row
3. Return `ans`.

    */

class Solution {
public:
  int numberOfBeams(vector<string>& bank) {
    int prev = 0, ans = 0;
    for (auto& row : bank) {
      int curr = count(row.begin(), row.end(), '1');
      if (curr > 0) {
        ans += prev * curr;
        prev = curr;
      }
    }
    return ans;
  }
};
// sub:
// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/submissions/1813301399/?envType=daily-question&envId=2025-10-27
// sol:
// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/solutions/7305870/2125-number-of-laser-beams-in-a-bank-by-s7g2o/
