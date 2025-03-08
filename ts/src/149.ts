//191. Number of 1 Bits
function hammingWeight(n: number): number {
  let count: number = 0;
  let binaryNum: string = n.toString(2);
  for (let i = 0; i < binaryNum.length; i++) {
    if (binaryNum[i] == "1") count++;
  }
  return count;
}
//sub: https://leetcode.com/problems/number-of-1-bits/submissions/1566737575/
//sol: https://leetcode.com/problems/number-of-1-bits/solutions/6512204/191-number-of-1-bits-by-nalindalal2004-5unl/
