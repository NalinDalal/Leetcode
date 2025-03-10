//338. Counting Bits
function countBits(n: number): number[] {
  const ans: number[] = new Array(n + 1);
  for (let i = 0; i <= n; i++) {
    ans[i] = i.toString(2).split("0").join("").length; // Count '1's in binary
  }
  return ans;
}
//sub: https://leetcode.com/problems/counting-bits/submissions/1568813695/
//sol: https://leetcode.com/problems/counting-bits/solutions/6519440/338-counting-bits-by-nalindalal2004-2qx2/
