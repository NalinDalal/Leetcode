function uniquePaths(m: number, n: number): number {
  if (m == 1 || n == 1) return 1;

  // Initialize the array `s` with 1s
  const s: number[] = new Array(m).fill(1);

  for (let i = 1; i < n; i++) {
    for (let j = 1; j < m; j++) {
      s[j] += s[j - 1];
    }
  }
  return s[m - 1];
}
//sub: https://leetcode.com/problems/unique-paths/submissions/1551593408/
//sol: https://leetcode.com/problems/unique-paths/solutions/6454558/62-unique-paths-by-nalindalal2004-vlkp/
