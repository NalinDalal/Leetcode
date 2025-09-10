/*1733. Minimum Number of People to Teach
On a social network consisting of m users and some friendships between users,
two users can communicate with each other if they know a common language.

You are given an integer n, an array languages, and an array friendships where:

There are n languages numbered 1 through n,
languages[i] is the set of languages the i​​​​​​th​​​​ user
knows, and friendships[i] = [u​​​​​​i​​​,
v​​​​​​i] denotes a friendship between the users
u​​​​​​​​​​​i​​​​​ and vi. You can choose one
language and teach it to some users so that all friends can communicate with
each other. Return the minimum number of users you need to teach.

Note that friendships are not transitive, meaning if x is a friend of y and y is
a friend of z, this doesn't guarantee that x is a friend of z.


Example 1:

Input: n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
Output: 1
Explanation: You can either teach user 1 the second language or user 2 the first
language. Example 2:

Input: n = 3, languages = [[2],[1,3],[1,2],[3]], friendships =
[[1,4],[1,2],[3,4],[2,3]] Output: 2 Explanation: Teach the third language to
users 1 and 3, yielding two users to teach.


Constraints:

2 <= n <= 500
languages.length == m
1 <= m <= 500
1 <= languages[i].length <= n
1 <= languages[i][j] <= n
1 <= u​​​​​​i < v​​​​​​i <= languages.length
1 <= friendships.length <= 500
All tuples (u​​​​​i, v​​​​​​i) are unique
languages[i] contains only unique values


Hint 1
You can just use brute force and find out for each language the number of users
you need to teach Hint 2 Note that a user can appear in multiple friendships but
you need to teach that user only once
*/

/*languages array, n size
 languages[i] -> ith user
 friendships[i]=[ui,vi]=> frinedship b/w ui, vi

 if you want to teach everyone a language, return min no of users needed to
 teach

 basically do it like this: try to establish connection b/w users from
 friendships array cover the languages from languages array and keep track of
 users from friendships array

 brute force no of users for each language, multiple frinedship person has to
 know only once

 return no f users, do like cover 1 language, check no of users needed
 then move to next, check users and add to answer

 return answer
    */
/*

### Approach

1. **Find problematic friendships**:
   Go through each friendship `(u, v)`.
   If `u` and `v` share **no common language**, mark them as "needs teaching".

2. **Collect candidate users**:
   Gather all users involved in those problematic friendships.

3. **Try each language**:
   For each language `L`:

   * Count how many of these candidate users **don’t know `L`** (they must learn
it).
   * That’s the number of people we need to teach if we choose `L`.

4. **Answer = minimum across all languages**.

*/

class Solution {
public:
  int minimumTeachings(int n, vector<vector<int>>& languages,
                       vector<vector<int>>& friendships) {
    int m = languages.size(); // number of users
    // Convert each user's languages into a set for quick lookup
    vector<unordered_set<int>> langSet(m + 1);
    for (int i = 0; i < m; i++) {
      for (int l : languages[i]) {
        langSet[i + 1].insert(l);
      }
    }

    // Step 1: find users in problematic friendships
    unordered_set<int> candidates;
    for (auto& f : friendships) {
      int u = f[0], v = f[1];
      bool canCommunicate = false;
      for (int l : langSet[u]) {
        if (langSet[v].count(l)) {
          canCommunicate = true;
          break;
        }
      }
      if (!canCommunicate) {
        candidates.insert(u);
        candidates.insert(v);
      }
    }

    if (candidates.empty())
      return 0; // all already communicate

    // Step 2: Try teaching each language
    int ans = INT_MAX;
    for (int lang = 1; lang <= n; lang++) {
      int cnt = 0;
      for (int user : candidates) {
        if (!langSet[user].count(lang)) {
          cnt++;
        }
      }
      ans = min(ans, cnt);
    }

    return ans;
  }
};

/*
### Complexity

* Building sets: **O(total number of languages across all users)**.
* Checking friendships: worst-case `O(#friendships × avg_languages_per_user)`.
* Trying each language: **O(n × |candidates|)**.

Efficient enough since `n ≤ 500` and users ≤ `10^4`.
*/

// sub:
// https://leetcode.com/problems/minimum-number-of-people-to-teach/submissions/1765645035/?envType=daily-question&envId=2025-09-10
// sol:
// https://leetcode.com/problems/minimum-number-of-people-to-teach/solutions/7174219/1733-minimum-number-of-people-to-teach-b-gudr/
