//3170. Lexicographically Minimum String After Removing Stars
impl Solution {
    pub fn clear_stars(s: String) -> String {
        let mut s_chars: Vec<char> = s.chars().collect();
        let mut cnt: Vec<Vec<usize>> = vec![Vec::new(); 26];

        for i in 0..s_chars.len() {
            if s_chars[i] != '*' {
                let index = (s_chars[i] as u8 - b'a') as usize;
                cnt[index].push(i);
            } else {
                for j in 0..26 {
                    if let Some(&pos) = cnt[j].last() {
                        s_chars[pos] = '*';
                        cnt[j].pop();
                        break;
                    }
                }
            }
        }

        s_chars.into_iter().filter(|&c| c != '*').collect()
    }
}

//sub: https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/submissions/1656202167/?envType=daily-question&envId=2025-06-07
