// 3403. Find the Lexicographically Largest String From the Box I

function answerString(word: string, numFriends: number): string {
  const n = word.length;

  // Step 1: Handle the base case where all friends can split the string
  if (numFriends === 1) {
    return word;
  }

  // Step 2: Find the lexicographically largest character in the string
  const maxChar = Math.max(...word.split("").map((char) => char.charCodeAt(0)));
  const maxCharStr = String.fromCharCode(maxChar);
  let maxString = "";

  // Step 3: Iterate through the positions of the largest character
  for (let pos = 0; pos < n; pos++) {
    if (word[pos] === maxCharStr) {
      // Step 4: Compute the maximum allowable substring length from this position
      const lAllowed = Math.min(n - pos, n - numFriends + 1);

      // Skip if no valid substring can be formed
      if (lAllowed <= 0) {
        continue;
      }

      // Step 5: Extract the substring and compare with the current maximum
      const substring = word.substr(pos, lAllowed);
      if (substring > maxString) {
        maxString = substring; // Update the maximum string
      }
    }
  }

  // Step 6: Return the result
  return maxString;
}

//sub: https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/submissions/1509305010/
//sol: https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/solutions/6283708/3403-find-the-lexicographically-largest-h2y8f/
