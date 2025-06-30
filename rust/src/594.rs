//594. Longest Harmonious Subsequence
use std::collections::HashMap;
impl Solution {
    pub fn find_lhs(nums: Vec<i32>) -> i32 {
        let mut freq = HashMap::new();
        let mut max_len = 0;

        for &num in &nums {
            *freq.entry(num).or_insert(0) += 1;
        }

        for (&num, &count) in &freq {
            if let Some(&next_count) = freq.get(&(num + 1)) {
                max_len = max_len.max(count + next_count);
            }
        }

        max_len
    }
}
//sub: https://leetcode.com/problems/longest-harmonious-subsequence/submissions/1681493967/
//sol: https://leetcode.com/problems/longest-harmonious-subsequence/solutions/6903011/594-longest-harmonious-subsequence/
