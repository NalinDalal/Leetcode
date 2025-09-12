//3227. Vowels Game in a String
impl Solution {
    pub fn does_alice_win(s: String) -> bool {
        let vowels = ['a', 'e', 'i', 'o', 'u'];
        let num_vowel = s.chars().filter(|&c| vowels.contains(&c)).count();
        num_vowel > 0
    }
}
//sub: https://leetcode.com/problems/vowels-game-in-a-string/submissions/1767778535/?envType=daily-question&envId=2025-09-12
//sol: https://leetcode.com/problems/vowels-game-in-a-string/solutions/7180713/3227-vowels-game-in-a-string-by-nalindal-zzzw/
