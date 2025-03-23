/*135. Candy

There are n children standing in a line. Each child is assigned a rating value
given in the integer array ratings.

You are giving candies to these children subjected to the following
requirements:
- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.

Return the minimum number of candies you need to have to distribute the candies
to the children.



Example 1:
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2
candies respectively.

Example 2:
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1
candies respectively. The third child gets 1 candy because it satisfies the
above two conditions.


Constraints:
n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104
*/

class Solution {
public:
  int candy(vector<int>& ratings) {
    // Each child must have at least one candy.
    // Children with a higher rating get more candies than their neighbors.
    // return no of candies to distriute
    int n = ratings.size();
    if (n == 0)
      return 0;

    vector<int> candies(n, 1); // Give each child at least one candy

    // Left to Right pass
    for (int i = 1; i < n; i++) {
      if (ratings[i] > ratings[i - 1]) {
        candies[i] = candies[i - 1] + 1;
      }
    }

    // Right to Left pass
    for (int i = n - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1]) {
        candies[i] = max(candies[i], candies[i + 1] + 1);
      }
    }

    // Sum up candies
    return accumulate(candies.begin(), candies.end(), 0);
  }
};
// Time: O(n)
// Space: O(n)
// sub:
// https://leetcode.com/problems/candy/submissions/1583186803/?envType=study-plan-v2&envId=top-interview-150
// sol:
// https://leetcode.com/problems/candy/solutions/6569867/135-candy-by-nalindalal2004-rwuo/
