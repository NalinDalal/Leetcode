//2125. Number of Laser Beams in a Bank
function numberOfBeams(bank: string[]): number {
  let prev = 0;
  let ans = 0;

  for (const row of bank) {
    const curr = [...row].filter((ch) => ch === "1").length;
    if (curr > 0) {
      ans += prev * curr;
      prev = curr;
    }
  }

  return ans;
}
//sub: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/submissions/1813307227/?envType=daily-question&envId=2025-10-27
//sol: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/solutions/7305870/2125-number-of-laser-beams-in-a-bank-by-s7g2o/
