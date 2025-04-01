//2140. Solving Questions With Brainpower

function mostPoints(questions: number[][]): number {
  let n = questions.length;
  let dp: number[] = new Array(n + 1).fill(0);

  for (let i = n - 1; i >= 0; i--) {
    let points = questions[i][0];
    let brainpower = questions[i][1];
    let nextIndex = i + 1 + brainpower;

    let take = points + (nextIndex < n ? dp[nextIndex] : 0);
    let skipQuestion = dp[i + 1];

    dp[i] = Math.max(take, skipQuestion);
  }

  return dp[0];
}
//sub: https://leetcode.com/problems/solving-questions-with-brainpower/submissions/1592884014/?envType=daily-question&envId=2025-04-01
//sol: https://leetcode.com/problems/solving-questions-with-brainpower/solutions/6602804/2140-solving-questions-with-brainpower-b-y02n/
