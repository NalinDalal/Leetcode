//2163. Minimum Difference in Sums After Removal of Elements
use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    pub fn minimum_difference(nums: Vec<i32>) -> i64 {
        let n = nums.len() / 3;
        let mut left_sum = vec![0_i64; nums.len()];
        let mut right_sum = vec![0_i64; nums.len()];

        let mut max_heap = BinaryHeap::new();
        let mut left_total: i64 = 0;

        for i in 0..nums.len() {
            max_heap.push(nums[i]);
            left_total += nums[i] as i64;

            if max_heap.len() > n {
                left_total -= max_heap.pop().unwrap() as i64;
            }

            if i >= n - 1 {
                left_sum[i] = left_total;
            }
        }

        let mut min_heap = BinaryHeap::new(); // use Reverse for min-heap
        let mut right_total: i64 = 0;

        for i in (0..nums.len()).rev() {
            min_heap.push(Reverse(nums[i]));
            right_total += nums[i] as i64;

            if min_heap.len() > n {
                right_total -= min_heap.pop().unwrap().0 as i64;
            }

            if i <= nums.len() - n {
                right_sum[i] = right_total;
            }
        }

        let mut result = i64::MAX;

        for i in n - 1..2 * n {
            result = result.min(left_sum[i] - right_sum[i + 1]);
        }

        result
    }
}
//sub: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/submissions/1702056958/?envType=daily-question&envId=2025-07-18
//sol: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/solutions/6972926/2163-minimum-difference-in-sums-after-removal-of-elements/?envType=daily-question&envId=2025-07-18
