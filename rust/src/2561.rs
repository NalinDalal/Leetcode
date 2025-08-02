//2561. Rearranging Fruits
use std::collections::BTreeMap;

impl Solution {
    pub fn min_cost(basket1: Vec<i32>, basket2: Vec<i32>) -> i64 {
        let mut freq1 = BTreeMap::new();
        let mut freq2 = BTreeMap::new();
        let mut total_freq = BTreeMap::new();
        let mut min_val = i32::MAX;

        for &x in &basket1 {
            *freq1.entry(x).or_insert(0) += 1;
            *total_freq.entry(x).or_insert(0) += 1;
            min_val = min_val.min(x);
        }

        for &x in &basket2 {
            *freq2.entry(x).or_insert(0) += 1;
            *total_freq.entry(x).or_insert(0) += 1;
            min_val = min_val.min(x);
        }

        for &count in total_freq.values() {
            if count % 2 != 0 {
                return -1;
            }
        }

        let mut extra_from1 = vec![];
        let mut extra_from2 = vec![];

        for (&val, &total) in &total_freq {
            let c1 = *freq1.get(&val).unwrap_or(&0);
            let diff = c1 as i32 - (total / 2) as i32;

            if diff > 0 {
                for _ in 0..diff {
                    extra_from1.push(val);
                }
            } else if diff < 0 {
                for _ in 0..-diff {
                    extra_from2.push(val);
                }
            }
        }

        extra_from1.sort();
        extra_from2.sort_by(|a, b| b.cmp(a)); // reverse sort

        let mut cost: i64 = 0;
        for i in 0..extra_from1.len() {
            let a = extra_from1[i];
            let b = extra_from2[i];
            cost += i64::from(a.min(b).min(2 * min_val));
        }

        cost
    }
}
//sub: https://leetcode.com/problems/rearranging-fruits/submissions/1720670990/?envType=daily-question&envId=2025-08-02
//sol: https://leetcode.com/problems/rearranging-fruits/solutions/7036216/2561-rearranging-fruits-by-nalindalal200-nth0/
