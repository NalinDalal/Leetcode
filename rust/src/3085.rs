//3085. Minimum Deletions to Make String K-Special

use std::collections::HashMap;
impl Solution {
    pub fn minimum_deletions(word: String, k: i32) -> i32 {
        let mut freq = HashMap::new();
        for c in word.chars() {
            *freq.entry(c).or_insert(0) += 1;
        }

        let mut counts: Vec<i32> = freq.values().cloned().collect();
        counts.sort();

        let max_count = *counts.last().unwrap();
        let mut res = i32::MAX;

        for base in 1..=max_count {
            let mut deletions = 0;

            for &f in &counts {
                if f < base {
                    deletions += f;
                } else if f > base + k {
                    deletions += f - (base + k);
                }
            }

            res = res.min(deletions);
        }

        res
    }
}

// Example usage:
fn main() {
    let result = minimum_deletions("aabcab".to_string(), 1);
    println!("{}", result); // Output: 1
}
//sub: https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/submissions/1671043876/?envType=daily-question&envId=2025-06-21
//sol: https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/solutions/6867131/3085-minimum-deletions-to-make-string-k-toj6a/
