//1718. Construct the Lexicographically Largest Valid Sequence
function constructDistancedSequence(n: number): number[] {
  const result: number[] = new Array(2 * n - 1).fill(0);
  const used: boolean[] = new Array(n + 1).fill(false);

  function backtrack(index: number): boolean {
    if (index === result.length) return true; // Successfully filled array

    if (result[index] !== 0) return backtrack(index + 1); // Skip filled positions

    for (let num = n; num >= 1; num--) {
      if (used[num]) continue; // Skip already used numbers

      const secondIndex = num > 1 ? index + num : index; // Compute second position
      if (secondIndex < result.length && result[secondIndex] === 0) {
        result[index] = result[secondIndex] = num;
        used[num] = true;

        if (backtrack(index + 1)) return true; // Recur for next position

        // Backtrack
        result[index] = result[secondIndex] = 0;
        used[num] = false;
      }
    }
    return false;
  }

  backtrack(0);
  return result;
}
//sub: https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/submissions/1544803127/?envType=daily-question&envId=2025-02-16
//sol: https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/solutions/6428448/1718-construct-the-lexicographically-lar-206c/
