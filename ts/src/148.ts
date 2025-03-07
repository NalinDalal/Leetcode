//2523. Closest Prime Numbers in Range
function closestPrimes(left: number, right: number): number[] {
  let isPrime = new Array(right + 1).fill(true);
  sieve(isPrime, right);

  let primes: number[] = [];
  for (let i = Math.max(2, left); i <= right; i++) {
    if (isPrime[i]) primes.push(i);
  }

  if (primes.length < 2) return [-1, -1];

  let minDiff = Infinity;
  let result: number[] = [-1, -1];

  for (let i = 1; i < primes.length; i++) {
    let diff = primes[i] - primes[i - 1];
    if (diff < minDiff) {
      minDiff = diff;
      result = [primes[i - 1], primes[i]];
    }
  }

  return result;
}

function sieve(isPrime: boolean[], n: number): void {
  isPrime[0] = isPrime[1] = false;
  for (let i = 2; i * i <= n; i++) {
    if (isPrime[i]) {
      for (let j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }
}

// Example usage
console.log(closestPrimes(10, 50));

//sub:https://leetcode.com/problems/closest-prime-numbers-in-range/submissions/1566053900/?envType=daily-question&envId=2025-03-07
//sol:https://leetcode.com/problems/closest-prime-numbers-in-range/solutions/6509468/2523-closest-prime-numbers-in-range-by-n-61bu/
