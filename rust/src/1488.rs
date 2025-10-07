//1488. Avoid Flood in The City
use std::collections::{BTreeSet, HashMap};

impl Solution {
    pub fn avoid_flood(rains: Vec<i32>) -> Vec<i32> {
        let n = rains.len();
        let mut ans = vec![1; n];
        let mut full: HashMap<i32, usize> = HashMap::new();
        let mut dry_days: BTreeSet<usize> = BTreeSet::new(); // keeps sorted order

        for (i, &lake) in rains.iter().enumerate() {
            if lake > 0 {
                ans[i] = -1;

                if let Some(&prev_day) = full.get(&lake) {
                    // find first dry day > prev_day
                    let mut next_dry = dry_days.range((prev_day + 1)..).next().cloned();
                    if let Some(day) = next_dry {
                        ans[day] = lake;
                        dry_days.remove(&day);
                    } else {
                        return vec![]; // flood unavoidable
                    }
                }

                full.insert(lake, i);
            } else {
                dry_days.insert(i);
            }
        }

        ans
    }
}
//sub: https://leetcode.com/problems/avoid-flood-in-the-city/submissions/1794017216/
//sol: https://leetcode.com/problems/avoid-flood-in-the-city/solutions/7255759/1488-avoid-flood-in-the-city-by-nalindal-emys/
