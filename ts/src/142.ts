//846. Hand of Straights
function isNStraightHand(hand: number[], groupSize: number): boolean {
  // Group of size groupSize
  // Sub-array has groupSize consecutive cards
  if (hand.length % groupSize !== 0) {
    return false; // If not divisible, return false immediately
  }

  hand.sort((a, b) => a - b);
  const count: Map<number, number> = new Map(); // To count occurrences of each card

  // Sliding window of size groupSize
  // Create a 2D vector of size groupSize,
  // Each sub-vector also must have size groupSize

  // If possible then return true
  // Else return false

  for (const card of hand) {
    count.set(card, (count.get(card) || 0) + 1);
  }

  for (const card of hand) {
    if (count.get(card)! > 0) {
      // If this card is available to start a group
      for (let i = 0; i < groupSize; ++i) {
        if ((count.get(card + i) || 0) === 0) {
          return false; // If any card is unavailable, return false
        }
        count.set(card + i, count.get(card + i)! - 1); // Decrease the count of the card used
      }
    }
  }

  return true; // All groups of size groupSize were successfully formed
}

//sub: https://leetcode.com/problems/hand-of-straights/submissions/1562239972/
//sol: https://leetcode.com/problems/hand-of-straights/solutions/6493627/846-hand-of-straights-by-nalindalal2004-d5f5/
