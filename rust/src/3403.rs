//3403. Find the Lexicographically Largest String From the Box I
impl Solution {
    pub fn answer_string(word: String, num_friends: i32) -> String {
        let n = word.len();
        if num_friends == 1 {
            return word;
        }

        let chars: Vec<char> = word.chars().collect();
        let max_char = *chars.iter().max().unwrap();
        let mut max_string = String::new();

        for pos in 0..n {
            if chars[pos] == max_char {
                let l_allowed = (n - pos).min(n - num_friends as usize + 1);
                if l_allowed == 0 {
                    continue;
                }

                let substr: String = chars[pos..pos + l_allowed].iter().collect();
                if substr > max_string {
                    max_string = substr;
                }
            }
        }

        max_string
    }
}

//sub: https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/submissions/1653162531/?envType=daily-question&envId=2025-06-04
//sol: https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/solutions/6283708/3403-find-the-lexicographically-largest-h2y8f/
