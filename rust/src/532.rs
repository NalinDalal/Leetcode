//532.AdjacentIncSubArrDet1.cpp
impl Solution {
    pub fn max_increasing_subarrays(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut cnt = 1;
        let mut precnt = 0;
        let mut ans = 0;
        
        for i in 1..n {
            if nums[i] > nums[i - 1] {
                cnt += 1;
            } else {
                precnt = cnt;
                cnt = 1;
            }
            ans = ans.max(precnt.min(cnt));
            ans = ans.max(cnt / 2);
        }
        
        ans
    }
}
//sub: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/submissions/1802532186/?envType=daily-question&envId=2025-10-15
//sol: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/solutions/7277592/3350-adjacent-increasing-subarrays-detec-7y6u/
