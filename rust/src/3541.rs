//3541. Find Most Frequent Vowel and Consonant
use std::collections::HashMap;
impl Solution {
    pub fn max_freq_sum(s: String) -> i32 {
        let mut freq: HashMap<char, i32> = HashMap::new();

        for c in s.chars() {
            if c.is_ascii_alphabetic() {
                let lower = c.to_ascii_lowercase();
                *freq.entry(lower).or_insert(0) += 1;
            }
        }

        let is_vowel = |c: char| "aeiou".contains(c);

        let mut max_vowel = 0;
        let mut max_consonant = 0;

        for (ch, count) in freq {
            if is_vowel(ch) {
                max_vowel = max_vowel.max(count);
            } else {
                max_consonant = max_consonant.max(count);
            }
        }

        max_vowel + max_consonant
    }
}


//sub: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/submissions/1768791077/?envType=daily-question&envId=2025-09-13
//sol: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/solutions/7183971/3541-find-most-frequent-vowel-and-conson-9rwe/
