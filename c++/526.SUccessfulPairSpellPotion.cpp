/*2300. Successful Pairs of Spells and Potions
You are given two positive integer arrays spells and potions, of length n and m
respectively, where spells[i] represents the strength of the ith spell and
potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is considered
successful if the product of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of
potions that will form a successful pair with the ith spell.



Example 1:
Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
Output: [4,0,3]
Explanation:
- 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
- 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
- 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
Thus, [4,0,3] is returned.

Example 2:
Input: spells = [3,1,2], potions = [8,5,8], success = 16
Output: [2,0,2]
Explanation:
- 0th spell: 3 * [8,5,8] = [24,15,24]. 2 pairs are successful.
- 1st spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful.
- 2nd spell: 2 * [8,5,8] = [16,10,16]. 2 pairs are successful.
Thus, [2,0,2] is returned.


Constraints:
n == spells.length
m == potions.length
1 <= n, m <= 105
1 <= spells[i], potions[i] <= 105
1 <= success <= 1010

Hint 1
Notice that if a spell and potion pair is successful, then the spell and all
stronger potions will be successful too. Hint 2 Thus, for each spell, we need to
find the potion with the least strength that will form a successful pair. Hint 3
We can efficiently do this by sorting the potions based on strength and using
binary search.
*/

/*traverse spell one-by-one and multiple potions with spells[i]
 now after multiplication find how many potions are >=success
 push them into pair vector
 return pair vector

 a spell and potion pair is considered successful if the product of their
 strengths is at least success

 pair vector=pairs[i] is the number of potions that will form a successful pair
 with the ith spell.
*/

/*hmm traverse spells index by index, multiple it whole with elements of potions
find how many are now >=sucess, store that count in a vector
traverse whole spells array,
return vector*/

class Solution {
public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                              long long success) {
    sort(potions.begin(), potions.end());
    int m = potions.size();
    vector<int> res;

    for (long long spell : spells) {
      // Minimum potion strength required
      long long minPotion =
          (success + spell - 1) / spell; // ceil(success / spell)

      // Find first potion >= minPotion
      auto it = lower_bound(potions.begin(), potions.end(), minPotion);

      // Count of successful pairs for this spell
      int count = potions.end() - it;
      res.push_back(count);
    }

    return res;
  }
};
// sub:
// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/submissions/1794947286/?envType=daily-question&envId=2025-10-08
// sol:
// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/solutions/7258068/2300-successful-pairs-of-spells-and-poti-uewb/
