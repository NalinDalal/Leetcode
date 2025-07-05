//1394. Find Lucky Integer in an Array
use std::collections::HashMap;

impl Solution {
    pub fn find_lucky(arr: Vec<i32>) -> i32 {
        let mut freq = HashMap::new();

        // Count frequencies
        for &num in &arr {
            *freq.entry(num).or_insert(0) += 1;
        }

        let mut ans = -1;

        // Find largest lucky number
        for (&num, &count) in &freq {
            if num == count {
                ans = ans.max(num);
            }
        }

        ans
    }
}
//sub: https://leetcode.com/problems/find-lucky-integer-in-an-array/submissions/1687275947/
//sol: https://leetcode.com/problems/find-lucky-integer-in-an-array/solutions/6923715/1394-find-lucky-integer-in-an-array-by-n-ma35/
