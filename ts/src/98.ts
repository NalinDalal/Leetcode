//1910. Remove All Occurrences of a Substring
function removeOccurrences(s: string, part: string): string {}
function removeOccurrences(s: string, part: string): string {
  let result: string[] = [];
  let partLen = part.length;

  for (let c of s) {
    result.push(c);

    // Check if the last `part.length` characters match `part`
    if (result.length >= partLen && result.slice(-partLen).join("") === part) {
      result.length -= partLen; // Efficiently remove last `partLen` characters
    }
  }

  return result.join("");
}
//sub: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/submissions/1539372004/?envType=daily-question&envId=2025-02-11
//sol: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/solutions/6408286/1910-remove-all-occurrences-of-a-substri-x75b/
