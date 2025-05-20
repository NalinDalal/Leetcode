/* 3355. Zero Array Transformation I
You are given an integer array nums of length n and a 2D array queries, where
queries[i] = [li, ri].

For each queries[i]:
Select a subset of indices within the range [li, ri] in nums.
Decrement the values at the selected indices by 1.
A Zero Array is an array where all elements are equal to 0.

Return true if it is possible to transform nums into a Zero Array after
processing all the queries sequentially, otherwise return false.



Example 1:
Input: nums = [1,0,1], queries = [[0,2]]
Output: true
Explanation:
For i = 0:
Select the subset of indices as [0, 2] and decrement the values at these indices
by 1. The array will become [0, 0, 0], which is a Zero Array.

Example 2:
Input: nums = [4,3,2,1], queries = [[1,3],[0,2]]
Output: false
Explanation:
For i = 0:
Select the subset of indices as [1, 2, 3] and decrement the values at these
indices by 1. The array will become [4, 2, 1, 0]. For i = 1: Select the subset
of indices as [0, 1, 2] and decrement the values at these indices by 1. The
array will become [3, 1, 0, 0], which is not a Zero Array.


Constraints:
1 <= nums.length <= 105
0 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= li <= ri < nums.length
 */

/* see traverse the array queries[i], we find a vector as [li,ri]
now apply a function to vector nums, such that
while(li<ri){
if(nums[li]==0)continue;
else nums[li]--;
li++;
}

once whole queries are processed, check if all elements of nums are zero
if then return true, else return false
*/

// tle:
/*class Solution {
public:
  bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    for (int i = 0; i < queries.size(); i++) {
      int li = queries[i][0];
      int ri = queries[i][1];
      for (int j = li; j <= ri; j++) {
        if (nums[j] == 0)
          continue;
        else
          nums[j]--;
      }
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (nums[i] != 0) {
        flag = false;
        break;
      }
    }
    return flag;
  }
};*/

/*create delta array to store no of opr via diff array
diff array: record the increment for each query on the number of operations.

For each query interval [left, right], increment deltaArray[left] by +1,
indicating an increase in the operation count starting from left. Decrement
deltaArray[right + 1] by -1, indicating that the operation count returns to its
original value after right + 1.

prefixSum on deltaArray: operationCounts[i]=prefixSum(deltaArray[0,i])

Traverse the nums array and the operationCounts array, comparing the actual
operation counts (operations) at each position to see if they meet the minimum
number of operations (target) required for zeroing.

 If all positions meet operations >= target, return true; otherwise, return
false.
 */
class Solution {
public:
  bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> deltaArray(nums.size() + 1, 0);
    for (const auto& query : queries) {
      int left = query[0];
      int right = query[1];
      deltaArray[left] += 1;
      deltaArray[right + 1] -= 1;
    }
    vector<int> operationCounts;
    int currentOperations = 0;
    for (int delta : deltaArray) {
      currentOperations += delta;
      operationCounts.push_back(currentOperations);
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (operationCounts[i] < nums[i]) {
        return false;
      }
    }
    return true;
  }
};

// Time: O(m+n)
// Space: O(n)
// Sub:
// https://leetcode.com/problems/zero-array-transformation-i/submissions/1638973755/?envType=daily-question&envId=2025-05-20
