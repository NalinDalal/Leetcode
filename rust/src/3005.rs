//3005. Count Elements With Maximum Frequency
use std::collections::HashMap;

impl Solution {
    pub fn max_frequency_elements(nums: Vec<i32>) -> i32 {
        let mut freq = HashMap::new();

        // Step 1: Count frequencies
        for num in nums {
            *freq.entry(num).or_insert(0) += 1;
        }

        // Step 2: Find maximum frequency
        let max_freq = freq.values().cloned().max().unwrap_or(0);

        // Step 3: Sum occurrences of elements with max frequency
        freq.values()
            .filter(|&&count| count == max_freq)
            .map(|&count| count)
            .sum()
    }
}

//sub: https://leetcode.com/problems/count-elements-with-maximum-frequency/submissions/1778643099/?envType=daily-question&envId=2025-09-22
//sol: https://leetcode.com/problems/count-elements-with-maximum-frequency/solutions/7212458/3005-count-elements-with-maximum-frequen-lyxo/
