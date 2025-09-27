/*812. Largest Triangle Area
Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.

 

Example 1:


Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2.00000
Explanation: The five points are shown in the above figure. The red triangle is the largest.
Example 2:

Input: points = [[1,0],[0,0],[0,1]]
Output: 0.50000
 

Constraints:

3 <= points.length <= 50
-50 <= xi, yi <= 50
All the given points are unique.
*/

/*find the area of largest triangle that can be formed
 loop over the given vector of coordinates 3 times due to choice of 3 points

 now we have 3 options:
 - shoelace formula for 3 points
 - heron's formula for 3 sides
 - area = 0.5 * a * b * sin(C) and find angle C with trigonometry


 we don't know the shoelace formula

 so apply the transformation on points, make one of them equal to 0, so other 2 will also be transformed

 From there, we could draw a square around the triangle with sides touching the coordinate axes, and calculate the area of the square minus the area of the right triangles surrounding the inner triangle.
*/
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int N=points.size();
        double ans=0;
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j)
                for (int k = j+1; k < N; ++k)
                    ans = max(ans, area(points[i], points[j], points[k]));
        return ans;
    }

    double area(vector<int>& P, vector<int>& Q, vector<int>& R){
        return 0.5 * abs(P[0]*Q[1] + Q[0]*R[1] + R[0]*P[1] -P[1]*Q[0] - Q[1]*R[0] - R[1]*P[0]);
    }
};
//sub: https://leetcode.com/problems/largest-triangle-area/submissions/1783798618/?envType=daily-question&envId=2025-09-27
//sol: https://leetcode.com/problems/largest-triangle-area/solutions/7226991/812-largest-triangle-area-by-nalindalal2-o5u8/
