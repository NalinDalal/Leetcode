/* 2966. Divide Array Into Arrays With Max Difference
You are given an integer array nums of size n where n is a multiple of 3 and a
positive integer k.

Divide the array nums into n / 3 arrays of size 3 satisfying the following
condition:

The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing the arrays. If it is impossible to satisfy the
conditions, return an empty array. And if there are multiple answers, return any
of them.



Example 1:

Input: nums = [1,3,4,8,7,9,3,5,1], k = 2

Output: [[1,1,3],[3,4,5],[7,8,9]]

Explanation:

The difference between any two elements in each array is less than or equal
to 2.

Example 2:

Input: nums = [2,4,2,2,5,2], k = 2

Output: []

Explanation:

Different ways to divide nums into 2 arrays of size 3 are:

[[2,2,2],[2,4,5]] (and its permutations)
[[2,2,4],[2,2,5]] (and its permutations)
Because there are four 2s there will be an array with the elements 2 and 5 no
matter how we divide it. since 5 - 2 = 3 > k, the condition is not satisfied and
so there is no valid division.

Example 3:

Input: nums = [4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11], k = 14

Output: [[2,2,12],[4,8,5],[5,9,7],[7,8,5],[5,9,10],[11,12,2]]

Explanation:

The difference between any two elements in each array is less than or equal
to 14.



Constraints:

n == nums.length
1 <= n <= 105
n is a multiple of 3
1 <= nums[i] <= 105
1 <= k <= 105

Hint 1
Try to use a greedy approach.
Hint 2
Sort the array and try to group each 3 consecutive elements.
*/

/* Sort the array so that close numbers are together.

Greedily group every 3 elements as a triplet.

Check the maximum difference in each triplet. If any triplet has a difference >
k, return an empty array.*/

/*
1. Sort nums.

2. Traverse with step size of 3.

3. For each group of 3 elements:

- Check max - min ≤ k.

- If valid, push to result.

- Else, return {}.*/
class Solution {
public:
  vector<vector<int>> divideArray(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    for (int i = 0; i < nums.size(); i += 3) {
      int a = nums[i], b = nums[i + 1], c = nums[i + 2];
      if (c - a > k) {
        return {}; // Invalid triplet
      }
      res.push_back({a, b, c});
    }

    return res;
  }
};
// sub:
// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/submissions/1667811801/?envType=daily-question&envId=2025-06-18
// sol:
// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/solutions/6856057/2966-divide-array-into-arrays-with-max-d-lu25/
