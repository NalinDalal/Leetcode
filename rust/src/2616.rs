//2616. Minimize the Maximum Difference of Pairs
impl Solution {
    fn count_valid_pairs(nums: &Vec<i32>, threshold: i32) -> i32 {
        let mut index = 0;
        let mut count = 0;
        while index < nums.len() - 1 {
            if nums[index + 1] - nums[index] <= threshold {
                count += 1;
                index += 1;
            }
            index += 1;
        }
        count
    }

    fn minimize_max(mut nums: Vec<i32>, p: i32) -> i32 {
        nums.sort();
        let (mut left, mut right) = (0, nums[nums.len() - 1] - nums[0]);

        while left < right {
            let mid = left + (right - left) / 2;
            if Self::count_valid_pairs(&nums, mid) >= p {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        left
    }
}
// Example usage:
fn main() {
    let result = minimize_max(vec![1, 3, 6, 19, 20], 2);
    println!("{}", result);
}
//sub: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/submissions/1662895819/?envType=daily-question&envId=2025-06-13
//sol: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/solutions/6839534/2616-minimize-the-maximum-difference-of-zibpr/
