//1493. Longest Subarray of 1's After Deleting One Element3
function longestSubarray(nums: number[]): number {
  let l = 0,
    zeroCnt = 0,
    ans = 0;

  for (let r = 0; r < nums.length; r++) {
    if (nums[r] === 0) zeroCnt++;

    while (zeroCnt > 1) {
      if (nums[l] === 0) zeroCnt--;
      l++;
    }

    ans = Math.max(ans, r - l); // delete one element
  }
  return ans;
}
//sub: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/submissions/1746047761/?envType=daily-question&envId=2025-08-24
//sol: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/solutions/7114934/1493-longest-subarray-of-1s-after-deleti-guqu/
