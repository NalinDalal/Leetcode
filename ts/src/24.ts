// https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
// 151. Reverse Words in a String

function reverseWords(s: string): string {
  // Trim leading and trailing spaces
  s = trim(s);

  // Split string into words
  const words = s.split(/\s+/); // Split by one or more spaces

  // Reverse the array of words
  words.reverse();

  // Join the array and return it
  return words.join(" ");
}

function trim(s: string): string {
  // Remove leading and trailing spaces
  return s.trim();
}
