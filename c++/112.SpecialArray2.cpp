/* 3152. Special Array II

An array is considered special if every pair of its adjacent elements contains
two numbers with different parity. You are given an array of integer nums and a
2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to
check that subarray nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if
nums[fromi..toi] is special.

Example 1:
Input: nums = [3,4,1,2,6], queries = [[0,4]]
Output: [false]

Explanation: The subarray is [3,4,1,2,6]. 2 and 6 are both even.

Example 2:
Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]
Output: [false,true]

Explanation:
The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this query is
false. The subarray is [1,6]. There is only one pair: (1,6) and it contains
numbers with different parity. So the answer to this query is true.


Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
1 <= queries.length <= 10^5
queries[i].length == 2
0 <= queries[i][0] <= queries[i][1] <= nums.length - 1
*/

#include <iostream>
#include <vector>

using namespace std;

/* 1. initialisr the array ans with false
 * 2. for each query check if subarray is special; update if founde else
 * continue
 * 3. return ans
 */
class Solution {
public:
  vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    vector<bool> ans(queries.size());
    for (int i = 0; i < queries.size(); i++) {
      int fromi = queries[i][0];
      int toi = queries[i][1];
      bool isSpecial = false;
      for (int j = fromi; j <= toi; j++) {
        if (nums[j] % 2 != nums[j - 1] % 2) {
          isSpecial = true;
          break;
        }
      }
    }
    return ans;
  }
};
// issues:
/* 1. Initialization of isSpecial: The value of isSpecial is determined within
the loop but is not assigned to the ans vector.
2. Index Out of Bounds: In the inner loop, nums[j - 1] can access an invalid
index if j == fromi (the first element in the range).
3. Missing Assignment to ans[i]: After determining whether a subarray is
special, the result is not stored in the ans vector.*/

class Solution1 {
public:
  vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<int> breaks;

    // Precompute "breaks" array for adjacent parity changes
    for (int i = 0; i < n - 1; i++) {
      if (nums[i] % 2 == nums[i + 1] % 2) {
        breaks.push_back(i);
      }
    }

    vector<bool> ans;

    // Process each query
    for (auto& query : queries) {
      int s = query[0];
      int e = query[1];

      // Find indices using binary search
      auto left = lower_bound(breaks.begin(), breaks.end(), s);
      auto right = lower_bound(breaks.begin(), breaks.end(), e);

      // If no breaks in range, it's special
      ans.push_back(left == right);
    }

    return ans;
  }
};
// Time Complexity: O(n+qlogn)
// space complexity: O(n+q)

// more optimisation
class Solution2 {
public:
  vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<int> breaks;

    // Precompute indices of "breaks" (parity changes)
    for (int i = 0; i < n - 1; i++) {
      if (nums[i] % 2 == nums[i + 1] % 2) {
        breaks.push_back(i);
      }
    }

    vector<bool> ans(queries.size());

    // Process queries efficiently
    for (int i = 0; i < queries.size(); i++) {
      int s = queries[i][0];
      int e = queries[i][1];

      // Use binary search to check if there are "breaks" in range [s, e - 1]
      auto left = lower_bound(breaks.begin(), breaks.end(), s);
      auto right = lower_bound(breaks.begin(), breaks.end(), e);

      // If no "breaks" in range, it's special
      ans[i] = (left == right);
    }

    return ans;
  }
};

// full optimisation
class Solution3 {
public:
  vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<int> prefix(n, 0); // Initialize prefix array with size n

    // Calculate the prefix array
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1];
      if ((nums[i - 1] % 2 == 0 && nums[i] % 2 == 0) ||
          (nums[i - 1] % 2 != 0 && nums[i] % 2 != 0)) {
        prefix[i]++;
      }
    }

    vector<bool> ans; // Result vector

    // Process the queries
    for (auto& q : queries) {
      int left = q[0], right = q[1];
      int specialCount = prefix[right] - (left > 0 ? prefix[left] : 0);
      ans.push_back(specialCount == 0);
    }

    return ans; // Return the result
  }
};
// Time complexity: $$O(n+q)$$   n-size(nums),q-no of queries
// Space complexity:$$O(n)$$     n- size(prefixArray)

int main() {
  vector<int> nums1 = {3, 4, 1, 2, 6};
  vector<vector<int>> queries1 = {{0, 4}};
  Solution3 obj;
  vector<bool> ans1 = obj.isArraySpecial(nums1, queries1);
  cout << (ans1[0] ? "true" : "false") << endl; // Expected: true

  vector<int> nums2 = {4, 3, 1, 6};
  vector<vector<int>> queries2 = {{0, 2}, {2, 3}};
  vector<bool> ans2 = obj.isArraySpecial(nums2, queries2);
  cout << (ans2[0] ? "true" : "false") << " " << (ans2[1] ? "true" : "false")
       << endl; // Expected: false true

  return 0;
}
