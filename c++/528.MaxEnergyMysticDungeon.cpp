/*3147. Taking Maximum Energy From the Mystic Dungeon
In a mystic dungeon, n magicians are standing in a line. Each magician has an
attribute that gives you energy. Some magicians can give you negative energy,
which means taking energy from you.

You have been cursed in such a way that after absorbing energy from magician i,
you will be instantly transported to magician (i + k). This process will be
repeated until you reach the magician where (i + k) does not exist.

In other words, you will choose a starting point and then teleport with k jumps
until you reach the end of the magicians' sequence, absorbing all the energy
during the journey.

You are given an array energy and an integer k. Return the maximum possible
energy you can gain.

Note that when you are reach a magician, you must take energy from them, whether
it is negative or positive energy.



Example 1:
Input: energy = [5,2,-10,-5,1], k = 3
Output: 3
Explanation: We can gain a total energy of 3 by starting from magician 1
absorbing 2 + 1 = 3.

Example 2:
Input: energy = [-2,-3,-1], k = 2
Output: -1
Explanation: We can gain a total energy of -1 by starting from magician 2.



Constraints:
1 <= energy.length <= 105
-1000 <= energy[i] <= 1000
1 <= k <= energy.length - 1


Hint 1
Let dp[i] denote the energy we gain starting from index i.
Hint 2
We can notice, that  dp[i] = dp[i + k] + energy[i].
*/

/*start at i say
 absorb it's energy, move to (i+k)
 repeat till (i+k)>=energy.size()

 teleport with k jumps until you reach end

 given energy array and integer k, find max energy gain

 always take energy from them whether it's +ve,-ve, or 0
*/
/*start from last index going backwards
 dp[i] = energy[i] + (dp[i+k] if i+k < n else 0)

ans=max(dp[i])

    */
class Solution {
public:
  int maximumEnergy(vector<int>& energy, int k) {
    int n = energy.size();
    vector<int> dp(n, 0);
    int ans = INT_MIN;

    for (int i = n - 1; i >= 0; --i) {
      dp[i] = energy[i];
      if (i + k < n)
        dp[i] += dp[i + k];
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
// sub:
// https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/submissions/1797099042/?envType=daily-question&envId=2025-10-10
// sol:
// https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/solutions/7263748/3147-taking-maximum-energy-from-the-myst-2hzh/
