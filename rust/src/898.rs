//898. Bitwise ORs of Subarrays
use std::collections::HashSet;

impl Solution {
    pub fn subarray_bitwise_o_rs(arr: Vec<i32>) -> i32 {
        let mut result: HashSet<i32> = HashSet::new();
        let mut curr: HashSet<i32> = HashSet::new();

        for &num in arr.iter() {
            let mut next: HashSet<i32> = HashSet::new();
            next.insert(num);
            for &x in curr.iter() {
                next.insert(x | num);
            }
            curr = next;
            result.extend(&curr);
        }

        result.len() as i32
    }
}
//sub: https://leetcode.com/problems/bitwise-ors-of-subarrays/submissions/1717881288/?envType=daily-question&envId=2025-07-31
//sol: https://leetcode.com/problems/bitwise-ors-of-subarrays/solutions/7026811/898-bitwise-ors-of-subarrays-by-nalindal-aap4/
