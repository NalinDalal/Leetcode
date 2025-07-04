/*3307. Find the K-th Character in String Game II
Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k. You are also given an integer array
operations, where operations[i] represents the type of the ith operation.

Now Bob will ask Alice to perform all operations in sequence:

If operations[i] == 0, append a copy of word to itself.
If operations[i] == 1, generate a new string by changing each character in word
to its next character in the English alphabet, and append it to the original
word. For example, performing the operation on "c" generates "cd" and performing
the operation on "zb" generates "zbac". Return the value of the kth character in
word after performing all the operations.

Note that the character 'z' can be changed to 'a' in the second type of
operation.



Example 1:

Input: k = 5, operations = [0,0,0]

Output: "a"

Explanation:

Initially, word == "a". Alice performs the three operations as follows:

Appends "a" to "a", word becomes "aa".
Appends "aa" to "aa", word becomes "aaaa".
Appends "aaaa" to "aaaa", word becomes "aaaaaaaa".
Example 2:

Input: k = 10, operations = [0,1,0,1]

Output: "b"

Explanation:

Initially, word == "a". Alice performs the four operations as follows:

Appends "a" to "a", word becomes "aa".
Appends "bb" to "aa", word becomes "aabb".
Appends "aabb" to "aabb", word becomes "aabbaabb".
Appends "bbccbbcc" to "aabbaabb", word becomes "aabbaabbbbccbbcc".


Constraints:

1 <= k <= 1014
1 <= operations.length <= 100
operations[i] is either 0 or 1.
The input is generated such that word has at least k characters after all
operations.


Hint 1
Try to replay the operations kth character was part of.
Hint 2
The kth character is only affected if it is present in the first half of the
string.
*/

// same as previous
/*determine which operation the current k is located in.

k=pow(2,t)+a
if a=0->t-1 opr
else -> t opr

After determining the number of operations corresponding to the current k, we
can decide whether to accumulate the answer using the operations array provided
in the problem. If operations[t] = 1, we perform the accumulation; otherwise, we
do not.


*/

class Solution {
public:
  char kthCharacter(long long k, vector<int>& operations) {
    int ans = 0;
    int t;
    while (k != 1) {
      t = __lg(k);
      if (((long long)1 << t) == k) {
        t--;
      }
      k = k - ((long long)1 << t);
      if (operations[t]) {
        ans++;
      }
    }
    return 'a' + (ans % 26);
  }
};

// Time: O(log k)
// Space: O(1)
// sub:
// https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/submissions/1686126499/
// sol:
// https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/solutions/6919299/3307-find-the-k-th-character-in-string-g-vsi1/
