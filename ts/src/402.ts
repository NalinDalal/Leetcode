//3397. Maximum Number of Distinct Elements After Operations
function maxDistinctElements(nums: number[], k: number): number {
  nums.sort((a, b) => a - b);
  let nextFree = Number.MIN_SAFE_INTEGER;
  let count = 0;

  for (let num of nums) {
    let assigned = Math.max(nextFree, num - k);
    if (assigned <= num + k) {
      count++;
      nextFree = assigned + 1;
    }
  }

  return count;
}

//sub: https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/submissions/1804818045/?envType=daily-question&envId=2025-10-18
//sol: https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/solutions/7283439/3397-maximum-number-of-distinct-elements-a57n/
