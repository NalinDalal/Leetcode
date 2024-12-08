/*
42. Trapping Rain Water
Hard
Topics
Companies
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

    */

#include <iostream>

using namespace std;

class Solution {
public:
  int trap(vector<int>& height) {
    int i = 0, j = 0, ans = 0;
    while (i < height.size(); i++) {
      int lmax = 0, rmax = 0;
      for (int j = i; j < height.size(); j++) {
        lmax = max(lmax, height[i]);
        rmax = max(rmax, height[j]);
        ans += min(lmax, rmax) - height[j];
      }
    }
  }
};
