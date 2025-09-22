/*3005. Count Elements With Maximum Frequency
You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all
have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the
array.



Example 1:
Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum
frequency in the array. So the number of elements in the array with maximum
frequency is 4.

Example 2:
Input: nums = [1,2,3,4,5]
Output: 5
Explanation: All elements of the array have a frequency of 1 which is the
maximum. So the number of elements in the array with maximum frequency is 5.


Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100


Hint 1
Find frequencies of all elements of the array.
Hint 2
Find the elements that have the maximum frequencies and count their total
occurrences.
*/
/*First, count how many times each number appears in the array (frequency map).

Then, find the maximum frequency.

Finally, return the sum of occurrences of all elements that have this maximum
frequency.
*/

class Solution {
public:
  int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> freq;

    // Step 1: Count frequencies
    for (int num : nums) {
      freq[num]++;
    }

    // Step 2: Find maximum frequency
    int maxFreq = 0;
    for (auto& p : freq) {
      maxFreq = max(maxFreq, p.second);
    }

    // Step 3: Count total occurrences of elements with max frequency
    int result = 0;
    for (auto& p : freq) {
      if (p.second == maxFreq) {
        result += p.second;
      }
    }

    return result;
  }
};
// sub:
// https://leetcode.com/problems/count-elements-with-maximum-frequency/submissions/1778641279/?envType=daily-question&envId=2025-09-22
// sol:
// https://leetcode.com/problems/count-elements-with-maximum-frequency/solutions/7212458/3005-count-elements-with-maximum-frequen-lyxo/
