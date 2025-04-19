//228. Summary Ranges

impl Solution {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        let mut result = Vec::new();
        let n = nums.len();
        if n == 0 {
            return result;
        }

        let mut start = nums[0];

        for i in 1..=n {
            if i == n || nums[i] != nums[i - 1] + 1 {
                if start == nums[i - 1] {
                    result.push(format!("{}", start));
                } else {
                    result.push(format!("{}->{}", start, nums[i - 1]));
                }

                if i < n {
                    start = nums[i];
                }
            }
        }

        result
    }
}
//sub: https://leetcode.com/problems/summary-ranges/submissions/1611109541/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/summary-ranges/solutions/6665617/228-summary-ranges-by-nalindalal2004-y2hj/
