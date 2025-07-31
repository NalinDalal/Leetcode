/*898. Bitwise ORs of Subarrays
Given an integer array arr, return the number of distinct bitwise ORs of all the
non-empty subarrays of arr.

The bitwise OR of a subarray is the bitwise OR of each integer in the subarray.
The bitwise OR of a subarray of one integer is that integer.

A subarray is a contiguous non-empty sequence of elements within an array.



Example 1:

Input: arr = [0]
Output: 1
Explanation: There is only one possible result: 0.
Example 2:

Input: arr = [1,1,2]
Output: 3
Explanation: The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1,
2]. These yield the results 1, 1, 2, 1, 3, 3. There are 3 unique values, so the
answer is 3. Example 3:

Input: arr = [1,2,4]
Output: 6
Explanation: The possible results are 1, 2, 3, 4, 6, and 7.


Constraints:

1 <= arr.length <= 5 * 104
0 <= arr[i] <= 109
*/

// what to do:
// find all subarray, store them in a vector
// then for each subarray, find bitwise or of all elements
// put that into a map
// then return the size of that map

class Solution {
public:
  int subarrayBitwiseORs(vector<int>& arr) {
    unordered_set<int> result; // Stores all unique OR results
    unordered_set<int> curr;   // ORs ending at current position
    unordered_set<int> next;   // ORs for next position

    for (int num : arr) {
      next.clear();
      next.insert(num);
      for (int x : curr) {
        next.insert(x | num); // OR current num with all previous ORs
      }
      curr = next;
      result.insert(curr.begin(), curr.end()); // Add all to result
    }

    return result.size();
  }
};
// sub:
// https://leetcode.com/problems/bitwise-ors-of-subarrays/submissions/1717876768/?envType=daily-question&envId=2025-07-31
// sol:
// https://leetcode.com/problems/bitwise-ors-of-subarrays/solutions/7026811/898-bitwise-ors-of-subarrays-by-nalindal-aap4/
