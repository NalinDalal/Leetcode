//371. Sum of Two Integers
function getSum(a: number, b: number): number {
  let x: number = a ^ b; // xor for sum
  let y: number = (a & b) << 1; // & for carry

  while (y !== 0) {
    let car: number = (x & y) << 1;
    x = x ^ y;
    y = car;
  }

  return x;
}
//sub: https://leetcode.com/problems/sum-of-two-integers/submissions/1577497539/
//sol: https://leetcode.com/problems/sum-of-two-integers/solutions/6549813/371-sum-of-two-integers-by-nalindalal200-5brn/
