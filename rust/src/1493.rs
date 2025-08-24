//1493. Longest Subarray of 1's After Deleting One Element
impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let (mut l, mut zero_cnt, mut ans) = (0usize, 0, 0);

        for r in 0..nums.len() {
            if nums[r] == 0 {
                zero_cnt += 1;
            }

            while zero_cnt > 1 {
                if nums[l] == 0 {
                    zero_cnt -= 1;
                }
                l += 1;
            }

            ans = ans.max(r - l);
        }
        ans as i32
    }
}
//sub: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/submissions/1746048917/?envType=daily-question&envId=2025-08-24
//sol: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/solutions/7114934/1493-longest-subarray-of-1s-after-deleti-guqu/
