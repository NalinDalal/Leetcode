//1304. Find N Unique Integers Sum up to Zero
function sumZero(n: number): number[] {
  const ans: number[] = [];
  for (let i = 1; i <= Math.floor(n / 2); i++) {
    ans.push(i, -i);
  }
  if (n % 2 === 1) {
    ans.push(0);
  }
  return ans;
}
//sub: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/submissions/1762055913/?envType=daily-question&envId=2025-09-07
//sol: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/solutions/7163123/1304-find-n-unique-integers-sum-up-to-ze-tjsd/
