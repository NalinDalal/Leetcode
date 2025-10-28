//3354. Make Array Elements Equal to Zero
impl Solution {
    pub fn count_valid_selections(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut valid = 0;

        fn simulate(nums: &Vec<i32>, start: usize, dir: i32) -> bool {
            let mut arr = nums.clone();
            let n = arr.len();
            let mut curr = start as i32;
            let mut dir = dir;

            while curr >= 0 && curr < n as i32 {
                let idx = curr as usize;
                if arr[idx] == 0 {
                    curr += dir;
                } else {
                    arr[idx] -= 1;
                    dir *= -1; // reverse direction
                    curr += dir;
                }
            }

            arr.iter().all(|&x| x == 0)
        }

        for i in 0..n {
            if nums[i] == 0 {
                if simulate(&nums, i, 1) { // right
                    valid += 1;
                }
                if simulate(&nums, i, -1) { // left
                    valid += 1;
                }
            }
        }

        valid
    }
}

//sub: https://leetcode.com/problems/make-array-elements-equal-to-zero/submissions/1814299163/?envType=daily-question&envId=2025-10-28
//sol: https://leetcode.com/problems/make-array-elements-equal-to-zero/solutions/7308534/3354-make-array-elements-equal-to-zero-b-8sds/
