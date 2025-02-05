function areAlmostEqual(s1: string, s2: string): boolean {
  if (s1.length !== s2.length) return false;

  if (s1 === s2) return true;

  let first: number = -1;
  let second: number = -1;

  for (let i = 0; i < s1.length; i++) {
    if (s1[i] !== s2[i]) {
      if (first === -1) {
        first = i;
      } else if (second === -1) {
        second = i;
      } else {
        // More than two differences, early exit
        return false;
      }
    }
  }

  // Check if exactly two differences and swapping makes strings equal
  return second !== -1 && s1[first] === s2[second] && s1[second] === s2[first];
}

// Example usage
console.log(areAlmostEqual("bank", "kanb")); // true
console.log(areAlmostEqual("attack", "defend")); // false
console.log(areAlmostEqual("abcd", "abdc")); // true
console.log(areAlmostEqual("aaaa", "aaaa")); // true
console.log(areAlmostEqual("abcd", "abcdx")); // false

//sub: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/submissions/1532155734/?envType=daily-question&envId=2025-02-05
//sol: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/solutions/6378918/1790-check-if-one-string-swap-can-make-s-i5sz/
