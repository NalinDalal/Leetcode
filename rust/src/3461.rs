//3461. Check If Digits Are Equal in String After Operations I
impl Solution {
    pub fn has_same_digits(mut s: String) -> bool {
        while s.len() > 2 {
            let mut new_s = String::new();
            let bytes = s.as_bytes();
            for i in 0..s.len() - 1 {
                let new_digit = ((bytes[i] - b'0' + bytes[i + 1] - b'0') % 10) as u8 + b'0';
                new_s.push(new_digit as char);
            }
            s = new_s;
        }
        s.chars().nth(0) == s.chars().nth(1)
    }
}
//sub: https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/submissions/1809239673/?envType=daily-question&envId=2025-10-23
//sol: https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/solutions/7294408/3461-check-if-digits-are-equal-in-string-i6zz/
