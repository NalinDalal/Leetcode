//3186. Maximum Total Damage With Spell Casting
use std::collections::HashMap;

impl Solution {
    pub fn maximum_total_damage(power: Vec<i32>) -> i64 {
        // Step 1: Aggregate total damage for each unique power
        let mut total: HashMap<i64, i64> = HashMap::new();
        for &p in &power {
            *total.entry(p as i64).or_insert(0) += p as i64;
        }

        // Step 2: Sort unique powers
        let mut keys: Vec<i64> = total.keys().cloned().collect();
        keys.sort_unstable();
        let n = keys.len();
        if n == 0 {
            return 0;
        }

        // Step 3: DP initialization
        let mut dp = vec![0i64; n];
        dp[0] = total[&keys[0]];

        // Step 4: DP transition (binary search for last valid j)
        for i in 1..n {
            // Option 1: skip current key
            let skip = dp[i - 1];

            // Option 2: take current key
            let mut left = 0;
            let mut right = i as i64 - 1;
            let mut j: i64 = -1;
            while left as i64 <= right {
                let mid = ((left as i64 + right) / 2) as usize;
                if keys[mid] <= keys[i] - 3 {
                    j = mid as i64;
                    left = mid + 1;
                } else {
                    if mid == 0 { break; }
                    right = mid as i64 - 1;
                }
            }

            let mut take = total[&keys[i]];
            if j >= 0 {
                take += dp[j as usize];
            }

            dp[i] = skip.max(take);
        }

        dp[n - 1]
    }
}

//sub: https://leetcode.com/problems/maximum-total-damage-with-spell-casting/submissions/1797918506/?envType=daily-question&envId=2025-10-11
//sol: https://leetcode.com/problems/maximum-total-damage-with-spell-casting/solutions/7265836/3186-maximum-total-damage-with-spell-cas-2tnc/
