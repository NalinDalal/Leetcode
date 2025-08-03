/*2106. Maximum Fruits Harvested After at Most K Steps
Fruits are available at some positions on an infinite x-axis. You are given a 2D
integer array fruits where fruits[i] = [positioni, amounti] depicts amounti
fruits at the position positioni. fruits is already sorted by positioni in
ascending order, and each positioni is unique.

You are also given an integer startPos and an integer k. Initially, you are at
the position startPos. From any position, you can either walk to the left or
right. It takes one step to move one unit on the x-axis, and you can walk at
most k steps in total. For every position you reach, you harvest all the fruits
at that position, and the fruits will disappear from that position.

Return the maximum total number of fruits you can harvest.



Example 1:


Input: fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
Output: 9
Explanation:
The optimal way is to:
- Move right to position 6 and harvest 3 fruits
- Move right to position 8 and harvest 6 fruits
You moved 3 steps and harvested 3 + 6 = 9 fruits in total.
Example 2:


Input: fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], startPos = 5, k = 4
Output: 14
Explanation:
You can move at most k = 4 steps, so you cannot reach position 0 nor 10.
The optimal way is to:
- Harvest the 7 fruits at the starting position 5
- Move left to position 4 and harvest 1 fruit
- Move right to position 6 and harvest 2 fruits
- Move right to position 7 and harvest 4 fruits
You moved 1 + 3 = 4 steps and harvested 7 + 1 + 2 + 4 = 14 fruits in total.
Example 3:


Input: fruits = [[0,3],[6,4],[8,5]], startPos = 3, k = 2
Output: 0
Explanation:
You can move at most k = 2 steps and cannot reach any position with fruits.


Constraints:

1 <= fruits.length <= 105
fruits[i].length == 2
0 <= startPos, positioni <= 2 * 105
positioni-1 < positioni for any i > 0 (0-indexed)
1 <= amounti <= 104
0 <= k <= 2 * 105

Hint 1
Does an optimal path have very few patterns? For example, could a path that goes
left, turns and goes right, then turns again and goes left be any better than a
path that simply goes left, turns, and goes right? Hint 2 The optimal path turns
at most once. That is, the optimal path is one of these: to go left only; to go
right only; to go left, turn and go right; or to go right, turn and go left.
Hint 3
Moving x steps left then k-x steps right gives you a range of positions that you
can reach. Hint 4 Use prefix sums to get the sum of all fruits for each possible
range. Hint 5 Use a similar strategy for all the paths that go right, then turn
and go left.
*/
/*You can only take at most one turn. So you consider the four movement
strategies:
    - Go left only.
    - Go right only.
    - Go left and then right.
    - Go right and then left.

We’ll use prefix sums to efficiently compute the total fruits in any range.
    */

/*1. Use a sliding window over the fruits array to compute the max total fruits
you can collect within reachable distance.

2. For each window, calculate the total distance needed:
    - Left then right: go x units left and y units right ⇒ distance = 2 * x + y
    - Right then left: go x units right and y units left ⇒ distance = 2 * x + y

3. Since positions are sorted, use two pointers to maintain a valid window of
reachable fruit positions.

4. For each window, use prefix sum to compute total fruit.

*/

class Solution {
public:
  int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
    // Prefix sum and position vectors
    int n = fruits.size();
    vector<int> pos(n), sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      pos[i] = fruits[i][0];
      sum[i + 1] = sum[i] + fruits[i][1];
    }

    auto getSum = [&](int l, int r) { return sum[r + 1] - sum[l]; };

    int res = 0;

    // Helper to find first index >= value
    auto lower_bound = [&](int value) {
      return std::lower_bound(pos.begin(), pos.end(), value) - pos.begin();
    };

    // Try moving left then right
    for (int x = 0; x <= k; ++x) {
      int left = startPos - x;
      int right = startPos + max(k - 2 * x, 0);
      int l = lower_bound(left);
      int r = upper_bound(pos.begin(), pos.end(), right) - pos.begin() - 1;
      if (l <= r)
        res = max(res, getSum(l, r));
    }

    // Try moving right then left
    for (int x = 0; x <= k; ++x) {
      int right = startPos + x;
      int left = startPos - max(k - 2 * x, 0);
      int l = lower_bound(left);
      int r = upper_bound(pos.begin(), pos.end(), right) - pos.begin() - 1;
      if (l <= r)
        res = max(res, getSum(l, r));
    }

    return res;
  }
};

// sub:
// https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/submissions/1721579005/?envType=daily-question&envId=2025-08-03
// sol:
// https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/solutions/7038436/2106-maximum-fruits-harvested-after-at-m-phq9/
