//1323. Maximum 69 Number
impl Solution {
    pub fn maximum69_number (num: i32) -> i32 {
        let mut chars: Vec<char> = num.to_string().chars().collect();
        let mut ans = num;

        for i in 0..chars.len() {
            let original = chars[i];

            // flip digit
            if chars[i] == '6' {
                chars[i] = '9';
            } else if chars[i] == '9' {
                chars[i] = '6';
            }

            // join chars back into string and parse to number
            let val: i32 = chars.iter().collect::<String>().parse().unwrap();
            ans = ans.max(val);

            // restore
            chars[i] = original;
        }

        ans
    }
}


impl Solution {
    pub fn maximum69_number(num: i32) -> i32 {
        let s = num.to_string().replacen("6", "9", 1);
        s.parse().unwrap()
    }
}
//sub: https://leetcode.com/problems/maximum-69-number/submissions/1736785336/?envType=daily-question&envId=2025-08-16
//sol: https://leetcode.com/problems/maximum-69-number/solutions/7086394/1323-maximum-69-number-by-nalindalal2004-6nqr/
