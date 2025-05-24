//2942. Find Words Containing Character
impl Solution {
    pub fn find_words_containing(words: Vec<String>, x: char) -> Vec<i32> {
        let mut result = Vec::new();
        for (i, word) in words.iter().enumerate() {
            if word.contains(x) {
                result.push(i as i32);
            }
        }
        result
    }
}
//sub:https://leetcode.com/problems/find-words-containing-character/submissions/1642683328/?envType=daily-question&envId=2025-05-24
//sol:https://leetcode.com/problems/find-words-containing-character/solutions/6775087/2942-find-words-containing-character-by-00nq4/
