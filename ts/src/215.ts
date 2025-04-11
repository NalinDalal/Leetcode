//2843. Count Symmetric Integers
function countSymmetricIntegers(low: number, high: number): number {
  let count: number = 0;

  for (let x = low; x <= high; ++x) {
    let s: string = x.toString();
    let len: number = s.length;

    if (len % 2 != 0) continue;

    let half: number = len / 2;
    let sum1: number = 0,
      sum2: number = 0;

    for (let i = 0; i < half; ++i) {
      sum1 += Number(s[i]); // ✅ fix: use Number instead of 'char' - '0'
      sum2 += Number(s[i + half]);
    }

    if (sum1 == sum2) {
      count++;
    }
  }

  return count;
}
//sub: https://leetcode.com/problems/count-symmetric-integers/submissions/1603232263/?envType=daily-question&envId=2025-04-11
//sol: https://leetcode.com/problems/count-symmetric-integers/solutions/6638140/2843-count-symmetric-integers-by-nalinda-w38p/
