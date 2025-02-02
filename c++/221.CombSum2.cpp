/*https://leetcode.com/problems/combination-sum-ii/description/

40. Combination Sum II

Given a collection of candidate numbers (candidates) and a target number
(target), find all unique combinations in candidates where the candidate numbers
sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.



Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]


Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

// return all combinations from candidates that sum to target
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(), candidates.end()); // Sort once at the beginning
    backtrack(candidates, target, 0, temp, ans);
    return ans;
  }

private:
  void backtrack(vector<int>& candidates, int target, int start,
                 vector<int>& temp, vector<vector<int>>& ans) {
    if (target == 0) {
      ans.push_back(temp);
      return;
    }

    for (int i = start; i < candidates.size(); ++i) {
      // Skip duplicates
      if (i > start && candidates[i] == candidates[i - 1])
        continue;

      if (candidates[i] > target)
        break; // No need to proceed if the current candidate exceeds the target

      temp.push_back(candidates[i]);
      backtrack(candidates, target - candidates[i], i + 1, temp,
                ans); // Move to the next element
      temp.pop_back();
    }
  }
};
int main() {
  Solution sol;
  vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
  int target = 8;

  vector<vector<int>> result = sol.combinationSum2(candidates, target);

  cout << "Combinations that sum to " << target << ":\n";
  for (const auto& combination : result) {
    cout << "[";
    for (size_t i = 0; i < combination.size(); ++i) {
      cout << combination[i];
      if (i < combination.size() - 1)
        cout << ", ";
    }
    cout << "]\n";
  }

  return 0;
}

// sol:
// https://leetcode.com/problems/combination-sum-ii/solutions/6364046/40-combination-sum-ii100-by-nalindalal20-7yny/
