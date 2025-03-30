//274. H-Index
function hIndex(citations: number[]): number {
  citations.sort((a, b) => b - a); // Sort in descending order

  let i = 0;
  while (i < citations.length && citations[i] >= i + 1) {
    i++;
  }

  return i;
}

// Example usage
console.log(hIndex([3, 0, 6, 1, 5])); // Output: 3
//sub: https://leetcode.com/problems/h-index/submissions/1590780142/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/h-index/solutions/6594947/274-h-index-by-nalindalal2004-n3n6/
