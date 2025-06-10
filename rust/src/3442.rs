//3442. Maximum Difference Between Even and Odd Frequency I
use std::collections::HashMap;
impl Solution {
    pub fn max_difference(s: String) -> i32 {
        let mut freq: HashMap<char, i32> = HashMap::new();

        // Count frequency of each character
        for c in s.chars() {
            *freq.entry(c).or_insert(0) += 1;
        }

        let mut odd_freqs = Vec::new();
        let mut even_freqs = Vec::new();

        // Separate odd and even frequencies
        for &count in freq.values() {
            if count % 2 == 0 {
                even_freqs.push(count);
            } else {
                odd_freqs.push(count);
            }
        }

        if odd_freqs.is_empty() || even_freqs.is_empty() {
            return -1; // No valid odd-even pair
        }

        let mut max_diff = i32::MIN;
        for &odd in &odd_freqs {
            for &even in &even_freqs {
                max_diff = max_diff.max(odd - even);
            }
        }

        max_diff
    }
}
//sub:https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/submissions/1659268764/?envType=daily-question&envId=2025-06-10
//sol:https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/solutions/6827928/3442-maximum-difference-between-even-and-m7j6/
