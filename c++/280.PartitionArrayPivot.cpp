/*2161. Partition Array According to Given Pivot

You are given a 0-indexed integer array nums and an integer pivot. Rearrange
nums such that the following conditions are satisfied:

Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and
greater than pivot. The relative order of the elements less than pivot and the
elements greater than pivot is maintained. More formally, consider every pi, pj
where pi is the new position of the ith element and pj is the new position of
the jth element. If i < j and both elements are smaller (or larger) than pivot,
then pi < pj. Return nums after the rearrangement.



Example 1:

Input: nums = [9,12,5,10,14,3,10], pivot = 10
Output: [9,5,3,10,10,12,14]
Explanation:
The elements 9, 5, and 3 are less than the pivot so they are on the left side of
the array. The elements 12 and 14 are greater than the pivot so they are on the
right side of the array. The relative ordering of the elements less than and
greater than pivot is also maintained. [9, 5, 3] and [12, 14] are the respective
orderings. Example 2:

Input: nums = [-3,4,3,2], pivot = 2
Output: [-3,2,4,3]
Explanation:
The element -3 is less than the pivot so it is on the left side of the array.
The elements 4 and 3 are greater than the pivot so they are on the right side of
the array. The relative ordering of the elements less than and greater than
pivot is also maintained. [-3] and [4, 3] are the respective orderings.


Constraints:

1 <= nums.length <= 105
-106 <= nums[i] <= 106
pivot equals to an element of nums.*/

#include <vector>
using std::vector;
class Solution {
public:
  vector<int> pivotArray(vector<int>& nums, int pivot) {
    // okay so we need to move all elements less than pivot to left side
    // and all elements greater than euqal to pivot to right side
    // keep them as like in the relative order
    // need not be sorted
    // find pivot element
    // now traverse vector from left to right
    // check if i is ess than or greater than pivot
    // if less than pivot, move to it's just left
    // else if greater than, move to it's just right
    // else move just next to it
    // so need to make 3 array, one for less than pivot, one for greater
    // than, last for equal to pivot
    vector<int> less;
    vector<int> equal;
    vector<int> greater;

    for (int i : nums) {
      if (i < pivot)
        less.push_back(i);
      else if (i == pivot)
        equal.push_back(i);
      else if (i > pivot)
        greater.push_back(i);
    }
    // concatenate all 3 array
    vector<int> result;
    result.reserve(nums.size()); // Optimize memory allocation
    result.insert(result.end(), less.begin(), less.end());
    result.insert(result.end(), equal.begin(), equal.end());
    result.insert(result.end(), greater.begin(), greater.end());

    return result;
  }
};

// sub:
// https://leetcode.com/problems/partition-array-according-to-given-pivot/submissions/1561011836/?envType=daily-question&envId=2025-03-03
// sol:
// https://leetcode.com/problems/partition-array-according-to-given-pivot/solutions/6488526/2161-partition-array-according-to-given-em6zr/
