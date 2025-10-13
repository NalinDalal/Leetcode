//2273. Find Resultant Array After Removing Anagrams
use std::collections::HashMap;

impl Solution {
    pub fn remove_anagrams(words: Vec<String>) -> Vec<String> {
        let mut res: Vec<String> = Vec::new();

        if words.is_empty() {
            return res;
        }

        res.push(words[0].clone());

        for i in 1..words.len() {
            let prev = res.last().unwrap();
            let cur = &words[i];

            if !Self::is_anagram(prev, cur) {
                res.push(cur.clone());
            }
        }

        res
    }

    fn is_anagram(a: &str, b: &str) -> bool {
        if a.len() != b.len() {
            return false;
        }

        let mut count = [0; 26];
        for (ca, cb) in a.bytes().zip(b.bytes()) {
            count[(ca - b'a') as usize] += 1;
            count[(cb - b'a') as usize] -= 1;
        }

        count.iter().all(|&x| x == 0)
    }
}

//sub: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/submissions/1800121386/?envType=daily-question&envId=2025-10-13
//sol: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/solutions/7271299/2273-find-resultant-array-after-removing-ss76/
