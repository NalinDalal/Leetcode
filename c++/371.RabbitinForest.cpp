/* 781. Rabbits in Forest
There is a forest with an unknown number of rabbits. We asked n rabbits "How
many rabbits have the same color as you?" and collected the answers in an
integer array answers where answers[i] is the answer of the ith rabbit.

Given the array answers, return the minimum number of rabbits that could be in
the forest.



Example 1:
Input: answers = [1,1,2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit that answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into
the array. The smallest possible number of rabbits in the forest is therefore 5:
3 that answered plus 2 that didn't.

Example 2:
Input: answers = [10,10,10]
Output: 11


Constraints:
1 <= answers.length <= 1000
0 <= answers[i] < 1000*/

/* Intuition:
So if a rabbit says x, that means there are x + 1 rabbits (including itself) of
its color.

If multiple rabbits say the same number x, you can group at most x + 1 of them
together in a color group. If more say the same thing, you need another group of
size x + 1, and so on.


*/

/* Approach:
1. Count frequency of each answer using a hash map.

2. For each unique answer `x`, do the following:

    - Each group of rabbits saying `x` can have up to `x + 1` rabbits.

    - So if `freq` is the number of rabbits saying `x`, we need:
groups=⌈𝑓𝑟𝑒𝑞/𝑥+1⌉
Total rabbits added from this answer = groups * (x + 1)
*/

class Solution {
public:
  int numRabbits(vector<int>& answers) {
    unordered_map<int, int> count;
    for (int a : answers)
      count[a]++;

    int res = 0;
    for (auto [x, freq] : count) {
      int group_size = x + 1;
      int groups =
          (freq + group_size - 1) / group_size; // ceil(freq / group_size)
      res += groups * group_size;
    }
    return res;
  }
};
// sub:
// https://leetcode.com/problems/rabbits-in-forest/submissions/1612120514/?envType=daily-question&envId=2025-04-20
// sol:
// https://leetcode.com/problems/rabbits-in-forest/solutions/6668763/781-rabbits-in-forest-by-nalindalal2004-7ha0/
