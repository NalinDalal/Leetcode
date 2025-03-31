//2551. Put Marbles in Bags
function putMarbles(weights: number[], k: number): number {
  if (k === 1) return 0;
  let pairSums: number[] = [];

  // Compute the contribution of each adjacent pair
  for (let i = 0; i < weights.length - 1; i++) {
    pairSums.push(weights[i] + weights[i + 1]);
  }

  // Sort the pair sums in ascending order
  pairSums.sort((a, b) => a - b);

  // Compute minScore by summing the smallest (k-1) elements
  let minScore = pairSums.slice(0, k - 1).reduce((sum, num) => sum + num, 0);

  // Compute maxScore by summing the largest (k-1) elements
  let maxScore = pairSums.slice(-(k - 1)).reduce((sum, num) => sum + num, 0);

  // Return the difference
  return maxScore - minScore;
}
//sub:https://leetcode.com/problems/put-marbles-in-bags/submissions/1591692916/?envType=daily-question&envId=2025-03-31
//sol:https://leetcode.com/problems/put-marbles-in-bags/solutions/6598616/2551-put-marbles-in-bags-by-nalindalal20-4cm8/
