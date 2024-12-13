/* 2593. Find Score of an Array After Marking All Elements

You are given an array nums consisting of positive integers.Starting with score
= 0, apply the following algorithm:
- Choose the smallest integer of the array that is not marked. If there is a
tie, choose the one with the smallest index.
- Add the value of the chosen integer to score.
- Mark the chosen element and its two adjacent elements if they exist.
- Repeat until all the array elements are marked.

Return the score you get after applying the above algorithm.


Example 1:
Input: nums = [2,1,3,4,5,2]
Output: 7
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent
elements: [2,1,3,4,5,2].
- 2 is the smallest unmarked element, so we mark it and its left adjacent
element: [2,1,3,4,5,2].
- 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
Our score is 1 + 2 + 4 = 7.

Example 2:
Input: nums = [2,3,5,1,3,2]
Output: 5
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent
elements: [2,3,5,1,3,2].
- 2 is the smallest unmarked element, since there are two of them, we choose the
left-most one, so we mark the one at index 0 and its right adjacent element:
[2,3,5,1,3,2].
- 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
Our score is 1 + 2 + 2 = 5.


Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
*/

#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

/* class Solution {
public:
    long long findScore(vector<int>& nums) {
        int score=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]=!chosen)
                score+=nums[i];
                nums[i-1],nums[i+1]= marked;
        }
        return score;
    }
};*/

/* class Solution {
public:
  long long findScore(vector<int>& nums) {
    long long score = 0;
    int n = nums.size();
    vector<bool> chosen(n, false); // Keeps track of which elements are "marked"

    for (int i = 0; i < n; i++) {
      if (!chosen[i]) { // If the current element is not "marked"
        score += nums[i];
        chosen[i] = true; // Mark the current element

        // Mark adjacent elements if within bounds
        if (i > 0)
          chosen[i - 1] = true;
        if (i < n - 1)
          chosen[i + 1] = true;
      }
    }

    return score;
  }
};
*/

// greedy strategy where we repeatedly choose the smallest unmarked integer from
// the array, breaking ties by selecting the one with the smallest index Once
// chosen, the integer and its adjacent elements are marked, and the integer's
// value is added to the score.
class Solution1 {
public:
  long long findScore(vector<int>& nums) {
    long long score = 0;
    int n = nums.size();
    vector<bool> marked(n, false); // Keeps track of marked elements

    // Priority queue to process elements in ascending order of value and index
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>> pq;
    for (int i = 0; i < n; i++) {
      pq.push({nums[i], i});
    }

    while (!pq.empty()) {
      auto [value, index] = pq.top();
      pq.pop();

      // If already marked, skip
      if (marked[index])
        continue;

      // Add value to score and mark neighbors
      score += value;
      marked[index] = true;
      if (index > 0)
        marked[index - 1] = true;
      if (index < n - 1)
        marked[index + 1] = true;
    }

    return score;
  }
};

/* Complexity Analysis:
Time Complexity:
Building the priority queue: 𝑂(𝑛log⁡𝑛).
Processing elements in the queue: 𝑂(𝑛log𝑛).
Overall: 𝑂(𝑛log𝑛).

Space Complexity:
Priority queue stores all elements: 𝑂(𝑛).
Marked array: 𝑂(𝑛).
Total: 𝑂(𝑛).
*/

// further optimisation:
/* 1. Sort the indices of the array:
- Create a vector of indices from 0 to n-1.
- Sort this vector based on the corresponding values in nums. If values are
tied, sort by index.
2. Iterate over the sorted indices:
- Process each element, marking it and its neighbors as needed.
- Skip already marked elements.*/
class Solution2 {
public:
  long long findScore(vector<int>& nums) {
    long long score = 0;
    int n = nums.size();
    vector<bool> marked(n, false); // Keeps track of marked elements
    vector<int> indices(n);

    // Initialize indices
    for (int i = 0; i < n; i++) {
      indices[i] = i;
    }

    // Sort indices based on values, and use index to break ties
    sort(indices.begin(), indices.end(), [&](int a, int b) {
      if (nums[a] == nums[b])
        return a < b;
      return nums[a] < nums[b];
    });

    // Process elements in sorted order
    for (int index : indices) {
      // If already marked, skip
      if (marked[index])
        continue;

      // Add value to score and mark neighbors
      score += nums[index];
      marked[index] = true;
      if (index > 0)
        marked[index - 1] = true;
      if (index < n - 1)
        marked[index + 1] = true;
    }

    return score;
  }
};

// Time Complexity:
/* Sorting the indices: 𝑂(𝑛log⁡𝑛)
Iterating over sorted indices: 𝑂(𝑛).
Overall: 𝑂(𝑛log⁡𝑛).

Space Complexity:
Marked array: 𝑂(𝑛).
Indices vector: 𝑂(𝑛).
Total: 𝑂(𝑛).*/

/* Further Optimized Approach:
1. Mark elements in-place:
Instead of using a separate marked array, directly modify the nums array. Use a
special value, such as -1, to represent marked elements. This reduces space
usage to 𝑂(1) (ignoring input array).

2. Sort the indices of the array:
Similar to the previous optimization, sort the indices based on their values and
process them in order.

3. Avoid marking unnecessary elements:
Process each index, check if it’s already marked, and update neighbors
in-place.*/

class Solution {
public:
  long long findScore(vector<int>& nums) {
    long long score = 0;
    int n = nums.size();
    vector<int> indices(n);

    // Initialize indices
    for (int i = 0; i < n; i++) {
      indices[i] = i;
    }

    // Sort indices based on values, and use index to break ties
    sort(indices.begin(), indices.end(), [&](int a, int b) {
      if (nums[a] == nums[b])
        return a < b;
      return nums[a] < nums[b];
    });

    // Process elements in sorted order
    for (int index : indices) {
      // If the current element is already marked, skip
      if (nums[index] == -1)
        continue;

      // Add value to score and mark neighbors
      score += nums[index];
      nums[index] = -1; // Mark current element
      if (index > 0)
        nums[index - 1] = -1; // Mark left neighbor
      if (index < n - 1)
        nums[index + 1] = -1; // Mark right neighbor
    }

    return score;
  }
};

/* Explanation of Changes:
In-Place Marking: Instead of a separate marked array, we modify nums directly.
This reduces the space complexity. Early Exit on Marked Elements: During
processing, if an element is already marked, it’s skipped. Efficient Marking:
The marking of neighbors (nums[index - 1] and nums[index + 1]) ensures no
redundant computations.*/

/*
Time Complexity:
Sorting the indices: 𝑂(𝑛log𝑛).
Single pass over sorted indices: 𝑂(𝑛).
Overall: 𝑂(𝑛log𝑛).

Space Complexity:
No additional memory apart from input and output:  𝑂(1) (ignoring input
array).*/
