//2429. Minimize XOR

function minimizeXor(num1: number, num2: number): number {
  // Count the number of set bits in num2
  const countSetBits = (n: number): number => {
    let count = 0;
    while (n > 0) {
      count += n & 1;
      n >>= 1;
    }
    return count;
  };

  let bitsInNum2 = countSetBits(num2);
  let x = 0;

  // Step 1: Set bits in x from the highest to lowest in num1
  for (let i = 31; i >= 0 && bitsInNum2 > 0; i--) {
    if ((num1 & (1 << i)) !== 0) {
      x |= 1 << i;
      bitsInNum2--;
    }
  }

  // Step 2: Set remaining bits in x from lowest to highest
  for (let i = 0; i < 32 && bitsInNum2 > 0; i++) {
    if ((x & (1 << i)) === 0) {
      x |= 1 << i;
      bitsInNum2--;
    }
  }

  return x;
}

//sub: https://leetcode.com/problems/minimize-xor/submissions/1509318639/?envType=daily-question&envId=2025-01-15
//sol: https://leetcode.com/problems/minimize-xor/solutions/6283769/2429-minimize-xor100-by-nalindalal2004-g7hc/
