/*
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]
*/
/*
Space Complexity:
- The function uses an unordered map `numMap` to store elements of `nums` along
with their indices. The space required for this map depends on the number of
unique elements in the `nums` vector.
- In the worst case, where all elements are unique, the space complexity would
be O(n) to store all elements and their indices.
- Additionally, the function uses a vector `result` to store the result, which
can hold at most two integers.
- Therefore, the space complexity of the function is O(n) for the unordered map
and O(1) for the `result` vector, which simplifies to O(n) overall.
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
      int complement = target - nums[i];
      if (numMap.find(complement) != numMap.end()) {
        result.push_back(numMap[complement]);
        result.push_back(i);
        return result;
      }
      numMap[nums[i]] = i;
    }

    return result; // Return empty vector if no solution found
  }
};

int main() {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  Solution solution;
  vector<int> indices = solution.twoSum(nums, target);

  if (indices.size() == 2) {
    cout << "Indices: " << indices[0] << " " << indices[1] << endl;
  } else {
    cout << "No solution found." << endl;
  }

  return 0;
}
