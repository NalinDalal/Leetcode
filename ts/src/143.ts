//1780. Check if Number is a Sum of Powers of Three
function checkPowersOfThree(n: number): boolean {
  while (n > 0) {
    if (n % 3 === 2) {
      return false;
    }
    n = Math.floor(n / 3); // Ensure integer division
  }
  return true;
}
//sub: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/submissions/1562351550/?envType=daily-question&envId=2025-03-04
//sol: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/solutions/6494146/1780-check-if-number-is-a-sum-of-powers-eaxgf/
