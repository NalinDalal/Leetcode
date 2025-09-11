//2785. Sort Vowels in a String
impl Solution {
    pub fn sort_vowels(s: String) -> String {
        fn is_vowel(c: char) -> bool {
            matches!(c, 'a'|'e'|'i'|'o'|'u'|'A'|'E'|'I'|'O'|'U')
        }

        // Step 1: Collect vowels
        let mut vowels: Vec<char> = s.chars().filter(|&c| is_vowel(c)).collect();

        // Step 2: Sort vowels
        vowels.sort();

        // Step 3: Replace vowels
        let mut idx = 0;
        let mut result: String = s.chars().map(|c| {
            if is_vowel(c) {
                let new_c = vowels[idx];
                idx += 1;
                new_c
            } else {
                c
            }
        }).collect();

        result
    }
}
//sub: https://leetcode.com/problems/sort-vowels-in-a-string/submissions/1766809194/?envType=daily-question&envId=2025-09-11
//sol: https://leetcode.com/problems/sort-vowels-in-a-string/solutions/7177613/2785-sort-vowels-in-a-string-by-nalindal-3t4x/
