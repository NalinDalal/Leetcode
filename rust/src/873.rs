//873. Length of Longest Fibonacci Subsequence
use std::collections::HashMap;

impl Solution {
    pub fn len_longest_fib_subseq(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut index = HashMap::new();
        let mut dp: Vec<HashMap<usize, i32>> = vec![HashMap::new(); n];
        let mut max_len = 0;

        for (i, &val) in arr.iter().enumerate() {
            index.insert(val, i);
        }

        for i in 1..n {
            for j in 0..i {
                let prev = arr[i] - arr[j];
                if prev < arr[j] {
                    if let Some(&k) = index.get(&prev) {
                        let len = *dp[k].get(&j).unwrap_or(&2) + 1;
                        dp[j].insert(i, len);
                        max_len = max_len.max(len);
                    }
                }
            }
        }

        if max_len >= 3 {
            max_len
        } else {
            0
        }
    }
}
//sub: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/submissions/1556676150/?envType=daily-question&envId=2025-02-27
// Example Usage
fn main() {
    let arr = vec![1, 2, 3, 4, 5, 6, 7, 8];
    let result = Solution::len_longest_fib_subseq(arr);
    println!("Longest Fibonacci-like subsequence length: {}", result);
}
//sol: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/solutions/6472536/873-length-of-longest-fibonacci-subseque-wb2o/
