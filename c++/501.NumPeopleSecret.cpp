/*2327. Number of People Aware of a Secret
On day 1, one person discovers a secret.

You are given an integer delay, which means that each person will share the
secret with a new person every day, starting from delay days after discovering
the secret. You are also given an integer forget, which means that each person
will forget the secret forget days after discovering it. A person cannot share
the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end
of day n. Since the answer may be very large, return it modulo 109 + 7.



Example 1:

Input: n = 6, delay = 2, forget = 4
Output: 5
Explanation:
Day 1: Suppose the first person is named A. (1 person)
Day 2: A is the only person who knows the secret. (1 person)
Day 3: A shares the secret with a new person, B. (2 people)
Day 4: A shares the secret with a new person, C. (3 people)
Day 5: A forgets the secret, and B shares the secret with a new person, D. (3
people) Day 6: B shares the secret with E, and C shares the secret with F. (5
people) Example 2:

Input: n = 4, delay = 1, forget = 3
Output: 6
Explanation:
Day 1: The first person is named A. (1 person)
Day 2: A shares the secret with B. (2 people)
Day 3: A and B share the secret with 2 new people, C and D. (4 people)
Day 4: A forgets the secret. B, C, and D share the secret with 3 new people. (6
people)


Constraints:

2 <= n <= 1000
1 <= delay < forget <= n

Hint 1
Let dp[i][j] be the number of people who have known the secret for exactly j + 1
days, at day i.
Hint 2
If j > 0, dp[i][j] = dp[i – 1][j – 1]. Hint 3 dp[i][0] =
sum(dp[i – 1][j]) for j in [delay – 1, forget – 2].
*/

/* day 1: 1 person gets the secret
 shares secret exactly after delay days
 forgets after forget days

 given n, how many people know the scret after n days

 dp[i][j]=people on day i who have known the secret for exactly j+1 days.

 if(j>0){
 dp[i][j] = dp[i-1][j-1]
 }

 if(j==0){
 dp[i][0] = sum(dp[i-1][j])   for j in [delay-1, forget-2]
 }

 ans= sum of dp[n][j] for all 0 <= j <= forget-1


    */
class Solution {
public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    const int MOD = 1e9 + 7;
    vector<long long> dp(
        n + 1); // dp[i] = number of people who learn secret on day i
    dp[1] = 1;  // day 1, 1 person knows

    long long shareable = 0; // how many can share secret today
    long long ans = 0;

    for (int day = 2; day <= n; day++) {
      // People who just became able to share
      if (day - delay >= 1) {
        shareable = (shareable + dp[day - delay]) % MOD;
      }
      // People who forgot today
      if (day - forget >= 1) {
        shareable = (shareable - dp[day - forget] + MOD) % MOD;
      }
      // New people learn today
      dp[day] = shareable;
    }

    // Count those who still remember at day n
    for (int day = n - forget + 1; day <= n; day++) {
      if (day >= 1)
        ans = (ans + dp[day]) % MOD;
    }
    return ans;
  }
};

// sub:
// https://leetcode.com/problems/number-of-people-aware-of-a-secret/submissions/1764465809/?envType=daily-question&envId=2025-09-09
// sol:
// https://leetcode.com/problems/number-of-people-aware-of-a-secret/solutions/7170972/2327-number-of-people-aware-of-a-secret-z4gd6/
