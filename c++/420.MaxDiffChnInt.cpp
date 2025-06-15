/* 1432. Max Difference You Can Get From Changing an Integer
You are given an integer num. You will apply the following steps to num two
separate times:

Pick a digit x (0 <= x <= 9).
Pick another digit y (0 <= y <= 9). Note y can be equal to x.
Replace all the occurrences of x in the decimal representation of num by y.
Let a and b be the two results from applying the operation to num independently.

Return the max difference between a and b.

Note that neither a nor b may have any leading zeros, and must not be 0.



Example 1:

Input: num = 555
Output: 888
Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
The second time pick x = 5 and y = 1 and store the new integer in b.
We have now a = 999 and b = 111 and max difference = 888
Example 2:

Input: num = 9
Output: 8
Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
The second time pick x = 9 and y = 1 and store the new integer in b.
We have now a = 9 and b = 1 and max difference = 8


Constraints:

1 <= num <= 108


Hint 1
We need to get the max and min value after changing num and the answer is max -
min. Hint 2 Use brute force, try all possible changes and keep the minimum and
maximum values
*/

// randomly pick x,y
// Replace all the occurrences of x in the decimal representation of num by y
// a,b be result
// return max diff b/w a,b
// pick 1st non-9 digit, change all occurences to 9
// if 1st digit is not 1, then change to 1
// else replace the first non-zero, non-one digit with 0.

class Solution {
public:
  int maxDiff(int num) {
    string s = to_string(num);

    // MAXIMIZE a: replace first non-9 digit with 9
    string maxS = s;
    char toReplace = 0;
    for (char c : maxS) {
      if (c != '9') {
        toReplace = c;
        break;
      }
    }
    if (toReplace != 0) {
      for (char& c : maxS) {
        if (c == toReplace)
          c = '9';
      }
    }
    int a = stoi(maxS);

    // MINIMIZE b
    string minS = s;
    toReplace = 0;

    // Case 1: First digit is not 1 → replace it with 1
    if (minS[0] != '1') {
      toReplace = minS[0];
      for (char& c : minS) {
        if (c == toReplace)
          c = '1';
      }
    }
    // Case 2: First digit is 1 → replace next eligible digit (not 0 or 1) with
    // 0
    else {
      for (int i = 1; i < minS.size(); ++i) {
        if (minS[i] != '0' && minS[i] != '1') {
          toReplace = minS[i];
          break;
        }
      }
      if (toReplace != 0) {
        for (char& c : minS) {
          if (c == toReplace)
            c = '0';
        }
      }
    }

    int b = stoi(minS);
    return a - b;
  }
};
// Time: O(log n)
// Space: O(1)
//  sub:
//  https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/submissions/1664531390/?envType=daily-question&envId=2025-06-15
//  sol:
//  https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/solutions/6844775/1432-max-difference-you-can-get-from-cha-8swi/
