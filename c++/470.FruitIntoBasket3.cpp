/*3479. Fruits Into Baskets III
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
1 <= n <= 105
1 <= fruits[i], baskets[i] <= 109

Hint 1
Sort the baskets by the pair of (basket[i], i) in the array.
Hint 2
For each fruit from left to right, use binary search to find the first index in
the sorted array such that basket[i] >= fruit. Hint 3 Use a segment tree to
maintain the smallest original indices where basket[i] >= fruit. Hint 4 When a
valid index is found, set the corresponding point to infinity to mark it as
used.
*/

/* Approach
- apply square root decomposition to the baskets
- `n = baskets.size()`

- `m = \sqrt{n} (block size)`

- So, number of blocks = `ceil(n / m)`

Logic:
- Preprocess maxV[i]: max of each block i
- For each fruit:
    - Scan blocks from left to right:
        - If maxV[block] < fruit → skip
        - Else → scan that block’s baskets to find leftmost basket[i] ≥ fruit
    - Once used → set basket[i] = 0 and update maxV[block]
*/

class Solution {
public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n = baskets.size();
    int blockSize = sqrt(n) + 1;

    int numBlocks = (n + blockSize - 1) / blockSize;
    vector<int> maxV(numBlocks, 0);

    // Precompute max in each block
    for (int i = 0; i < n; ++i) {
      int block = i / blockSize;
      maxV[block] = max(maxV[block], baskets[i]);
    }

    int unplaced = 0;
    for (int fruit : fruits) {
      bool placed = false;
      for (int b = 0; b < numBlocks; ++b) {
        if (maxV[b] < fruit)
          continue;

        // Check block
        int start = b * blockSize;
        int end = min(n, start + blockSize);
        for (int i = start; i < end; ++i) {
          if (baskets[i] >= fruit) {
            baskets[i] = 0;
            // Recompute max of block
            maxV[b] = 0;
            for (int j = start; j < end; ++j)
              maxV[b] = max(maxV[b], baskets[j]);
            placed = true;
            break;
          }
        }
        if (placed)
          break;
      }
      if (!placed)
        unplaced++;
    }
    return unplaced;
  }
};

// TIme: O(n^3/2)
// Space: O(n^1/2)
// sub:
// https://leetcode.com/problems/fruits-into-baskets-iii/submissions/1725699338/?envType=daily-question&envId=2025-08-06
// sol:
// https://leetcode.com/problems/fruits-into-baskets-iii/solutions/7051367/3479-fruits-into-baskets-iii-by-nalindal-wstg/
