//190. Reverse Bits
function reverseBits(n: number): number {
  let res = 0;
  for (let i = 0; i < 32; i++) {
    res |= (n & 1) << (31 - i); // Extract LSB and place it in the reversed position
    n >>>= 1; // Unsigned right shift
  }
  return res >>> 0; // Convert to unsigned 32-bit integer
}

// Example usage:
console.log(reverseBits(43261596)); // Output: 964176192
//sub: https://leetcode.com/problems/reverse-bits/submissions/1573359630/
//sol: https://leetcode.com/problems/reverse-bits/solutions/6535387/190-reverse-bits-by-nalindalal2004-alpw/
