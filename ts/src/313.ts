//3201. Find the Maximum Length of Valid Subsequence I
function maximumLength(nums: number[]): number {
  let res = 0;
  const patterns = [
    [0, 0],
    [0, 1],
    [1, 0],
    [1, 1],
  ] as const;
  for (const pattern of patterns) {
    let cnt = 0;
    for (const num of nums) {
      if (num % 2 === pattern[cnt % 2]) {
        cnt++;
      }
    }
    res = Math.max(res, cnt);
  }
  return res;
}
//sub: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/submissions/1700026104/?envType=daily-question&envId=2025-07-16
//sol: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/solutions/6966556/3201-find-the-maximum-length-of-valid-su-tu7u/
