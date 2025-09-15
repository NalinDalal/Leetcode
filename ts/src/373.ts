//1935. Maximum Number of Words You Can Type
function canBeTypedWords(text: string, brokenLetters: string): number {
  const broken = new Set(brokenLetters.split("")); // store broken letters
  const words = text.split(" "); // split text into words
  let ans = 0;

  for (const word of words) {
    let canType = true;
    for (const c of word) {
      if (broken.has(c)) {
        canType = false;
        break;
      }
    }
    if (canType) ans++;
  }

  return ans;
}
//sub: https://leetcode.com/problems/maximum-number-of-words-you-can-type/submissions/1771047582/?envType=daily-question&envId=2025-09-15
//sol: https://leetcode.com/problems/maximum-number-of-words-you-can-type/solutions/7190686/1935-maximum-number-of-words-you-can-typ-zy8j/
