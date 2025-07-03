//3304. Find the K-th Character in String Game I
impl Solution {
    pub fn kth_character(k: i32) -> char {
        let mut ans = 0;
        let mut k = k;
        while k != 1 {
            let t = 31 - k.leading_zeros();
            let t = if (1 << t) == k { t - 1 } else { t };
            k -= 1 << t;
            ans += 1;
        }
        (b'a' + ans) as char
    }
}
//sub: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/submissions/1684870289/?envType=daily-question&envId=2025-07-03
//sol: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/solutions/6914654/3304-find-the-k-th-character-in-string-g-9m1m/
