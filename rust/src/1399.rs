//1399. Count Largest Group

use std::collections::HashMap;
impl Solution {
    pub fn count_largest_group(n: i32) -> i32 {
        let mut hash_map: HashMap<i32, i32> = HashMap::new();
        let mut max_value = 0;

        for i in 1..=n {
            let mut key = 0;
            let mut i0 = i;

            while i0 > 0 {
                key += i0 % 10;
                i0 /= 10;
            }

            let count = hash_map.entry(key).and_modify(|e| *e += 1).or_insert(1);
            max_value = max_value.max(*count);
        }

        let mut count = 0;
        for &value in hash_map.values() {
            if value == max_value {
                count += 1;
            }
        }

        count
    }
}
//sub: https://leetcode.com/problems/count-largest-group/submissions/1615164665/?envType=daily-question&envId=2025-04-23
