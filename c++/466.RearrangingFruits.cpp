/*2561. Rearranging Fruits
You have two fruit baskets containing n fruits each. You are given two 0-indexed
integer arrays basket1 and basket2 representing the cost of fruit in each
basket. You want to make both baskets equal. To do so, you can use the following
operation as many times as you want:

Chose two indices i and j, and swap the ith fruit of basket1 with the jth fruit
of basket2. The cost of the swap is min(basket1[i],basket2[j]). Two baskets are
considered equal if sorting them according to the fruit cost makes them exactly
the same baskets.

Return the minimum cost to make both the baskets equal or -1 if impossible.



Example 1:

Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
Output: 1
Explanation: Swap index 1 of basket1 with index 0 of basket2, which has cost 1.
Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays
makes them equal. Example 2:

Input: basket1 = [2,3,4,1], basket2 = [3,2,5,1]
Output: -1
Explanation: It can be shown that it is impossible to make both the baskets
equal.


Constraints:

basket1.length == basket2.length
1 <= basket1.length <= 105
1 <= basket1[i],basket2[i] <= 109

Hint 1
Create two frequency maps for both arrays, and find the minimum element among
all elements of both arrays. Hint 2 Check if the sum of frequencies of an
element in both arrays is odd, if so return -1 Hint 3 Store the elements that
need to be swapped in a vector, and sort it. Hint 4 Can we reduce swapping cost
with the help of minimum element? Hint 5 Calculate the minimum cost of swapping.
*/

// Intuition:
// 2 basket: basket1, basket2
// find the minimum total cost to make both baskets equal by swapping elements
// Swapping cost is the minimum of the two swapped elements.

// Approach
/* ## Step 1: Frequency maps + min element
We need:
    - `freq1[x]`: how many times x occurs in basket1
    - `freq2[x]`: how many times x occurs in basket2
    - `minVal`: the smallest fruit value (across both baskets)

## Step 2: Check total frequency of each value is even
If not → impossible → return `-1`.

## Step 3: Build list of elements to swap
We’ll store:
    - All the extra elements in basket1 (more than needed) → extraFrom1
    - All the extra elements in basket2 → extraFrom2

Note: To make things easier, we’ll collect half of the difference (since one
swap fixes two mismatches).

## Step 4: Sort and optimize swaps
Sort both `extraFrom1` and `extraFrom2`. We want to pair smallest with largest
(since that's worst-case), but we will always choose the cheaper option between:
    - direct swap: `min(a, b)`
    - indirect swap: `2 * minVal`

## Step 5: Sum the minimum costs
*/

class Solution {
public:
  long long minCost(vector<int>& basket1, vector<int>& basket2) {
    map<int, int> freq1, freq2;
    map<int, int> totalFreq;
    int minVal = INT_MAX;

    // Count frequencies and find min
    for (int x : basket1) {
      freq1[x]++;
      totalFreq[x]++;
      minVal = min(minVal, x);
    }
    for (int x : basket2) {
      freq2[x]++;
      totalFreq[x]++;
      minVal = min(minVal, x);
    }

    // Check if it's possible
    for (auto& [val, total] : totalFreq) {
      if (total % 2 != 0)
        return -1;
    }

    vector<int> extraFrom1, extraFrom2;

    // Find excess elements
    for (auto& [val, _] : totalFreq) {
      int count1 = freq1[val];
      int count2 = freq2[val];
      int diff = count1 - (totalFreq[val] / 2);

      if (diff > 0) {
        // basket1 has more than needed
        for (int i = 0; i < diff; ++i) {
          extraFrom1.push_back(val);
        }
      } else if (diff < 0) {
        // basket2 has more than needed
        for (int i = 0; i < -diff; ++i) {
          extraFrom2.push_back(val);
        }
      }
    }

    sort(extraFrom1.begin(), extraFrom1.end());
    sort(extraFrom2.rbegin(), extraFrom2.rend()); // reverse sort

    long long cost = 0;
    int n = extraFrom1.size();

    for (int i = 0; i < n; ++i) {
      int a = extraFrom1[i];
      int b = extraFrom2[i];
      cost += min(min(a, b), 2 * minVal);
    }

    return cost;
  }
};
// sub:
// https://leetcode.com/problems/rearranging-fruits/submissions/1720664571/?envType=daily-question&envId=2025-08-02
// sol:
// https://leetcode.com/problems/rearranging-fruits/solutions/7036216/2561-rearranging-fruits-by-nalindalal200-nth0/
