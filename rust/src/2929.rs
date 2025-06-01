//2929. Distribute Candies Among Children II
impl Solution {
    pub fn distribute_candies(n: i32, limit: i32) -> i64 {
        let mut total = 0i64;
        for a in 0..=n.min(limit) {
            let remaining = n - a;
            let min_b = (remaining - limit).max(0);
            let max_b = remaining.min(limit);
            total += (max_b - min_b + 1).max(0) as i64;
        }
        total
    }
}
//sub: https://leetcode.com/problems/distribute-candies-among-children-ii/submissions/1650474155/?envType=daily-question&envId=2025-06-01
