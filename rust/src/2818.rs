//2818. Apply Operations to Maximize Score
use std::collections::BinaryHeap;

const MOD: i64 = 1_000_000_007;

// Function to compute prime scores
fn compute_prime_scores(max_val: usize) -> Vec<i32> {
    let mut prime_score = vec![0; max_val + 1];
    for i in 2..=max_val {
        if prime_score[i] == 0 {
            // Prime number
            for j in (i..=max_val).step_by(i) {
                prime_score[j] += 1;
            }
        }
    }
    prime_score
}

// Modular exponentiation
fn mod_exp(mut base: i64, mut exp: i64, mod_val: i64) -> i64 {
    let mut result = 1;
    base %= mod_val;
    while exp > 0 {
        if exp % 2 == 1 {
            result = (result * base) % mod_val;
        }
        base = (base * base) % mod_val;
        exp /= 2;
    }
    result
}

impl Solution {
    pub fn maximum_score(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let max_num = *nums.iter().max().unwrap() as usize;
        let prime_score = compute_prime_scores(max_num);

        let mut left = vec![-1; n];
        let mut right = vec![n as i32; n];
        let mut stack: Vec<usize> = Vec::new();

        // Compute left boundary
        for i in 0..n {
            while let Some(&top) = stack.last() {
                if prime_score[nums[top] as usize] >= prime_score[nums[i] as usize] {
                    break;
                }
                stack.pop();
            }
            left[i] = if stack.is_empty() {
                -1
            } else {
                stack.last().copied().unwrap() as i32
            };
            stack.push(i);
        }

        stack.clear();

        // Compute right boundary
        for i in (0..n).rev() {
            while let Some(&top) = stack.last() {
                if prime_score[nums[top] as usize] > prime_score[nums[i] as usize] {
                    break;
                }
                stack.pop();
            }
            right[i] = if stack.is_empty() {
                n as i32
            } else {
                stack.last().copied().unwrap() as i32
            };
            stack.push(i);
        }

        // Max-Heap based on value
        let mut pq: BinaryHeap<(i32, usize)> = BinaryHeap::new();
        for (i, &num) in nums.iter().enumerate() {
            pq.push((num, i));
        }

        let mut res: i64 = 1;
        let mut remaining_k = k as i64;

        while remaining_k > 0 {
            if let Some((num, index)) = pq.pop() {
                let left_cnt = (index as i64 - (left[index] as i64)) as i64;
                let right_cnt = ((right[index] as i64) - index as i64) as i64;
                let operations = left_cnt * right_cnt;

                if operations > 0 {
                    let usable_ops = operations.min(remaining_k);
                    res = (res * mod_exp(num as i64, usable_ops, MOD)) % MOD;
                    remaining_k -= usable_ops;
                }
            } else {
                break;
            }
        }

        res as i32
    }
}
//sub: https://leetcode.com/problems/apply-operations-to-maximize-score/submissions/1589879415/?envType=daily-question&envId=2025-03-29
//sol: https://leetcode.com/problems/apply-operations-to-maximize-score/solutions/6592141/2818-apply-operations-to-maximize-score-z3hoi/
