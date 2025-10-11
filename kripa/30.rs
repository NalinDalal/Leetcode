//30. Substring with Concatenation of All Words

use std::collections::HashMap;

impl Solution {
    pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        let mut res = Vec::new();
        if words.is_empty() || s.is_empty() {
            return res;
        }

        let word_len = words[0].len();
        let word_count = words.len();
        let total_len = word_len * word_count;
        let n = s.len();

        let mut word_map: HashMap<String, i32> = HashMap::new();
        for word in &words {
            *word_map.entry(word.clone()).or_insert(0) += 1;
        }

        for i in 0..word_len {
            let mut left = i;
            let mut count = 0;
            let mut window: HashMap<String, i32> = HashMap::new();

            let mut j = i;
            while j + word_len <= n {
                let word = s[j..j + word_len].to_string();

                if word_map.contains_key(&word) {
                    *window.entry(word.clone()).or_insert(0) += 1;
                    count += 1;

                    while window[&word] > word_map[&word] {
                        let left_word = s[left..left + word_len].to_string();
                        if let Some(x) = window.get_mut(&left_word) {
                            *x -= 1;
                        }
                        count -= 1;
                        left += word_len;
                    }

                    if count == word_count {
                        res.push(left as i32);
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = j + word_len;
                }

                j += word_len;
            }
        }

        res
    }
}
//sub: https://leetcode.com/problems/substring-with-concatenation-of-all-words/submissions/1610122457/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/substring-with-concatenation-of-all-words/solutions/6662226/30-substring-with-concatenation-of-all-w-wzh0/
