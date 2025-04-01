/* 2140. Solving Questions With Brainpower
You are given a 0-indexed 2D integer array questions where questions[i] =
[pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the
questions in order (i.e., starting from question 0) and make a decision whether
to solve or skip each question. Solving question i will earn you pointsi points
but you will be unable to solve each of the next brainpoweri questions. If you
skip question i, you get to make the decision on the next question.

For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
If question 0 is solved, you will earn 3 points but you will be unable to solve
questions 1 and 2. If instead, question 0 is skipped and question 1 is solved,
you will earn 4 points but you will be unable to solve questions 2 and 3. Return
the maximum points you can earn for the exam.



Example 1:

Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.
Example 2:

Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: 7
Explanation: The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.


Constraints:

1 <= questions.length <= 105
questions[i].length == 2
1 <= pointsi, brainpoweri <= 105

Hint 1
For each question, we can either solve it or skip it. How can we use Dynamic
Programming to decide the most optimal option for each problem? Hint 2 We store
for each question the maximum points we can earn if we started the exam on that
question. Hint 3 If we skip a question, then the answer for it will be the same
as the answer for the next question. Hint 4 If we solve a question, then the
answer for it will be the points of the current question plus the answer for the
next solvable question. Hint 5 The maximum of these two values will be the
answer to the current question.
*/
// for ith question-> earn pointsi
// but can't solve next brainpoweri questions
// if ith skipped, do same for i+1th
// return maxPoints;

/*1. dp[i]-> maxPoints for ith question
 2. if(skip current question){dp[i]=dp[i+1]}
 earn points[i] then dp[i] = points[i] + dp[i + 1 + brainpower[i]] to jump to
 next
dp[i]=max(dp[i+1],points[i]+dp[i+1+brainpower[i]])

base case: dp[n]=0
*/

class Solution {
public:
  long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();
    vector<long long> dp(n + 1,
                         0); // dp[i] = max points from question i onwards

    for (int i = n - 1; i >= 0; i--) {
      int points = questions[i][0];       // Points for solving question i
      int brainpower = questions[i][1];   // Number of questions to skip
      int nextIndex = i + 1 + brainpower; // Next question that can be solved

      // If nextIndex is out of bounds, take only current points
      long long take = points + (nextIndex < n ? dp[nextIndex] : 0);
      long long skipQuestion = dp[i + 1]; // Skip current question

      dp[i] = max(take, skipQuestion);
    }

    return dp[0]; // Maximum points starting from question 0
  }
};
// sub:
// https://leetcode.com/problems/solving-questions-with-brainpower/submissions/1592881144/?envType=daily-question&envId=2025-04-01
// sol:
// https://leetcode.com/problems/solving-questions-with-brainpower/solutions/6602804/2140-solving-questions-with-brainpower-b-y02n/
