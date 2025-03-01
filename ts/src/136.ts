//72. Edit Distance
function minDistance(word1: string, word2: string): number {
  let m: number = word1.length;
  let n: number = word2.length;

  if (m > n) {
    [word1, word2] = [word2, word1];
    [m, n] = [n, m];
  }
  // Previous and current DP rows
  let previous: number[] = Array(n + 1).fill(0);
  let current: number[] = Array(n + 1).fill(0);

  // Initialize the first row (base case when word1 is empty)
  for (let j = 0; j <= n; j++) {
    previous[j] = j;
  }

  // Fill the DP table
  for (let i = 1; i <= m; i++) {
    current[0] = i; // Base case when word2 is empty

    for (let j = 1; j <= n; j++) {
      if (word1[i - 1] === word2[j - 1]) {
        current[j] = previous[j - 1]; // No operation needed
      } else {
        current[j] = Math.min(previous[j - 1], previous[j], current[j - 1]) + 1;
      }
    }

    // Swap previous and current for next iteration
    [previous, current] = [current, previous];
  }

  // The result is stored in the last element of the previous row
  return previous[n];
}

//sub: https://leetcode.com/problems/edit-distance/submissions/1558689298/
//sol: https://leetcode.com/problems/edit-distance/solutions/6479233/72-edit-distance-by-nalindalal2004-9gef/
