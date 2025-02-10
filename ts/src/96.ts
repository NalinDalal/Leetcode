//
function clearDigits(s: string): string {
  while (true) {
    let n = s.length;
    let found = false;

    for (let i = 0; i < n; i++) {
      if (isDigit(s[i])) {
        // Find the nearest non-digit character to the left
        let j = i - 1;
        while (j >= 0 && isDigit(s[j])) j--; // Skip digits

        // Convert string to an array to modify it
        let arr = s.split("");

        // Erase the digit and nearest non-digit character
        arr.splice(i, 1); // Delete digit
        if (j >= 0) arr.splice(j, 1); // Delete non-digit if it exists

        s = arr.join(""); // Convert back to string
        found = true;
        break; // Restart loop after deletion
      }
    }
    if (!found) break; // Stop when no more digits are found
  }
  return s;
}

function isDigit(c: string): boolean {
  return c >= "0" && c <= "9";
}

// Test Cases
const sol = new Solution();
console.log(sol.clearDigits("ab1cde")); // Output: "acde"
console.log(sol.clearDigits("1abcd")); // Output: "abcd"
console.log(sol.clearDigits("abc123")); // Output: "ac123"
//sub: https://leetcode.com/problems/clear-digits/submissions/1538163263/?envType=daily-question&envId=2025-02-10
//sol: https://leetcode.com/problems/clear-digits/solutions/6403184/3174-clear-digits-by-nalindalal2004-74p2/
