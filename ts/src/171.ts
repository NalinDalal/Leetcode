//7. Reverse Integer
function reverse(x: number): number {
  const isNegative = x < 0;
  let numStr = Math.abs(x).toString().split("").reverse().join("");

  let reversed = parseInt(numStr, 10);

  if (reversed > 2_147_483_647) {
    return 0; // Handle overflow
  }

  return isNegative ? -reversed : reversed;
}

//sub: https://leetcode.com/problems/reverse-integer/submissions/1578672060/
//sol: https://leetcode.com/problems/reverse-integer/solutions/6553948/7-reverse-integer-by-nalindalal2004-aaij/
