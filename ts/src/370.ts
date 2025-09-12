//3227. Vowels Game in a String
function doesAliceWin(s: string): boolean {
  let numVowel = 0;
  for (let c of s) {
    if ("aeiou".includes(c)) {
      numVowel++;
    }
  }
  return numVowel > 0;
}
//sub: https://leetcode.com/problems/vowels-game-in-a-string/submissions/1767778167/?envType=daily-question&envId=2025-09-12
//sol: https://leetcode.com/problems/vowels-game-in-a-string/solutions/7180713/3227-vowels-game-in-a-string-by-nalindal-zzzw/
