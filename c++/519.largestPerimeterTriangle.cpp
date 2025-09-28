/*976. Largest Perimeter Triangle
Given an integer array nums, return the largest perimeter of a triangle with a
non-zero area, formed from three of these lengths. If it is impossible to form
any triangle of a non-zero area, return 0.



Example 1:

Input: nums = [2,1,2]
Output: 5
Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
Example 2:

Input: nums = [1,2,1,10]
Output: 0
Explanation:
You cannot use the side lengths 1, 1, and 2 to form a triangle.
You cannot use the side lengths 1, 1, and 10 to form a triangle.
You cannot use the side lengths 1, 2, and 10 to form a triangle.
As we cannot use any three side lengths to form a triangle of non-zero area, we
return 0.


Constraints:

3 <= nums.length <= 104
1 <= nums[i] <= 106
*/

/*triangle property: sum of 2 must be greater then 3rd
so given a vector of sides, find all combination of 3 sides,
if you sort the vector converts to 3 pointer problem

return largest possible perimeter from the vector
else return -1

sort the vector in descending order
first triplet (a,b,c) where a<b+c will give largest perimeter
*/
class Solution {
public:
  int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
      int a = nums[i], b = nums[i + 1], c = nums[i + 2];
      if (a < b + c) {
        return a + b + c; // largest perimeter found
      }
    }
    return 0; // no valid triangle
  }
};
// sub:
// https://leetcode.com/problems/largest-perimeter-triangle/submissions/1785394454/?envType=daily-question&envId=2025-09-28
// sol:
// https://leetcode.com/problems/largest-perimeter-triangle/solutions/7231449/976-largest-perimeter-triangle-by-nalind-9b47/
