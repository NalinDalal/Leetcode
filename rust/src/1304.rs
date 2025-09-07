//1304. Find N Unique Integers Sum up to Zero
impl Solution {
    pub fn sum_zero(n: i32) -> Vec<i32> {
        let mut ans = Vec::new();
        for i in 1..=(n / 2) {
            ans.push(i);
            ans.push(-i);
        }
        if n % 2 == 1 {
            ans.push(0);
        }
        ans
    }
}
//sub: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/submissions/1762056964/?envType=daily-question&envId=2025-09-07
//sol: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/solutions/7163123/1304-find-n-unique-integers-sum-up-to-ze-tjsd/
