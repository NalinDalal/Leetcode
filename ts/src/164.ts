//2560. House Robber IV
function minCapability(nums: number[], k: number): number {
  function canRob(cap: number): boolean {
    let count = 0;
    for (let i = 0; i < nums.length; i++) {
      if (nums[i] <= cap) {
        count++;
        i++; // Skip the adjacent house
      }
      if (count >= k) return true;
    }
    return false;
  }

  let low = Math.min(...nums);
  let high = Math.max(...nums);

  while (low < high) {
    let mid = Math.floor((low + high) / 2);
    if (canRob(mid)) {
      high = mid; // Try a lower capability
    } else {
      low = mid + 1; // Increase capability
    }
  }

  return low;
}
//sub: https://leetcode.com/problems/house-robber-iv/submissions/1574451945/?envType=daily-question&envId=2025-03-15
//sol: https://leetcode.com/problems/house-robber-iv/solutions/6539137/2560-house-robber-iv-by-nalindalal2004-78h9/
