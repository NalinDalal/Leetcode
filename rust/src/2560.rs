//2560. House Robber IV
impl Solution {
    pub fn min_capability(nums: Vec<i32>, k: i32) -> i32 {
        fn can_rob(nums: &Vec<i32>, k: i32, cap: i32) -> bool {
            let mut count = 0;
            let mut i = 0;
            while i < nums.len() {
                if nums[i] <= cap {
                    count += 1;
                    i += 1; // Skip the next adjacent house
                }
                if count >= k {
                    return true;
                }
                i += 1;
            }
            false
        }

        let mut low = *nums.iter().min().unwrap();
        let mut high = *nums.iter().max().unwrap();

        while low < high {
            let mid = low + (high - low) / 2;
            if can_rob(&nums, k, mid) {
                high = mid; // Try a lower capability
            } else {
                low = mid + 1; // Increase capability
            }
        }

        low
    }
}

//sub: https://leetcode.com/problems/house-robber-iv/submissions/1574452461/?envType=daily-question&envId=2025-03-15
//sol: https://leetcode.com/problems/house-robber-iv/solutions/6539137/2560-house-robber-iv-by-nalindalal2004-78h9/
