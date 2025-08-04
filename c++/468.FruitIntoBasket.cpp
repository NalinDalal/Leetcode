/*904. Fruit Into Baskets

You are visiting a farm that has a single row of fruit trees arranged from left
to right. The trees are represented by an integer array fruits where fruits[i]
is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some
strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit.
There is no limit on the amount of fruit each basket can hold. Starting from any
tree of your choice, you must pick exactly one fruit from every tree (including
the start tree) while moving to the right. The picked fruits must fit in one of
your baskets. Once you reach a tree with fruit that cannot fit in your baskets,
you must stop. Given the integer array fruits, return the maximum number of
fruits you can pick.



Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].


Constraints:

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length

*/

// 2 baskets
// each basket can hold any no of fruits but only 2 types of fruits
// pick only 1 fruit from every tree
// stop when you can't pick anymore
// return max no of fruits you can pick

/*approach
- problem asks for a sliding window approach that tracks the longest subarray
with at most two distinct fruit types.
- map for fruit-type and count
- If more than 2 types, shrink window from the left
*/

class Solution {
public:
  int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> basket; // fruit type → count
    int left = 0, max_fruits = 0;

    for (int right = 0; right < fruits.size(); ++right) {
      basket[fruits[right]]++;

      // If more than 2 types, shrink window from the left
      while (basket.size() > 2) {
        basket[fruits[left]]--;
        if (basket[fruits[left]] == 0) {
          basket.erase(fruits[left]);
        }
        left++;
      }

      max_fruits = max(max_fruits, right - left + 1);
    }

    return max_fruits;
  }
};
// sub:
// https://leetcode.com/problems/fruit-into-baskets/submissions/1722457009/?envType=daily-question&envId=2025-08-04
// sol:
// https://leetcode.com/problems/fruit-into-baskets/solutions/7041213/904-fruit-into-baskets-by-nalindalal2004-84vz/
