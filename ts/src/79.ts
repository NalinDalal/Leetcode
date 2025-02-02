//40. Combination Sum II
function combinationSum2(candidates: number[], target: number): number[][] {
  const ans: number[][] = [];
  const temp: number[] = [];
  candidates.sort((a, b) => a - b); // Sort once at the beginning
  backtrack(candidates, target, 0, temp, ans);
  return ans;
}

function backtrack(
  candidates: number[],
  target: number,
  start: number,
  temp: number[],
  ans: number[][],
): void {
  if (target === 0) {
    ans.push([...temp]); // Make a copy of temp
    return;
  }

  for (let i = start; i < candidates.length; ++i) {
    // Skip duplicates
    if (i > start && candidates[i] === candidates[i - 1]) continue;

    if (candidates[i] > target) break; // No need to proceed if the current candidate exceeds the target

    temp.push(candidates[i]);
    backtrack(candidates, target - candidates[i], i + 1, temp, ans); // Move to the next element
    temp.pop(); // Backtrack
  }
}
//sol: https://leetcode.com/problems/combination-sum-ii/solutions/6364046/40-combination-sum-ii100-by-nalindalal20-7yny/
