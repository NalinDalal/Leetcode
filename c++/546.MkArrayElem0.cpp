/*3354. Make Array Elements Equal to Zero
You are given an integer array nums.

Start by selecting a starting position curr such that nums[curr] == 0, and
choose a movement direction of either left or right.

After that, you repeat the following process:

If curr is out of the range [0, n - 1], this process ends.
If nums[curr] == 0, move in the current direction by incrementing curr if you
are moving right, or decrementing curr if you are moving left. Else if
nums[curr] > 0: Decrement nums[curr] by 1. Reverse your movement direction (left
becomes right and vice versa). Take a step in your new direction. A selection of
the initial position curr and movement direction is considered valid if every
element in nums becomes 0 by the end of the process.

Return the number of possible valid selections.



Example 1:
Input: nums = [1,0,2,0,3]
Output: 2
Explanation:
The only possible valid selections are the following:
Choose curr = 3, and a movement direction to the left.
[1,0,2,0,3] -> [1,0,2,0,3] -> [1,0,1,0,3] -> [1,0,1,0,3] -> [1,0,1,0,2] ->
[1,0,1,0,2] -> [1,0,0,0,2] -> [1,0,0,0,2] -> [1,0,0,0,1] -> [1,0,0,0,1] ->
[1,0,0,0,1] -> [1,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] ->
[0,0,0,0,1] -> [0,0,0,0,0]. Choose curr = 3, and a movement direction to the
right. [1,0,2,0,3] -> [1,0,2,0,3] -> [1,0,2,0,2] -> [1,0,2,0,2] -> [1,0,1,0,2]
-> [1,0,1,0,2] -> [1,0,1,0,1] -> [1,0,1,0,1] -> [1,0,0,0,1] -> [1,0,0,0,1] ->
[1,0,0,0,0] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [0,0,0,0,0].

Example 2:
Input: nums = [2,3,4,0,4,1,0]
Output: 0
Explanation:
There are no possible valid selections.



Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 100
There is at least one element i where nums[i] == 0.
*/

/*1. for each index `i` where `nums[i]==0`, simulate twice: `left`,`right`
 2. Simulation:
    - Make a copy of nums (since it mutates).
    - Follow the process until curr goes out of bounds.
    - If, at the end, all elements in the copy are 0 → it's a valid selection.
3. Count all valid cases.
*/

class Solution {
public:
  int countValidSelections(vector<int>& nums) {
    int n = nums.size();
    int valid = 0;

    auto simulate = [&](int start, int dir) {
      vector<int> arr = nums; // make a copy
      int curr = start;

      while (curr >= 0 && curr < n) {
        if (arr[curr] == 0) {
          curr += dir;
        } else {
          arr[curr]--;
          dir *= -1; // reverse direction
          curr += dir;
        }
      }

      for (int x : arr)
        if (x != 0)
          return false;
      return true;
    };

    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        if (simulate(i, 1)) // right
          valid++;
        if (simulate(i, -1)) // left
          valid++;
      }
    }

    return valid;
  }
};
// sub:
// https://leetcode.com/problems/make-array-elements-equal-to-zero/submissions/1814295639/?envType=daily-question&envId=2025-10-28
// sol:
// https://leetcode.com/problems/make-array-elements-equal-to-zero/solutions/7308534/3354-make-array-elements-equal-to-zero-b-8sds/
