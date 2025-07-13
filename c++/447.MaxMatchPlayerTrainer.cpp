/*2410. Maximum Matching of Players With Trainers
You are given a 0-indexed integer array players, where players[i] represents the
ability of the ith player. You are also given a 0-indexed integer array
trainers, where trainers[j] represents the training capacity of the jth trainer.

The ith player can match with the jth trainer if the player's ability is less
than or equal to the trainer's training capacity. Additionally, the ith player
can be matched with at most one trainer, and the jth trainer can be matched with
at most one player.

Return the maximum number of matchings between players and trainers that satisfy
these conditions.



Example 1:

Input: players = [4,7,9], trainers = [8,2,5,8]
Output: 2
Explanation:
One of the ways we can form two matchings is as follows:
- players[0] can be matched with trainers[0] since 4 <= 8.
- players[1] can be matched with trainers[3] since 7 <= 8.
It can be proven that 2 is the maximum number of matchings that can be formed.
Example 2:

Input: players = [1,1,1], trainers = [10]
Output: 1
Explanation:
The trainer can be matched with any of the 3 players.
Each player can only be matched with one trainer, so the maximum answer is 1.


Constraints:

1 <= players.length, trainers.length <= 105
1 <= players[i], trainers[j] <= 109


Note: This question is the same as 445: Assign Cookies.

Hint 1
Sort both the arrays.
Hint 2
Construct the matching greedily.
*/
/*Approach:
1. Sort both arrays.

2. Use two pointers: one for players, one for trainers.

3. Greedily match the smallest available player with the smallest available
trainer who can handle them.

4. Move the pointers accordingly.
    */

class Solution {
public:
  int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());

    // trainer>=player
    // 1 trainer with only 1 player
    int i = 0; // pointer for players
    int j = 0; // pointer for trainers
    int count = 0;

    while (i < players.size() && j < trainers.size()) {
      if (players[i] <= trainers[j]) {
        // match found
        count++;
        i++;
        j++;
      } else {
        // trainer too weak, try next trainer
        j++;
      }
    }

    return count;
  }
};
// sub:
// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/submissions/1696603162/?envType=daily-question&envId=2025-07-13
// sol:
// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/solutions/6954279/2410-maximum-matching-of-players-with-tr-dw65/
