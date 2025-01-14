//2657. Find the Prefix Common Array of Two Arrays

function findThePrefixCommonArray(A: number[], B: number[]): number[] {
  const n = A.length;
  const freq: number[] = new Array(n + 1).fill(0);
  const ans: number[] = [];
  let common = 0;

  for (let i = 0; i < n; i++) {
    // Increment frequency for element in A
    if (++freq[A[i]] === 2) common++;

    // Increment frequency for element in B
    if (++freq[B[i]] === 2) common++;

    // Push the current count of common elements to the result
    ans.push(common);
  }

  return ans;
}

//sub: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/submissions/1508103104/?envType=daily-question&envId=2025-01-14
//sol: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/solutions/6278006/2657-find-the-prefix-common-array-of-two-31ll/
