//58. Length of Last Word
impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let chars: Vec<char> = s.chars().collect(); // Convert string to Vec<char>
        let mut length = 0;
        let mut i = chars.len() as isize - 1; // Use isize for safe decrementing

        // Ignore trailing spaces
        while i >= 0 && chars[i as usize] == ' ' {
            i -= 1;
        }

        // Count the length of the last word
        while i >= 0 && chars[i as usize] != ' ' {
            length += 1;
            i -= 1;
        }

        length // Return value (no semicolon means implicit return)
    }
}
//sub: https://leetcode.com/problems/length-of-last-word/submissions/1595482167/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/length-of-last-word/solutions/6610941/58-length-of-last-word-by-nalindalal2004-yzbw/
