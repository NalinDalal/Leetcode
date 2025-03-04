/* 846. Hand of Straights
Alice has some number of cards and she wants to rearrange the cards into groups
so that each group is of size groupSize, and consists of groupSize consecutive
cards.

Given an integer array hand where hand[i] is the value written on the ith card
and an integer groupSize, return true if she can rearrange the cards, or false
otherwise.



Example 1:
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

Example 2:
Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.



Constraints:
1 <= hand.length <= 104
0 <= hand[i] <= 109
1 <= groupSize <= hand.length

*/
class Solution {
public:
  bool isNStraightHand(vector<int>& hand, int groupSize) {
    // group of size goupSize
    // sub array has groupSize consecutive cards
    if (hand.size() % groupSize != 0) {
      return false; // If not divisible, return false immediately
    }

    sort(hand.begin(), hand.end());
    unordered_map<int, int> count; // To count occurrences of each card

    // sliding window of size groupSize
    // create a 2d vector of size groupSize,
    // each sub vector also must have size groupSize

    // if possible then return true
    // else return false
    for (int card : hand) {
      count[card]++;
    }

    for (int card : hand) {
      if (count[card] > 0) { // If this card is available to start a group
        for (int i = 0; i < groupSize; ++i) {
          if (count[card + i] == 0) {
            return false; // If any card is unavailable, return false
          }
          count[card + i]--; // Decrease the count of the card used
        }
      }
    }

    return true; // All groups of size groupSize were successfully formed
  }
};
// sub: https://leetcode.com/problems/hand-of-straights/submissions/1562237718/
// sol:
// https://leetcode.com/problems/hand-of-straights/solutions/6493627/846-hand-of-straights-by-nalindalal2004-d5f5/
