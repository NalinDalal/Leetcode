//966. Vowel Spellchecker
use std::collections::{HashMap, HashSet};

struct Solution;

impl Solution {
    pub fn spellchecker(wordlist: Vec<String>, queries: Vec<String>) -> Vec<String> {
        let exact: HashSet<String> = wordlist.iter().cloned().collect();
        let mut case_map: HashMap<String, String> = HashMap::new();
        let mut vowel_map: HashMap<String, String> = HashMap::new();

        fn to_lower(s: &str) -> String {
            s.to_lowercase()
        }

        fn mask_vowels(s: &str) -> String {
            s.to_lowercase()
                .chars()
                .map(|c| match c {
                    'a' | 'e' | 'i' | 'o' | 'u' => '*',
                    _ => c,
                })
                .collect()
        }

        // Preprocess
        for w in &wordlist {
            let lower = to_lower(w);
            case_map.entry(lower.clone()).or_insert(w.clone());

            let masked = mask_vowels(w);
            vowel_map.entry(masked).or_insert(w.clone());
        }

        let mut ans = Vec::new();
        for q in queries {
            if exact.contains(&q) {
                ans.push(q);
            } else {
                let lower = to_lower(&q);
                if let Some(w) = case_map.get(&lower) {
                    ans.push(w.clone());
                } else {
                    let masked = mask_vowels(&q);
                    if let Some(w) = vowel_map.get(&masked) {
                        ans.push(w.clone());
                    } else {
                        ans.push(String::new());
                    }
                }
            }
        }
        ans
    }
}
//sub: https://leetcode.com/problems/vowel-spellchecker/submissions/1770062824/?envType=daily-question&envId=2025-09-14
//sol: https://leetcode.com/problems/vowel-spellchecker/solutions/7187589/966-vowel-spellchecker-by-nalindalal2004-m86e/
