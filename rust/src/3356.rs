//3356. Zero Array Transformation II
impl Solution {
    pub fn min_zero_array(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> i32 {
        let mut left = 0;
        let mut right = queries.len() as i32;

        // Check if it's even possible to make nums all zero
        if !Self::can_form_zero_array(&nums, &queries, right) {
            return -1;
        }

        // Binary search for the minimum number of queries
        while left <= right {
            let mid = (left + right) / 2;
            if Self::can_form_zero_array(&nums, &queries, mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        left
    }

    fn can_form_zero_array(nums: &Vec<i32>, queries: &Vec<Vec<i32>>, k: i32) -> bool {
        let n = nums.len();
        let mut diff = vec![0; n + 1]; // Difference array

        // Apply first k queries
        for i in 0..k as usize {
            let start = queries[i][0] as usize;
            let end = queries[i][1] as usize;
            let val = queries[i][2];

            diff[start] += val;
            if end + 1 < n {
                diff[end + 1] -= val;
            }
        }

        // Apply the difference array to check if nums can be zeroed
        let mut sum = 0;
        for i in 0..n {
            sum += diff[i];
            if sum < nums[i] {
                return false;
            }
        }

        true
    }
}
//sub: https://leetcode.com/problems/zero-array-transformation-ii/submissions/1572218938/?envType=daily-question&envId=2025-03-13
//sol: https://leetcode.com/problems/zero-array-transformation-ii/solutions/6531667/3356-zero-array-transformation-ii-by-nal-0njm/
