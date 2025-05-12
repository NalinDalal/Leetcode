//2094. Finding 3-Digit Even Numbers

function findEvenNumbers(digits: number[]): number[] {
  const uniqueNumbers = new Set<number>();
  const n = digits.length;

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      for (let k = 0; k < n; k++) {
        if (i === j || j === k || i === k) continue;

        const num = digits[i] * 100 + digits[j] * 10 + digits[k];
        if (digits[i] !== 0 && num % 2 === 0) {
          uniqueNumbers.add(num);
        }
      }
    }
  }

  return Array.from(uniqueNumbers).sort((a, b) => a - b);
}

//sub: https://leetcode.com/problems/finding-3-digit-even-numbers/submissions/1632057962/?envType=daily-question&envId=2025-05-12
