/* 1550. Three Consecutive Odds
Given an integer array arr, return true if there are three consecutive odd
numbers in the array. Otherwise, return false.


Example 1:
Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.

Example 2:
Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.


Constraints:
1 <= arr.length <= 1000
1 <= arr[i] <= 1000
*/

class Solution {
public:
  bool threeConsecutiveOdds(vector<int>& arr) {
    bool ans = false;
    if (arr.size() <= 2)
      return ans;
    for (int i = 0; i < arr.size() - 2; i++) {
      // three consecutive odd numbers
      if (arr[i] % 2 && arr[i + 1] % 2 && arr[i + 2] % 2)
        ans = true;
    }
    return ans;
  }
};
// sub:
// https://leetcode.com/problems/three-consecutive-odds/submissions/1630815678/?envType=daily-question&envId=2025-05-11
