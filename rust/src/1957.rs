//1957. Delete Characters to Make Fancy String
impl Solution {
    pub fn make_fancy_string(s: String) -> String {
        let chars: Vec<char> = s.chars().collect();
        let mut ans = String::new();

        for i in 0..chars.len() {
            if i + 2 >= chars.len() || chars[i] != chars[i + 1] || chars[i] != chars[i + 2] {
                ans.push(chars[i]);
            }
        }

        ans
    }
}
//sub: https://leetcode.com/problems/delete-characters-to-make-fancy-string/submissions/1705469475/?envType=daily-question&envId=2025-07-21
//sol: https://leetcode.com/problems/delete-characters-to-make-fancy-string/solutions/6984194/1957-delete-characters-to-make-fancy-str-jh4p/
