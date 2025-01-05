// https://leetcode.com/problems/shifting-letters-ii/description/?envType=daily-question&envId=2025-01-05
// 2381. Shifting Letters II

function shiftingLetters(s: string, shifts: number[][]): string {
  const n: number = s.length; // Get the length of the string
  const diffArray: number[] = new Array(n).fill(0); // Initialize diffArray with zeros

  for (const shift of shifts) {
    // Traverse the shifts array
    if (shift[2] === 1) {
      // If direction is forward
      diffArray[shift[0]]++;
      if (shift[1] + 1 < n) {
        diffArray[shift[1] + 1]--;
      }
    } else {
      // If direction is backward
      diffArray[shift[0]]--;
      if (shift[1] + 1 < n) {
        diffArray[shift[1] + 1]++;
      }
    }
  }

  const result: string[] = new Array(n).fill(""); // Initialize the result array
  let numberOfShifts = 0;

  for (let i = 0; i < n; i++) {
    // Iterate over the string
    numberOfShifts = (numberOfShifts + diffArray[i]) % 26; // Update cumulative shifts
    if (numberOfShifts < 0) {
      numberOfShifts += 26; // Ensure non-negative shifts
    }
    result[i] = String.fromCharCode(
      "a".charCodeAt(0) +
        ((s.charCodeAt(i) - "a".charCodeAt(0) + numberOfShifts) % 26),
    ); // Calculate the new character
  }

  return result.join(""); // Join and return the result as a string
}
//100%
//https://leetcode.com/problems/shifting-letters-ii/submissions/1498760280/?envType=daily-question&envId=2025-01-05
