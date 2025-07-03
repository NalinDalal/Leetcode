/*3304. Find the K-th Character in String Game I
Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k.

Now Bob will ask Alice to perform the following operation forever:

Generate a new string by changing each character in word to its next character
in the English alphabet, and append it to the original word. For example,
performing the operation on "c" generates "cd" and performing the operation on
"zb" generates "zbac".

Return the value of the kth character in word, after enough operations have been
done for word to have at least k characters.

Note that the character 'z' can be changed to 'a' in the operation.


Example 1:
Input: k = 5
Output: "b"
Explanation:

Initially, word = "a". We need to do the operation three times:

Generated string is "b", word becomes "ab".
Generated string is "bc", word becomes "abbc".
Generated string is "bccd", word becomes "abbcbccd".


Example 2:
Input: k = 10
Output: "c"



Constraints:
1 <= k <= 500

Hint 1
The constraints are small. Construct the string by simulating the operations.
*/

// Solution
/* after each operation current string changed to next char
 * modified_str+=original_str[i];
 * after each opr length=length*2, so do '+1 modulo 26'
 * need to find kth char, so what chat is responsible at previous version
 * let k=pow(2,t)+a:
 * If a=0, then k lies in the (t−1)-th operation, and we set k ′ =k−pow(2,t−1).
If a!==0, then k lies in the t-th operation, and we set k`=k-pow(2,t)=a.

iterate till k` reduces to 1
count how many such steps are taken
*/

class Solution {
public:
  char kthCharacter(int k) {
    int ans = 0;
    int t;
    while (k != 1) {
      t = __lg(k);
      if ((1 << t) == k) {
        t--;
      }
      k = k - (1 << t);
      ans++;
    }
    return 'a' + ans;
  }
};

// Time: O(logk)
// Space: O(1)
// Sub:
// https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/submissions/1684864294/?envType=daily-question&envId=2025-07-03
// sol:
// https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/solutions/6914654/3304-find-the-k-th-character-in-string-g-9m1m/
