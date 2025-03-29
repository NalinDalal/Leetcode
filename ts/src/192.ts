//2818. Apply Operations to Maximize Score

const MOD = 1_000_000_007;

// Function to compute prime scores for numbers up to maxVal
function computePrimeScores(maxVal: number): number[] {
  const primeScore = new Array(maxVal + 1).fill(0);
  for (let i = 2; i <= maxVal; i++) {
    if (primeScore[i] === 0) {
      // Prime number
      for (let j = i; j <= maxVal; j += i) {
        primeScore[j]++;
      }
    }
  }
  return primeScore;
}

// Modular exponentiation
function modExp(base: number, exp: number, mod: number): number {
  let result = 1n;
  let b = BigInt(base);
  let e = BigInt(exp);
  let m = BigInt(mod);

  while (e > 0n) {
    if (e % 2n === 1n) {
      result = (result * b) % m;
    }
    b = (b * b) % m;
    e /= 2n;
  }

  return Number(result);
}

function maximumScore(nums: number[], k: number): number {
  const n = nums.length;
  const maxNum = Math.max(...nums);
  const primeScore = computePrimeScores(maxNum);

  const left = new Array(n).fill(-1);
  const right = new Array(n).fill(n);
  const stack: number[] = [];

  // Compute left boundary
  for (let i = 0; i < n; i++) {
    while (
      stack.length > 0 &&
      primeScore[nums[stack[stack.length - 1]]] < primeScore[nums[i]]
    ) {
      stack.pop();
    }
    left[i] = stack.length === 0 ? -1 : stack[stack.length - 1];
    stack.push(i);
  }

  while (stack.length > 0) stack.pop();

  // Compute right boundary
  for (let i = n - 1; i >= 0; i--) {
    while (
      stack.length > 0 &&
      primeScore[nums[stack[stack.length - 1]]] <= primeScore[nums[i]]
    ) {
      stack.pop();
    }
    right[i] = stack.length === 0 ? n : stack[stack.length - 1];
    stack.push(i);
  }

  // Use a priority queue (max-heap) using an array and sorting
  const pq: [number, number][] = nums.map((num, index) => [num, index]);
  pq.sort((a, b) => b[0] - a[0]); // Sort in descending order based on num

  let res = 1n;
  let remainingK = BigInt(k);

  for (const [num, index] of pq) {
    if (remainingK <= 0n) break;

    const leftCnt = BigInt(index - (left[index] === -1 ? -1 : left[index]));
    const rightCnt = BigInt((right[index] === n ? n : right[index]) - index);
    const operations = leftCnt * rightCnt;

    if (operations > 0n) {
      const usableOps = operations < remainingK ? operations : remainingK;
      res = (res * BigInt(modExp(num, Number(usableOps), MOD))) % BigInt(MOD);
      remainingK -= usableOps;
    }
  }

  return Number(res);
}
//sub: https://leetcode.com/problems/apply-operations-to-maximize-score/submissions/1589876034/?envType=daily-question&envId=2025-03-29
//sol: https://leetcode.com/problems/apply-operations-to-maximize-score/solutions/6592141/2818-apply-operations-to-maximize-score-z3hoi/
