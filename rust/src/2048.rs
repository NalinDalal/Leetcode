//2048. Next Greater Numerically Balanced Number
impl Solution {
    pub fn next_beautiful_number(n: i32) -> i32 {
        fn is_balanced(num: i32) -> bool {
            let s = num.to_string();
            let mut freq = vec![0; 10];
            for c in s.chars() {
                let d = c.to_digit(10).unwrap() as usize;
                freq[d] += 1;
            }
            for d in 0..10 {
                if freq[d] > 0 && freq[d] != d {
                    return false;
                }
            }
            true
        }

        let mut i = n + 1;
        loop {
            if is_balanced(i) {
                return i;
            }
            i += 1;
        }
    }
}
//sub: https://leetcode.com/problems/next-greater-numerically-balanced-number/submissions/1809968957/?envType=daily-question&envId=2025-10-24
//sol: https://leetcode.com/problems/next-greater-numerically-balanced-number/solutions/7296274/2048-next-greater-numerically-balanced-n-pfei/
