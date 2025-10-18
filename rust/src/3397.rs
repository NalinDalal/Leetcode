//3397. Maximum Number of Distinct Elements After Operations
impl Solution {
    pub fn max_distinct_elements(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort_unstable();
        let mut next_free = std::i32::MIN;
        let mut count = 0;

        for &num in nums.iter() {
            let assigned = next_free.max(num - k);
            if assigned <= num + k {
                count += 1;
                next_free = assigned + 1;
            }
        }

        count
    }
}

//sub: https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/submissions/1804818225/?envType=daily-question&envId=2025-10-18
//sol: https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/solutions/7283439/3397-maximum-number-of-distinct-elements-a57n/
