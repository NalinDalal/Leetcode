/* 128. Longest Consecutive Sequence
Given an unsorted array of integers nums, return the length of the longest
consecutive elements sequence. You must write an algorithm that runs in O(n)
time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
Therefore its length is 4. Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/

/* my approach
1. sort the array
2. Initialise count=0
2. if ({ith element +1 } is equal to {i+1th element}){count++;
return count;}
*/

// Solution
// Sort the array firstly,
// then initialise 2 var, curr, long
// loop over the array
/* Loop->{
    agar ith elem != i-1 elem
        usme bhi agar i elem=i-1 elem+1
            count++
        nhi to fir
            long=max(curr,long)
            curr=1
last me max(long,curr) ko log krana h
*/

class Solution {
public:
  int longestConsecutive(std::vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    std::sort(nums.begin(), nums.end());

    int longestStreak = 1;
    int currentStreak = 1;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[i - 1]) {
        if (nums[i] == nums[i - 1] + 1) {
          currentStreak++;
        } else {
          longestStreak = std::max(longestStreak, currentStreak);
          currentStreak = 1;
        }
      }
    }

    return std::max(longestStreak, currentStreak);
  }
};
