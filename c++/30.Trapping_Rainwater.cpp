// 07.08.2024
/*
42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of
each bar is 1, compute how much water it can trap after raining.

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array
[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section)
are being trapped. Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9


Constraints:

n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5
   */

// soln->
/*
 * 🎯Problem Explaination:
We have an array height representing the heights of bars at different positions.
The goal is to calculate how much water can be trapped between these bars after
a rainfall. Each bar has a certain height given by the elements of the height
array.

The goal is to calculate how much water can be trapped between the bars based on
their heights.

Water can only be trapped at a particular index if there are higher bars on both
its left and right sides.

We can use two pointers approach to solve this problem.

2 array -> left to current pointer; current to right pointer

The left pointer is initialized to 0 and the right pointer is initialized to the
last index of the array.

left= max(left, height[left])
right= max(right, height[right])
water+= min(left, right) - height[i]

return water

    */

class Solution {
public:
  int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) {
      return 0;
    }

    vector<int> left(n, 0);
    vector<int> right(n, 0);

    // Fill left array
    left[0] = height[0];
    for (int i = 1; i < n; ++i) {
      left[i] = max(left[i - 1], height[i]);
    }

    // Fill right array
    right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      right[i] = max(right[i + 1], height[i]);
    }

    // Calculate trapped water
    int trappedWater = 0;
    for (int i = 0; i < n; ++i) {
      trappedWater += min(left[i], right[i]) - height[i];
    }

    return trappedWater;
  }
};
