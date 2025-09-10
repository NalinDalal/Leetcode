//1733. Minimum Number of People to Teach
use std::collections::HashSet;

impl Solution {
    pub fn minimum_teachings(n: i32, languages: Vec<Vec<i32>>, friendships: Vec<Vec<i32>>) -> i32 {
        let m = languages.len(); // number of users

        // Step 1: build language sets for each user (1-indexed)
        let mut lang_set: Vec<HashSet<i32>> = vec![HashSet::new(); m + 1];
        for (i, langs) in languages.iter().enumerate() {
            for &l in langs {
                lang_set[i + 1].insert(l);
            }
        }

        // Step 2: find candidates (users in friendships that can't communicate)
        let mut candidates: HashSet<usize> = HashSet::new();
        for f in friendships.iter() {
            let (u, v) = (f[0] as usize, f[1] as usize);
            let mut can_communicate = false;

            for &l in &lang_set[u] {
                if lang_set[v].contains(&l) {
                    can_communicate = true;
                    break;
                }
            }

            if !can_communicate {
                candidates.insert(u);
                candidates.insert(v);
            }
        }

        if candidates.is_empty() {
            return 0;
        }

        // Step 3: try teaching each language
        let mut ans = i32::MAX;
        for lang in 1..=n {
            let mut cnt = 0;
            for &user in &candidates {
                if !lang_set[user].contains(&lang) {
                    cnt += 1;
                }
            }
            ans = ans.min(cnt);
        }

        ans
    }
}

//sub: https://leetcode.com/problems/minimum-number-of-people-to-teach/submissions/1765652000/?envType=daily-question&envId=2025-09-10
//sol: https://leetcode.com/problems/minimum-number-of-people-to-teach/solutions/7174219/1733-minimum-number-of-people-to-teach-b-gudr/
