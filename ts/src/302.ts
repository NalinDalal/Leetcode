//1394. Find Lucky Integer in an Array
function findLucky(arr: number[]): number {
  const freq: Record<number, number> = {};

  // Count frequency of each number
  for (const num of arr) {
    freq[num] = (freq[num] || 0) + 1;
  }

  let ans = -1;

  // Check if any number is lucky
  for (const key in freq) {
    const num = Number(key);
    if (num === freq[num]) {
      ans = Math.max(ans, num);
    }
  }

  return ans;
}
//sub: https://leetcode.com/problems/find-lucky-integer-in-an-array/submissions/1687274984/
//sol: https://leetcode.com/problems/find-lucky-integer-in-an-array/solutions/6923715/1394-find-lucky-integer-in-an-array-by-n-ma35/
