/*85. Maximal Rectangle
Given a rows x cols binary matrix filled with 0's and 1's, find the largest
rectangle containing only 1's and return its area.

Example 1:
Input: matrix =
[["1","0","1","0","0"]
,["1","0","1","1","1"]
,["1","1","1","1","1"]
,["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = [["0"]]
Output: 0

Example 3:
Input: matrix = [["1"]]
Output: 1


Constraints:
rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'. */

//        if (matrix[i][j] == '1')
//          ans = max(ans, i * m + j);

// Use a histogram approach per row
// Apply Largest Rectangle in Histogram logic for each row’s histogram

// Convert each row into a histogram of heights.

// For each row, use the Largest Rectangle in Histogram technique to compute the
// max area.

// Repeat for all rows and return the maximum found.

class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty())
      return 0;

    int n = matrix.size(), m = matrix[0].size();
    vector<int> height(m, 0);
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
      // Build the histogram for the current row
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == '1')
          height[j] += 1;
        else
          height[j] = 0;
      }

      // Compute the largest rectangle area in the histogram
      maxArea = max(maxArea, largestRectangleArea(height));
    }

    return maxArea;
  }

private:
  int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0); // Sentinel
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i < heights.size(); i++) {
      while (!st.empty() && heights[i] < heights[st.top()]) {
        int h = heights[st.top()];
        st.pop();
        int w = st.empty() ? i : i - st.top() - 1;
        maxArea = max(maxArea, h * w);
      }
      st.push(i);
    }

    heights.pop_back(); // Clean up
    return maxArea;
  }
};
// sub: https://leetcode.com/problems/maximal-rectangle/submissions/1597136919/
// sol:
// https://leetcode.com/problems/maximal-rectangle/solutions/6617188/85-maximal-rectangle-by-nalindalal2004-ahgo/
