//3307. Find the K-th Character in String Game II
impl Solution {
    pub fn kth_character(k: i64, operations: Vec<i32>) -> char {
        let mut ans = 0;
        let mut k = k;
        while k != 1 {
            let t = 63 - k.leading_zeros();
            let t = if (1 << t) == k { t - 1 } else { t };
            k -= 1 << t;
            if operations[t as usize] != 0 {
                ans += 1;
            }
        }
        (b'a' + (ans % 26) as u8) as char
    }
}
//sub: https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/submissions/1686125905/
//sol: https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/solutions/6919299/3307-find-the-k-th-character-in-string-g-vsi1/
