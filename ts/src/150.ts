//2379. Minimum Recolors to Get K Consecutive Black Blocks

function minimumRecolors(blocks: string, k: number): number {
  let n = blocks.length;
  let minOperations = Number.MAX_VALUE;

  // Iterate through the string with a sliding window of size k
  for (let i = 0; i <= n - k; i++) {
    let whiteCount = 0;

    // Count the number of 'W's in the current window
    for (let j = i; j < i + k; j++) {
      if (blocks[j] === "W") {
        whiteCount++;
      }
    }

    // Update the minimum number of operations
    minOperations = Math.min(minOperations, whiteCount);
  }

  return minOperations;
}

//sub: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/submissions/1566747449/?envType=daily-question&envId=2025-03-08
//sol: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/solutions/6512261/2379-minimum-recolors-to-get-k-consecuti-u3z6/
