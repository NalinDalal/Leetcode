//2131. Longest Palindrome by Concatenating Two Letter Words
use std::collections::HashMap;
impl Solution {
    pub fn longest_palindrome(words: Vec<String>) -> i32 {
        let mut mpp: HashMap<String, i32> = HashMap::new();
        for w in &words {
            *mpp.entry(w.clone()).or_insert(0) += 1;
        }

        let mut count = 0;
        let mut already_palindrome = false;

        for (w, &freq) in &mpp {
            let reversed: String = w.chars().rev().collect();

            if w == &reversed {
                count += (freq / 2) * 4;
                if freq % 2 == 1 {
                    already_palindrome = true;
                }
            } else if w < &reversed {
                if let Some(&other_freq) = mpp.get(&reversed) {
                    count += std::cmp::min(freq, other_freq) * 4;
                }
            }
        }

        if already_palindrome {
            count += 2;
        }

        count
    }
}
//sub: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/submissions/1643723364/?envType=daily-question&envId=2025-05-25
//sol: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/solutions/6778561/2131-longest-palindrome-by-concatenating-allf/
