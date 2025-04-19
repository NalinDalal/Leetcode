/* 228. Summary Ranges
You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the
array exactly. That is, each element of nums is covered by exactly one of the
ranges, and there is no integer x such that x is in one of the ranges but not in
nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b


Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"


Constraints:

0 <= nums.length <= 20
-231 <= nums[i] <= 231 - 1
All the values of nums are unique.
nums is sorted in ascending order.
*/
#include <string>
#include <vector>
using namespace std;
// nums is sorted
// start with nums[0]
// check upto where the sequence breaks, like a[i+1]=a[i]+1
// then break and put the vector data: v[0]="0->a[i+1]"
// check for next sequence recursively, append in vector
// return vector
/* range [a,b] in the list should be output as:
    "a->b" if a != b
    "a" if a == b */

class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;
    int n = nums.size();
    if (n == 0)
      return result;

    int start = nums[0];

    for (int i = 1; i <= n; ++i) {
      // Check if current number continues the sequence
      if (i == n || nums[i] != nums[i - 1] + 1) {
        if (start == nums[i - 1]) {
          result.push_back(to_string(start));
        } else {
          result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
        }

        // Start new range if not at the end
        if (i < n) {
          start = nums[i];
        }
      }
    }

    return result;
  }
};
// sub:
// https://leetcode.com/problems/summary-ranges/submissions/1611105280/?envType=study-plan-v2&envId=top-interview-150
// sol:
// https://leetcode.com/problems/summary-ranges/solutions/6665617/228-summary-ranges-by-nalindalal2004-y2hj/
