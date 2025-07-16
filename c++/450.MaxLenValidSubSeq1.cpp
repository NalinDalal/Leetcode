/*3201. Find the Maximum Length of Valid Subsequence I
You are given an integer array nums.
A subsequence sub of nums with length x is called valid if it satisfies:

(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x -
1]) % 2. Return the length of the longest valid subsequence of nums.

A subsequence is an array that can be derived from another array by deleting
some or no elements without changing the order of the remaining elements.



Example 1:

Input: nums = [1,2,3,4]

Output: 4

Explanation:

The longest valid subsequence is [1, 2, 3, 4].

Example 2:

Input: nums = [1,2,1,1,2,1,2]

Output: 6

Explanation:

The longest valid subsequence is [1, 2, 1, 2, 1, 2].

Example 3:

Input: nums = [1,3]

Output: 2

Explanation:

The longest valid subsequence is [1, 3].



Constraints:

2 <= nums.length <= 2 * 105
1 <= nums[i] <= 107

Hint 1
The possible sequence either contains all even elements, all odd elements,
alternate even odd, or alternate odd even elements. Hint 2 Considering only the
parity of elements, there are only 4 possibilities and we can try all of them.
Hint 3
When selecting an element with any parity, try to select the earliest one.
*/

// so do like calculate for 0,1 index
// then calculate for 1,2; if matches previous increase count
// do till last unless breaks
// return count
// else it's odd
// Thus, for a valid subsequence of length x, every adjacent pair must have the
// same parity pattern: either always same or always different.

/* all elements at odd indices in the subsequence must have the same parity, and
all elements at even indices must also have the same parity. 4 possibilities:
1. All elements are even.
2. All elements are odd.
3. Elements at odd indices are odd, and elements at even indices are even.
4. Elements at odd indices are even, and elements at even indices are odd.

traverse the entire nums array and calculate the maximum length of a subsequence
that fits the chosen pattern. While traversing, if the current number satisfies
the required parity based on its position in the subsequence, we greedily
increase the length by 1. Finally, we return the maximum subsequence length
across all possibilities.
*/

class Solution {
public:
  int maximumLength(vector<int>& nums) {
    int res = 0;
    vector<vector<int>> patterns = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    for (auto& pattern : patterns) {
      int cnt = 0;
      for (int num : nums) {
        if (num % 2 == pattern[cnt % 2]) {
          cnt++;
        }
      }
      res = max(res, cnt);
    }
    return res;
  }
};
// Time: O(n)
// Space: O(1)
// sub:
// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/submissions/1700022817/?envType=daily-question&envId=2025-07-16
// sol:
// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/solutions/6966556/3201-find-the-maximum-length-of-valid-su-tu7u/
