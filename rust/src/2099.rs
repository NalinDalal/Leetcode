//2099. Find Subsequence of Length K With the Largest Sum

impl Solution {
    pub fn max_subsequence(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let k = k as usize; // or use k.try_into().unwrap() for safe conversion

        let mut with_index: Vec<(i32, usize)> = nums
            .iter()
            .cloned()
            .enumerate()
            .map(|(i, val)| (val, i))
            .collect();

        // Sort by value descending
        with_index.sort_by(|a, b| b.0.cmp(&a.0));

        // Take top k and sort by original index
        let mut top_k: Vec<(i32, usize)> = with_index.into_iter().take(k).collect();
        top_k.sort_by(|a, b| a.1.cmp(&b.1));

        // Extract values
        top_k.into_iter().map(|(val, _)| val).collect()
    }
}

//sub: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/submissions/1679317679/?envType=daily-question&envId=2025-06-28
//sol: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/solutions/6895734/2099-find-subsequence-of-length-k-with-t-83bh/
