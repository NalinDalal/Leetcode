//1295. Find Numbers with Even Number of Digits

impl Solution {
    pub fn find_numbers(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        for num in nums {
            if Self::count_digits(num) % 2 == 0 {
                ans += 1;
            }
        }
        ans
    }

    pub fn count_digits(mut num: i32) -> i32 {
        let mut digits = 0;
        while num > 0 {
            num /= 10;
            digits += 1;
        }
        digits
    }
}
//sub: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/submissions/1621657727/?envType=daily-question&envId=2025-04-30
