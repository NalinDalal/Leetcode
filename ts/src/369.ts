//2785. Sort Vowels in a String
function sortVowels(s: string): string {
  const vowels = new Set(["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]);
  const arr = s.split("");

  // Step 1: Collect vowels
  const vowelChars: string[] = [];
  for (const c of arr) {
    if (vowels.has(c)) vowelChars.push(c);
  }

  // Step 2: Sort vowels
  vowelChars.sort();

  // Step 3: Replace vowels in order
  let idx = 0;
  for (let i = 0; i < arr.length; i++) {
    if (vowels.has(arr[i])) {
      arr[i] = vowelChars[idx++];
    }
  }

  return arr.join("");
}
//sub: https://leetcode.com/problems/sort-vowels-in-a-string/submissions/1766808207/?envType=daily-question&envId=2025-09-11
//sol: https://leetcode.com/problems/sort-vowels-in-a-string/solutions/7177613/2785-sort-vowels-in-a-string-by-nalindal-3t4x/
