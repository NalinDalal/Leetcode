/* 1394. Find Lucky Integer in an Array
Given an array of integers arr, a lucky integer is an integer that has a
frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer
return -1.



Example 1:

Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
Example 2:

Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
Example 3:

Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.


Constraints:

1 <= arr.length <= 500
1 <= arr[i] <= 500

Hint 1
Count the frequency of each integer in the array.
Hint 2
Get all lucky numbers and return the largest of them.
*/

// create a map
// no associated with it's frequency
// int ans=-1
// now check map, when ans=index from last
// return ans;

class Solution {
public:
  int findLucky(vector<int>& arr) {

    unordered_map<int, int> freq;

    // Count frequency of each number
    for (int num : arr) {
      freq[num]++;
    }

    int ans = -1;
    for (auto& [num, count] : freq) {
      if (num == count) {
        ans = max(ans, num); // Keep track of the largest lucky number
      }
    }

    return ans;
  }
};

// sub:
// https://leetcode.com/problems/find-lucky-integer-in-an-array/submissions/1687270822/
//  sol:
//  https://leetcode.com/problems/find-lucky-integer-in-an-array/solutions/6923715/1394-find-lucky-integer-in-an-array-by-n-ma35/
