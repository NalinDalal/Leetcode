//97. Interleaving String
function isInterleave(s1: string, s2: string, s3: string): boolean {
    let n1:number = s1.length, n2:number = s2.length, n3:number = s3.length;
    if (n1 + n2 != n3)
      return false;
    if (n1 < n2)
      return isInterleave(s2, s1, s3);
const dp: boolean[] = new Array(n2 + 1).fill(false);
dp[0] = true;

   // 1. Fill in the first row of dp array, considering only the characters
    // from s1.
    // 2. Fill in the first column of dp array, considering only the characters
    // from s2.

    for (let j = 1; j <= n2; ++j) {
      dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
    }
    // 3. Loop through each possible (i, j) combination, starting from (1, 1).
    // 4. Update dp[i][j] based on the transition dp[i][j] = (dp[i-1][j] and
    // s1[i-1] == s3[i+j-1]) or (dp[i][j-1] and s2[j-1] == s3[i+j-1]).
    for (let i = 1; i <= n1; ++i) {
      dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
      for (int j = 1; j <= n2; ++j) {
        dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
      }
    }

    return dp[n2];
};
//sub: https://leetcode.com/problems/interleaving-string/submissions/1556661606/
//sol: https://leetcode.com/problems/interleaving-string/solutions/6472507/97-interleaving-string-by-nalindalal2004-aqgb/
