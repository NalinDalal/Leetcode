/*3477. Fruits Into Baskets II
You are given two arrays of integers, fruits and baskets, each of length n,
where fruits[i] represents the quantity of the ith type of fruit, and baskets[j]
represents the capacity of the jth basket.

From left to right, place the fruits according to these rules:

Each fruit type must be placed in the leftmost available basket with a capacity
greater than or equal to the quantity of that fruit type. Each basket can hold
only one type of fruit. If a fruit type cannot be placed in any basket, it
remains unplaced. Return the number of fruit types that remain unplaced after
all possible allocations are made.



Example 1:

Input: fruits = [4,2,5], baskets = [3,5,4]

Output: 1

Explanation:

fruits[0] = 4 is placed in baskets[1] = 5.
fruits[1] = 2 is placed in baskets[0] = 3.
fruits[2] = 5 cannot be placed in baskets[2] = 4.
Since one fruit type remains unplaced, we return 1.

Example 2:

Input: fruits = [3,6,1], baskets = [6,4,7]

Output: 0

Explanation:

fruits[0] = 3 is placed in baskets[0] = 6.
fruits[1] = 6 cannot be placed in baskets[1] = 4 (insufficient capacity) but can
be placed in the next available basket, baskets[2] = 7. fruits[2] = 1 is placed
in baskets[1] = 4. Since all fruits are successfully placed, we return 0.



Constraints:

n == fruits.length == baskets.length
1 <= n <= 100
1 <= fruits[i], baskets[i] <= 1000



Hint 1
Simulate the operations for each fruit as described
*/

/*Approach:
- fruits[i]: the size of the i-th fruit.

- baskets[i]: the capacity of the i-th basket.

Assign each fruit to a unique basket whose capacity is at least as large as the
fruit. You can use each basket only once. Return the n
*/

class Solution {
public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n = fruits.size();
    if (n == 0)
      return 0;

    int size = 1;
    while (size < n)
      size <<= 1;
    vector<int> seg(2 * size, 0);

    for (int i = 0; i < n; ++i) {
      seg[size + i] = baskets[i];
    }
    for (int i = size - 1; i > 0; --i) {
      seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    }

    auto update = [&](int pos) {
      pos += size;
      seg[pos] = 0;
      for (pos >>= 1; pos >= 1; pos >>= 1) {
        seg[pos] = max(seg[2 * pos], seg[2 * pos + 1]);
      }
    };

    auto query = [&](int x) {
      int pos = 1;
      int l = 0, r = size - 1;
      while (pos < size) {
        int mid = (l + r) / 2;
        if (seg[2 * pos] >= x) {
          pos = 2 * pos;
          r = mid;
        } else {
          pos = 2 * pos + 1;
          l = mid + 1;
        }
      }
      if (l < n && seg[pos] >= x) {
        return l;
      }
      return -1;
    };

    int unplaced = 0;
    for (int fruit : fruits) {
      int idx = query(fruit);
      if (idx == -1) {
        ++unplaced;
      } else {
        update(idx);
      }
    }
    return unplaced;
  }
};
// sub:
// https://leetcode.com/problems/fruits-into-baskets-ii/submissions/1567659243/?envType=daily-question&envId=2025-08-05
// sol:
// https://leetcode.com/problems/fruits-into-baskets-ii/solutions/7045726/3477-fruits-into-baskets-ii-by-nalindala-uk6y/
