//2410. Maximum Matching of Players With Trainers
function matchPlayersAndTrainers(
  players: number[],
  trainers: number[],
): number {
  players.sort((a, b) => a - b);
  trainers.sort((a, b) => a - b);

  let i = 0; // players pointer
  let j = 0; // trainers pointer
  let count = 0;

  while (i < players.length && j < trainers.length) {
    if (players[i] <= trainers[j]) {
      count++;
      i++;
      j++;
    } else {
      j++;
    }
  }

  return count;
}
//sub: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/submissions/1696607793/?envType=daily-question&envId=2025-07-13
//sol: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/solutions/6954279/2410-maximum-matching-of-players-with-tr-dw65/
