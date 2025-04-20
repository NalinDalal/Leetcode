//781. Rabbits in Forest
use std::collections::HashMap;

impl Solution {
    pub fn num_rabbits(answers: Vec<i32>) -> i32 {
        let mut count = HashMap::new();

        for &a in &answers {
            *count.entry(a).or_insert(0) += 1;
        }

        let mut res = 0;
        for (x, freq) in count {
            let group_size = x + 1;
            let groups = (freq + group_size - 1) / group_size;
            res += groups * group_size;
        }

        res
    }
}

//sub: https://leetcode.com/problems/rabbits-in-forest/submissions/1612123231/?envType=daily-question&envId=2025-04-20
//sol: https://leetcode.com/problems/rabbits-in-forest/solutions/6668763/781-rabbits-in-forest-by-nalindalal2004-7ha0/
