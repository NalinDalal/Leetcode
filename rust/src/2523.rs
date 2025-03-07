//2523. Closest Prime Numbers in Range
struct Solution;

impl Solution {
    pub fn closest_primes(left: i32, right: i32) -> Vec<i32> {
        let mut is_prime = vec![true; (right + 1) as usize];
        Solution::sieve(&mut is_prime, right as usize);

        let mut primes = vec![];
        for i in left.max(2)..=right {
            if is_prime[i as usize] {
                primes.push(i);
            }
        }

        if primes.len() < 2 {
            return vec![-1, -1];
        }

        let mut min_diff = i32::MAX;
        let mut result = vec![-1, -1];

        for i in 1..primes.len() {
            let diff = primes[i] - primes[i - 1];
            if diff < min_diff {
                min_diff = diff;
                result = vec![primes[i - 1], primes[i]];
            }
        }

        result
    }

    fn sieve(is_prime: &mut Vec<bool>, n: usize) {
        is_prime[0] = false;
        is_prime[1] = false;
        for i in 2..=((n as f64).sqrt() as usize) {
            if is_prime[i] {
                for j in (i * i..=n).step_by(i) {
                    is_prime[j] = false;
                }
            }
        }
    }
}

fn main() {
    let result = Solution::closest_primes(10, 50);
    println!("{:?}", result);
}
//sub:https://leetcode.com/problems/closest-prime-numbers-in-range/submissions/1566054871/?envType=daily-question&envId=2025-03-07
//sol:https://leetcode.com/problems/closest-prime-numbers-in-range/solutions/6509468/2523-closest-prime-numbers-in-range-by-n-61bu/
