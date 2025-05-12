//2094. Finding 3-Digit Even Numbers

use std::collections::HashSet;
impl Solution {
    pub fn find_even_numbers(digits: Vec<i32>) -> Vec<i32> {
        let mut unique_numbers = HashSet::new();
        let n = digits.len();

        for i in 0..n {
            for j in 0..n {
                for k in 0..n {
                    if i == j || j == k || i == k {
                        continue;
                    }

                    let a = digits[i];
                    let b = digits[j];
                    let c = digits[k];

                    if a != 0 && c % 2 == 0 {
                        let num = a * 100 + b * 10 + c;
                        unique_numbers.insert(num);
                    }
                }
            }
        }

        let mut result: Vec<_> = unique_numbers.into_iter().collect();
        result.sort();
        result
    }
}
//sub: https://leetcode.com/problems/finding-3-digit-even-numbers/submissions/1632058575/?envType=daily-question&envId=2025-05-12
