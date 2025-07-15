//3136. Valid Word
impl Solution {
    pub fn is_valid(word: String) -> bool {
        if word.len() < 3 {
            return false;
        }

        let mut has_vowel = false;
        let mut has_consonant = false;

        for c in word.chars() {
            if !c.is_ascii_alphanumeric() {
                return false;
            }

            if c.is_ascii_alphabetic() {
                let lower = c.to_ascii_lowercase();
                if "aeiou".contains(lower) {
                    has_vowel = true;
                } else {
                    has_consonant = true;
                }
            }
        }

        has_vowel && has_consonant
    }
}

//sub: https://leetcode.com/problems/valid-word/submissions/1698431645/?envType=daily-question&envId=2025-07-15
//sol: https://leetcode.com/problems/valid-word/solutions/6960738/3136-valid-word-by-nalindalal2004-cdo5/
