//2106. Maximum Fruits Harvested After at Most K Steps
impl Solution {
    pub fn max_total_fruits(fruits: Vec<Vec<i32>>, start_pos: i32, k: i32) -> i32 {
        use std::cmp::{max, Ordering};

        let n = fruits.len();
        let mut positions = vec![];
        let mut prefix_sum = vec![0; n + 1];

        for (i, f) in fruits.iter().enumerate() {
            positions.push(f[0]);
            prefix_sum[i + 1] = prefix_sum[i] + f[1];
        }

        let get_sum = |l: usize, r: usize| -> i32 {
            prefix_sum[r + 1] - prefix_sum[l]
        };

        let lower_bound = |target: i32| -> usize {
            match positions.binary_search_by(|&x| {
                if x < target { Ordering::Less }
                else { Ordering::Greater }
            }) {
                Ok(i) | Err(i) => i,
            }
        };

        let upper_bound = |target: i32| -> usize {
            match positions.binary_search_by(|&x| {
                if x <= target { Ordering::Less }
                else { Ordering::Greater }
            }) {
                Ok(i) | Err(i) => i,
            }
        };

        let mut res = 0;

        for x in 0..=k {
            // Go left then right
            let left = start_pos - x;
            let right = start_pos + (k - 2 * x).max(0);
            let l = lower_bound(left);
            let r = upper_bound(right) - 1;
            if l <= r && r < n {
                res = max(res, get_sum(l, r));
            }

            // Go right then left
            let right = start_pos + x;
            let left = start_pos - (k - 2 * x).max(0);
            let l = lower_bound(left);
            let r = upper_bound(right) - 1;
            if l <= r && r < n {
                res = max(res, get_sum(l, r));
            }
        }

        res
    }
}

//sub: https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/submissions/1721589951/?envType=daily-question&envId=2025-08-03
//sol: https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/solutions/7038436/2106-maximum-fruits-harvested-after-at-m-phq9/
