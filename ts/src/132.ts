//873. Length of Longest Fibonacci Subsequence
/*logic: check for last two element sum of Fibb vector if equal to ith of arr 
if yes then append ith element to vector 
else move forward do till end of arr atlast return length of vector
  
use map*/

function lenLongestFibSubseq(arr: number[]): number {
  let n: number = arr.length;
  const index = new Map<number, number>();
  const dp: Map<number, number>[] = Array.from({ length: n }, () => new Map());
  let maxLen = 0;

  for (let i = 0; i < n; i++) {
    index.set(arr[i], i);
  }

  for (let i = 1; i < n; i++) {
    for (let j = 0; j < i; j++) {
      const prev = arr[i] - arr[j];
      if (prev < arr[j] && index.has(prev)) {
        const k = index.get(prev)!;
        const length = (dp[k].get(j) || 2) + 1;
        dp[j].set(i, length);
        maxLen = Math.max(maxLen, length);
      }
    }
  }

  return maxLen >= 3 ? maxLen : 0;
}

//sub: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/submissions/1556674626/?envType=daily-question&envId=2025-02-27
//sol: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/solutions/6472536/873-length-of-longest-fibonacci-subseque-wb2o/
