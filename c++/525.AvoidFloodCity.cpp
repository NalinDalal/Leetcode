/*1488. Avoid Flood in The City
Your country has an infinite number of lakes. Initially, all the lakes are
empty, but when it rains over the nth lake, the nth lake becomes full of water.
If it rains over a lake that is full of water, there will be a flood. Your goal
is to avoid floods in any lake.

Given an integer array rains where:

rains[i] > 0 means there will be rains over the rains[i] lake.
rains[i] == 0 means there are no rains this day and you can choose one lake this
day and dry it. Return an array ans where:

ans.length == rains.length
ans[i] == -1 if rains[i] > 0.
ans[i] is the lake you choose to dry in the ith day if rains[i] == 0.
If there are multiple valid answers return any of them. If it is impossible to
avoid flood return an empty array.

Notice that if you chose to dry a full lake, it becomes empty, but if you chose
to dry an empty lake, nothing changes.



Example 1:

Input: rains = [1,2,3,4]
Output: [-1,-1,-1,-1]
Explanation: After the first day full lakes are [1]
After the second day full lakes are [1,2]
After the third day full lakes are [1,2,3]
After the fourth day full lakes are [1,2,3,4]
There's no day to dry any lake and there is no flood in any lake.
Example 2:

Input: rains = [1,2,0,0,2,1]
Output: [-1,-1,2,1,-1,-1]
Explanation: After the first day full lakes are [1]
After the second day full lakes are [1,2]
After the third day, we dry lake 2. Full lakes are [1]
After the fourth day, we dry lake 1. There is no full lakes.
After the fifth day, full lakes are [2].
After the sixth day, full lakes are [1,2].
It is easy that this scenario is flood-free. [-1,-1,1,2,-1,-1] is another
acceptable scenario. Example 3:

Input: rains = [1,2,0,1,2]
Output: []
Explanation: After the second day, full lakes are  [1,2]. We have to dry one
lake in the third day. After that, it will rain over lakes [1,2]. It's easy to
prove that no matter which lake you choose to dry in the 3rd day, the other one
will flood.


Constraints:

1 <= rains.length <= 105
0 <= rains[i] <= 109


Hint 1
Keep An array of the last day there was rains over each city.
Hint 2
Keep an array of the days you can dry a lake when you face one.
Hint 3
When it rains over a lake, check the first possible day you can dry this lake
and assign this day to this lake.
*/

/*Intuition:
 `rains[i] > 0` means there will be rains over the rains[i] lake.
`rains[i] == 0` means there are no rains this day and you can choose one lake
this day and dry it.


 `ans[i]==-1 if rains[i] > 0`.
 `ans[i]` is the lake you choose to dry in the ith day if `rains[i] == 0`.

Approach:
- `unordered_map<int, int> full` → maps lake -> last day it was filled

- `set<int> dryDays` → stores indices of available dry days (in sorted order)

- `vector<int> ans(n, 1)` → fill initially with 1 (arbitrary valid dry-lake for
zero days)

    */

/*Approach:
 1. Iterate through each day i.

2. If it rains on lake x = rains[i]:
- If lake x is already full (full.count(x)):
- We need to find a dry day after full[x] (last rain day) to dry it.
- Use auto it = dryDays.upper_bound(full[x])
- If no such day exists → impossible → return {}
- Otherwise, assign ans[*it] = x, remove *it from dryDays.
- Mark full[x] = i
- Set ans[i] = -1

3. If rains[i] == 0 → add i to dryDays (we’ll decide later which lake to dry).
    */

class Solution {
public:
  vector<int> avoidFlood(vector<int>& rains) {
    int n = rains.size();
    vector<int> ans(n, 1);
    unordered_map<int, int> full; // lake -> last rain day
    set<int> dryDays;             // available dry days

    for (int i = 0; i < n; i++) {
      int lake = rains[i];
      if (lake > 0) {
        // it's raining on this lake
        ans[i] = -1;

        // if lake is already full, find a dry day
        if (full.count(lake)) {
          auto it = dryDays.upper_bound(full[lake]);
          if (it == dryDays.end()) {
            return {}; // cannot avoid flood
          }
          ans[*it] = lake;   // dry this lake
          dryDays.erase(it); // remove used dry day
        }

        full[lake] = i; // mark lake as full today
      } else {
        // dry day — store for later
        dryDays.insert(i);
      }
    }

    return ans;
  }
};
// sub:
// https://leetcode.com/problems/avoid-flood-in-the-city/submissions/1794012676/
// sol:
// https://leetcode.com/problems/avoid-flood-in-the-city/solutions/7255759/1488-avoid-flood-in-the-city-by-nalindal-emys/
