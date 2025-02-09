/* 2364. Count Number of Bad Pairs

You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad
pair if i < j and j - i != nums[j] - nums[i].

Return the total number of bad pairs in nums.


Example 1:
Input: nums = [4,1,3,3]
Output: 5
Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.

Example 2:
Input: nums = [1,2,3,4,5]
Output: 0
Explanation: There are no bad pairs.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109*/

class Solution {
public:
  long long countBadPairs(vector<int>& nums) {
    long long badPair = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums.size(); j++) {
        if (i < j && j - i != nums[j] - nums[i])
          badPair++;
      }
    }
    return badPair;
  }
};

// give tle, possible sol: use hadMap
//(i,j) is bad if j-1!=nums[i]-nums[j]
// trnsforms to diff[i]=nums[i]-i;if diff[i]==diff[j] then good
// so totalpair are n^2-n/2
// badPair=total-good
class Solution1 {
public:
  long long countBadPairs(std::vector<int>& nums) {
    long long n = nums.size();
    long long totalPairs = n * (n - 1) / 2;
    std::unordered_map<int, long long> freq;
    long long goodPairs = 0;

    for (int i = 0; i < n; i++) {
      int diff = nums[i] - i;
      goodPairs +=
          freq[diff]; // Count how many times this diff has appeared before
      freq[diff]++;   // Update frequency
    }

    return totalPairs - goodPairs;
  }
};

// Time: O(n)
// Space: O(1)
// sub:
// https://leetcode.com/problems/count-number-of-bad-pairs/submissions/1536853557/
// sol:
// https://leetcode.com/problems/count-number-of-bad-pairs/solutions/6397607/2364-count-number-of-bad-pairs-by-nalind-irj9/
