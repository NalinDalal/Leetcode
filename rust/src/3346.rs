//3346. Maximum Frequency of an Element After Performing Operations I
use std::collections::HashMap;

impl Solution {
    pub fn max_frequency(nums: Vec<i32>, k: i32, num_operations: i32) -> i32 {
        let mut nums = nums;
        nums.sort();
        
        let mut ans = 0;
        let mut num_count = HashMap::new();
        
        let mut last_num_index = 0;
        for i in 0..nums.len() {
            if nums[i] != nums[last_num_index] {
                num_count.insert(nums[last_num_index], (i - last_num_index) as i32);
                ans = ans.max((i - last_num_index) as i32);
                last_num_index = i;
            }
        }
        
        num_count.insert(nums[last_num_index], (nums.len() - last_num_index) as i32);
        ans = ans.max((nums.len() - last_num_index) as i32);
        
        let left_bound = |value: i32| -> usize {
            let mut left = 0;
            let mut right = nums.len() - 1;
            while left < right {
                let mid = (left + right) / 2;
                if nums[mid] < value {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            left
        };
        
        let right_bound = |value: i32| -> usize {
            let mut left = 0;
            let mut right = nums.len() - 1;
            while left < right {
                let mid = (left + right + 1) / 2;
                if nums[mid] > value {
                    right = mid - 1;
                } else {
                    left = mid;
                }
            }
            left
        };
        
        for i in nums[0]..=nums[nums.len() - 1] {
            let l = left_bound(i - k);
            let r = right_bound(i + k);
            
            let temp_ans = if let Some(&count) = num_count.get(&i) {
                (r - l + 1).min(count as usize + num_operations as usize)
            } else {
                (r - l + 1).min(num_operations as usize)
            };
            ans = ans.max(temp_ans as i32);
        }
        
        ans
    }
}
//sub: https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/submissions/1807426872/?envType=daily-question&envId=2025-10-21
//sol: https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/solutions/7290165/3346-maximum-frequency-of-an-element-aft-gtjp/
