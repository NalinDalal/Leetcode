//1733. Minimum Number of People to Teach
function minimumTeachings(
  n: number,
  languages: number[][],
  friendships: number[][],
): number {
  const m = languages.length; // number of users

  // Step 1: build language sets for each user (1-indexed)
  const langSet: Set<number>[] = new Array(m + 1);
  for (let i = 0; i <= m; i++) {
    langSet[i] = new Set();
  }
  for (let i = 0; i < m; i++) {
    for (const l of languages[i]) {
      langSet[i + 1].add(l);
    }
  }

  // Step 2: find candidates (users in friendships that can't communicate)
  const candidates = new Set<number>();
  for (const [u, v] of friendships) {
    let canCommunicate = false;
    for (const l of langSet[u]) {
      if (langSet[v].has(l)) {
        canCommunicate = true;
        break;
      }
    }
    if (!canCommunicate) {
      candidates.add(u);
      candidates.add(v);
    }
  }

  if (candidates.size === 0) return 0;

  // Step 3: try teaching each language
  let ans = Number.MAX_SAFE_INTEGER;
  for (let lang = 1; lang <= n; lang++) {
    let cnt = 0;
    for (const user of candidates) {
      if (!langSet[user].has(lang)) {
        cnt++;
      }
    }
    ans = Math.min(ans, cnt);
  }

  return ans;
}

//sub: https://leetcode.com/problems/minimum-number-of-people-to-teach/submissions/1765651117/?envType=daily-question&envId=2025-09-10
//sol: https://leetcode.com/problems/minimum-number-of-people-to-teach/solutions/7174219/1733-minimum-number-of-people-to-teach-b-gudr/
