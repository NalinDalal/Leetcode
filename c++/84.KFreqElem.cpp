/* 347. Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent
elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.


Follow up: Your algorithm's time complexity must be better than O(n log n),
where n is the array's size.*/

/* Here’s how you can approach the solution correctly:

Count frequencies: Use a frequency map (unordered_map).
Use a priority queue: To efficiently find the k most frequent elements, you can
use a min-heap (priority queue). The heap will store the frequency and the
element as a pair. The size of the heap will never exceed k, ensuring that we
only keep the top k frequent elements. Return the result: After processing the
entire array, the heap will contain the top k frequent elements.*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    // Step 1: Count the frequencies of each element
    unordered_map<int, int> freq_map;
    for (int num : nums) {
      freq_map[num]++;
    }

    // Step 2: Create a min-heap (priority queue) to keep track of top k
    // elements
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        min_heap;

    // Step 3: Push the elements into the heap
    for (auto &entry : freq_map) {
      min_heap.push({entry.second, entry.first});
      if (min_heap.size() > k) {
        min_heap.pop(); // Remove the element with the lowest frequency
      }
    }

    // Step 4: Extract the elements from the heap into the result vector
    vector<int> result;
    while (!min_heap.empty()) {
      result.push_back(min_heap.top().second);
      min_heap.pop();
    }

    // Step 5: Return the result
    return result;
  }
};

// Example usage
int main() {
  Solution sol;
  vector<int> nums1 = {1, 1, 1, 2, 2, 3};
  int k1 = 2;
  vector<int> result1 = sol.topKFrequent(nums1, k1);

  for (int num : result1) {
    cout << num << " ";
  }
  return 0;
}

// O(N log k) where N is the number of elements in the input array, and k is the
// size of the heap.
//
// # Complexity
//- Time complexity:O(N log k)

//- Space complexity:O(n)
