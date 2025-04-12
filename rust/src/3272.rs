//3272. Find the Count of Good Integers
use std::collections::HashSet;

impl Solution {
    pub fn count_good_integers(n: i32, k: i32) -> i64 {
        let factorial = Solution::fact();
        let mut ans = 0;
        let mut mh = HashSet::new();
        let m = (n + 1) / 2;
        let till = 10_i64.pow(m as u32);
        for i in 0..till {
            let x = Solution::create(i, n);
            if x % k as i64 == 0 && Solution::palindrome(x, &mut mh) {
                ans += Solution::permutation(x, &factorial);
            }
        }
        ans
    }
    fn fact() -> Vec<i64> {
        let mut factorial = vec![1; 11];
        let mut pro = 1;
        for i in 1..11 {
            pro *= i as i64;
            factorial[i] = pro;
        }
        factorial
    }
    fn create(num: i64, n: i32) -> i64 {
        let mut res = num;
        let mut pro = 10_i64.pow((n - 1) as u32);
        let mut n = n / 2;
        let mut num = num;

        while num > 0 && n > 0 {
            res += (num % 10) * pro;
            pro /= 10;
            num /= 10;
            n -= 1;
        }
        res
    }
    fn permutation(n: i64, fact: &[i64]) -> i64 {
        let mut arr = [0; 11];
        let sarr = n.to_string().chars().collect::<Vec<_>>();

        for c in sarr.iter() {
            arr[c.to_digit(10).unwrap() as usize] += 1;
        }

        let total_freq = sarr.len() as i64;
        let mut total_freq = fact[total_freq as usize];
        let mut res = 1;

        for &count in arr.iter() {
            res *= fact[count as usize];
        }

        total_freq /= res;

        if arr[0] == 0 {
            return total_freq;
        }

        res = 1;
        arr[0] -= 1;
        let total = fact[sarr.len() - 1];

        for &count in arr.iter() {
            res *= fact[count as usize];
        }

        total_freq - (total / res)
    }

    fn palindrome(num: i64, mh: &mut HashSet<String>) -> bool {
        let sarr: Vec<char> = num.to_string().chars().collect();
        let (mut i, mut j) = (0, sarr.len() - 1);

        while i < j {
            if sarr[i] != sarr[j] {
                return false;
            }
            i += 1;
            j -= 1;
        }

        let mut sorted_sarr = sarr.clone();
        sorted_sarr.sort();
        let sorted_str: String = sorted_sarr.iter().collect();

        if mh.contains(&sorted_str) {
            return false;
        }

        mh.insert(sorted_str);
        true
    }
}

fn main() {
    // Example usage:
    let param_1: i32 = 3; // Replace with actual values
    let param_2: i32 = 10; // Replace with actual values
    let ret =
        Solution::count_good_integers(param_1.try_into().unwrap(), param_2.try_into().unwrap());
    let out = ret.serialize();
    println!("{:?}", out);
}
//sub: https://leetcode.com/problems/find-the-count-of-good-integers/submissions/1604138442/?envType=daily-question&envId=2025-04-12
//sol: https://leetcode.com/problems/find-the-count-of-good-integers/solutions/6641500/3272-find-the-count-of-good-integers-by-8lore/
