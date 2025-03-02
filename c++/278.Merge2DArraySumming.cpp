/* 2570. Merge Two 2D Arrays by Summing Values

You are given two 2D integer arrays nums1 and nums2.

nums1[i] = [idi, vali] indicate that the number with the id idi has a value
equal to vali. nums2[i] = [idi, vali] indicate that the number with the id idi
has a value equal to vali. Each array contains unique ids and is sorted in
ascending order by id.

Merge the two arrays into one array that is sorted in ascending order by id,
respecting the following conditions:

Only ids that appear in at least one of the two arrays should be included in the
resulting array. Each id should be included only once and its value should be
the sum of the values of this id in the two arrays. If the id does not exist in
one of the two arrays, then assume its value in that array to be 0. Return the
resulting array. The returned array must be sorted in ascending order by id.



Example 1:

Input: nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
Output: [[1,6],[2,3],[3,2],[4,6]]
Explanation: The resulting array contains the following:
- id = 1, the value of this id is 2 + 4 = 6.
- id = 2, the value of this id is 3.
- id = 3, the value of this id is 2.
- id = 4, the value of this id is 5 + 1 = 6.
Example 2:

Input: nums1 = [[2,4],[3,6],[5,5]], nums2 = [[1,3],[4,3]]
Output: [[1,3],[2,4],[3,6],[4,3],[5,5]]
Explanation: There are no common ids, so we just include each id with its value
in the resulting list.


Constraints:

1 <= nums1.length, nums2.length <= 200
nums1[i].length == nums2[j].length == 2
1 <= idi, vali <= 1000
Both arrays contain unique ids.
Both arrays are in strictly ascending order by id.


Hint 1
Use a dictionary/hash map to keep track of the indices and their sum values.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                  vector<vector<int>>& nums2) {
    vector<vector<int>> result;
    int i = 0, j = 0;

    while (i < nums1.size() || j < nums2.size()) {
      if (j >= nums2.size() ||
          (i < nums1.size() && nums1[i][0] < nums2[j][0])) {
        result.push_back(nums1[i++]);
      } else if (i >= nums1.size() ||
                 (j < nums2.size() && nums2[j][0] < nums1[i][0])) {
        result.push_back(nums2[j++]);
      } else {
        result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
        i++;
        j++;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
  vector<vector<int>> nums2 = {{1, 4}, {3, 2}, {4, 1}};

  auto result = sol.mergeArrays(nums1, nums2);
  for (auto& row : result) {
    cout << "[" << row[0] << ", " << row[1] << "] ";
  }
  return 0;
}

// sub:
// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/submissions/1560336988/?envType=daily-question&envId=2025-03-02
// sol:
// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/solutions/6485941/2570-merge-two-2d-arrays-by-summing-valu-0vvh/
