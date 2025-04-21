//2145. Count the Hidden Sequences

//sub: https://leetcode.com/problems/count-the-hidden-sequences/submissions/1613038060/?envType=daily-question&envId=2025-04-21
impl Solution {
    pub fn number_of_arrays(differences: Vec<i32>, lower: i32, upper: i32) -> i32 {
        let mut prefix: i64 = 0;
        let mut min_prefix: i64 = 0;
        let mut max_prefix: i64 = 0;

        for &diff in &differences {
            prefix += diff as i64;
            min_prefix = min_prefix.min(prefix);
            max_prefix = max_prefix.max(prefix);
        }

        let min_start = lower as i64 - min_prefix;
        let max_start = upper as i64 - max_prefix;

        let count = max_start - min_start + 1;
        count.max(0) as i32
    }
}
//sol: https://leetcode.com/problems/count-the-hidden-sequences/solutions/6672485/2145-count-the-hidden-sequences-by-nalin-vi26/
