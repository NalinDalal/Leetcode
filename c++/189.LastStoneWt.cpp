/* https://leetcode.com/problems/last-stone-weight/

1046. Last Stone Weight

You are given an array of integers stones where stones[i] is the weight of the
ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two
stones and smash them together. Suppose the heaviest two stones have weights x
and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new
weight y - x. At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left,
return 0.



Example 1:
Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value
of the last stone.

Example 2:
Input: stones = [1]
Output: 1


Constraints:
1 <= stones.length <= 30
1 <= stones[i] <= 1000*/

#include <bits/stdc++>
using namespace std;

// 8%
class Solution {
public:
  int lastStoneWeight(vector<int>& stones) {
    /* choose heaviest 2 stones
    // sort array, return nums.size()-1, nums.size()-2
    // let they be x,y;x<=y
    // if(x==y) delete x,y
    // else delete x, y=y-x
    // do this until only one stone left, i.e. size()==1
    // return the last stone; return stones[0];
   */
    // Create a max heap (priority queue) to store stones
    std::priority_queue<int> maxHeap(stones.begin(), stones.end());

    // While more than one stone remains
    while (maxHeap.size() > 1) {
      // Get the two largest stones
      int x = maxHeap.top();
      maxHeap.pop();
      int y = maxHeap.top();
      maxHeap.pop();

      // If they don't destroy each other, push the result back
      if (x != y) {
        maxHeap.push(x - y);
      }
    }

    // If there's no stone left, return 0
    return maxHeap.empty() ? 0 : maxHeap.top();
  }
};

// 100%
// optimisation: no need for the priority queue to store all the stones
// initially;Reducing the number of operations
class Solution1 {
public:
  int lastStoneWeight(std::vector<int>& stones) {
    // Create a max heap (priority queue) to store stones
    std::priority_queue<int> maxHeap;

    // Insert all stones into the max heap
    for (int stone : stones) {
      maxHeap.push(stone);
    }

    // While more than one stone remains
    while (maxHeap.size() > 1) {
      // Get the two largest stones
      int x = maxHeap.top();
      maxHeap.pop();
      int y = maxHeap.top();
      maxHeap.pop();

      // If they don't destroy each other, push the result back
      if (x != y) {
        maxHeap.push(x - y);
      }
    }

    // If there's no stone left, return 0
    return maxHeap.empty() ? 0 : maxHeap.top();
  }
};

// Time: O(n)
// Space: O(1)
// Sub(100%):
// https://leetcode.com/problems/last-stone-weight/submissions/1511234308/
// Solution:
// https://leetcode.com/problems/last-stone-weight/solutions/6292985/1046-last-stone-weight100-by-nalindalal2-q8mf/
