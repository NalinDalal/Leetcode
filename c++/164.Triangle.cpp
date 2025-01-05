/* 120. Triangle

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More
formally, if you are on index i on the current row, you may move to either index
i or index i + 1 on the next row.

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
above).

Example 2:
Input: triangle = [[-10]]
Output: -10


Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-10^4 <= triangle[i][j] <= 10^4

Follow up: Could you do this using only O(n) extra space, where n is the total
number of rows in the triangle?*/

// Intuition: for say ith position of this line, select min of ith and i+1th n
// next line, sum it return sum

// Approach:
/* 1. well do it from bottom up approach
2. store minimum sum
3. Start with the last row of the triangle
4. Start from the second last row and move upwards
5. Update DP value as the current value + min of two adjacent values below
6. The top element of DP array will have the minimum path sum*/
class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    // for say ith position of this line, select min of ith and i+1th n next
    // line, sum it return sum

    // 1. well do it from bottom up approach
    // 2. store minimum sum
    int n = triangle.size();
    vector<int> dp(triangle.back()); // Start with the last row of the triangle

    // Start from the second last row and move upwards
    for (int row = n - 2; row >= 0; --row) {
      for (int col = 0; col <= row; ++col) {
        // Update DP value as the current value + min of two adjacent values
        // below
        dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
      }
    }

    // The top element of DP array will have the minimum path sum
    return dp[0];
  }
};

// 100%
//- Time complexity:$$O(n^2)$$
//- Space complexity: $$O(1)$$
