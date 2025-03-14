/*2226. Maximum Candies Allocated to K Children
You are given a 0-indexed integer array candies. Each element in the array
denotes a pile of candies of size candies[i]. You can divide each pile into any
number of sub piles, but you cannot merge two piles together.

You are also given an integer k. You should allocate piles of candies to k
children such that each child gets the same number of candies. Each child can be
allocated candies from only one pile of candies and some piles of candies may go
unused.

Return the maximum number of candies each child can get.



Example 1:

Input: candies = [5,8,6], k = 3
Output: 5
Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and
candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of
sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. It
can be proven that each child cannot receive more than 5 candies. Example 2:

Input: candies = [2,5], k = 11
Output: 0
Explanation: There are 11 children but only 7 candies in total, so it is
impossible to ensure each child receives at least one candy. Thus, each child
gets no candy and the answer is 0.


Constraints:

1 <= candies.length <= 105
1 <= candies[i] <= 107
1 <= k <= 1012

Hint 1: For a fixed number of candies c, how can you check if each child can get
c candies? Hint 2: Use binary search to find the maximum c as the answer.
*/

// determine the maximum number of candies 𝑐 that can be given to each child,
// ensuring that at least 𝑘 children receive 𝑐 candies.
class Solution {
public:
  bool canDistribute(vector<int>& candies, long long k, int c) {
    long long count = 0;
    for (int num : candies) {
      count += num / c; // Count how many children can get c candies
    }
    return count >= k;
  }
  int maximumCandies(vector<int>& candies, long long k) {
    // use Binary Search to find the maximum 𝑐 such that distributing the
    // candies is possible.
    int low = 1, high = *max_element(candies.begin(), candies.end()),
        result = 0;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (canDistribute(candies, k, mid)) {
        result = mid;  // Store the valid c
        low = mid + 1; // Try a bigger c
      } else {
        high = mid - 1; // Try a smaller c
      }
    }

    return result;
  }
};

// sub:
// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/submissions/1573370677/?envType=daily-question&envId=2025-03-14
// sol:
// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/solutions/6535464/2226-maximum-candies-allocated-to-k-chil-k06e/
