//1128. Number of Equivalent Domino Pairs

use std::collections::HashMap;

impl Solution {
    pub fn num_equiv_domino_pairs(dominoes: Vec<Vec<i32>>) -> i32 {
        let mut count = HashMap::new();
        let mut result = 0;

        for domino in dominoes {
            let (a, b) = (domino[0], domino[1]);
            let key = if a < b { a * 10 + b } else { b * 10 + a };
            if let Some(&v) = count.get(&key) {
                result += v;
            }
            *count.entry(key).or_insert(0) += 1;
        }

        result
    }
}
//sub:https://leetcode.com/problems/number-of-equivalent-domino-pairs/submissions/1624875415/?envType=daily-question&envId=2025-05-04
