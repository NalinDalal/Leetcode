/*3186. Maximum Total Damage With Spell Casting
A magician has various spells.

You are given an array power, where each element represents the damage of a
spell. Multiple spells can have the same damage value.

It is a known fact that if a magician decides to cast a spell with a damage of
power[i], they cannot cast any spell with a damage of power[i] - 2, power[i] -
1, power[i] + 1, or power[i] + 2.

Each spell can be cast only once.

Return the maximum possible total damage that a magician can cast.



Example 1:
Input: power = [1,1,3,4]
Output: 6
Explanation:The maximum possible damage of 6 is produced by casting spells 0, 1,
3 with damage 1, 1, 4.

Example 2:
Input: power = [7,1,6,6]
Output: 13
Explanation:The maximum possible damage of 13 is produced by casting spells 1,
2, 3 with damage 1, 6, 6.



Constraints:
1 <= power.length <= 105
1 <= power[i] <= 109


Hint 1
If we ever decide to use some spell with power x, then we will use all spells
with power x. Hint 2 Think of dynamic programming. Hint 3 dp[i][j] represents
the maximum damage considering up to the i-th unique spell and j represents the
number of spells skipped (up to 3 as per constraints).
*/

/* Array power[i] = spell’s damage.

If we pick damage x, we cannot pick any spell whose damage ∈ {x-2, x-1, x+1,
x+2}.

We can take all spells of the same damage at once.

We want maximum total damage.

- Combine all spells of the same damage:
```
unordered_map<long long, long long> total;
for (int x : power) total[x] += x;
```

- Work with sorted unique damages
```
vector<long long> keys;
for (auto &p : total) keys.push_back(p.first);
sort(keys.begin(), keys.end());
```

Now we’ll perform DP over keys.

- DP Relation
`dp[i]` = max total damage we can get considering up to `keys[i]`.
if we take `keys[i]`, then we can;t take any within dist<=2

so find a `j` such that `keys[j] <= keys[i] - 3`

then `dp[i] = max(dp[i-1], total[keys[i]] + dp[j])`

If no valid `j`, then just `dp[i] = max(dp[i-1], total[keys[i]])`.

find j via `binary_search`
*/

class Solution {
public:
  long long maximumTotalDamage(vector<int>& power) {
    unordered_map<long long, long long> total;
    for (int x : power)
      total[x] += x;

    vector<long long> keys;
    keys.reserve(total.size());
    for (auto& p : total)
      keys.push_back(p.first);
    sort(keys.begin(), keys.end());

    int n = keys.size();
    vector<long long> dp(n);

    dp[0] = total[keys[0]];
    for (int i = 1; i < n; ++i) {
      // Option 1: Skip this damage
      long long skip = dp[i - 1];

      // Option 2: Take this damage
      // find the last valid index j where keys[j] <= keys[i] - 3
      int j =
          upper_bound(keys.begin(), keys.end(), keys[i] - 3) - keys.begin() - 1;

      long long take = total[keys[i]];
      if (j >= 0)
        take += dp[j];

      dp[i] = max(skip, take);
    }

    return dp[n - 1];
  }
};

// sub:
// https://leetcode.com/problems/maximum-total-damage-with-spell-casting/submissions/1797914220/?envType=daily-question&envId=2025-10-11
// sol:
// https://leetcode.com/problems/maximum-total-damage-with-spell-casting/solutions/7265836/3186-maximum-total-damage-with-spell-cas-2tnc/
