/*1717. Maximum Score From Removing Substrings
You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
 

Constraints:

1 <= s.length <= 105
1 <= x, y <= 104
s consists of lowercase English letters.

Hint 1
Note that it is always more optimal to take one type of substring before another
Hint 2
You can use a stack to handle erasures
*/

/*Approach
given string `s`, 2 int `x`,`y`
- Remove `"ab"` → gain `x` points
- Remove `"ba"` → gain `y` points

remove substrings in an order that gives maximum total score.

1. decide which subStr to remove 1st based on `x`,`y`
2. Use a stack to simulate removing substrings efficiently:
    - If removing `"ab"` first:
        - Traverse from left to right, use a stack.
        - If top is `'a'` and current is `'b'`, pop and gain `x` points.

    - If removing `"ba"` first:
        - Traverse from left to right.
        - If top is `'b'` and current is `'a'`, pop and gain `y` points.

3. After first pass, process the remaining string to remove the other substring.
*/

class Solution {
public:
    int removeSubstr(string& s, char first, char second, int gain) {
        string temp;
        int score = 0;

        for (char c : s) {
            if (!temp.empty() && temp.back() == first && c == second) {
                temp.pop_back(); // remove the matched pair
                score += gain;
            } else {
                temp.push_back(c);
            }
        }

        s = temp; // update s with the remaining characters
        return score;
    }

    int maximumGain(string s, int x, int y) {
        int totalScore = 0;

        // Step 1: remove the higher value pair first
        if (x > y) {
            totalScore += removeSubstr(s, 'a', 'b', x); // remove "ab"
            totalScore += removeSubstr(s, [48;51;178;1734;2848t'b', 'a', y); // then "ba"
        } else {
            totalScore += removeSubstr(s, 'b', 'a', y); // remove "ba"
            totalScore += removeSubstr(s, 'a', 'b', x); // then "ab"
        }

        return totalScore;
    }
};
//sub: https://leetcode.com/problems/maximum-score-from-removing-substrings/submissions/1708292267/?envType=daily-question&envId=2025-07-23
//sol: https://leetcode.com/problems/maximum-score-from-removing-substrings/solutions/6994176/1717-maximum-score-from-removing-substri-excy/
