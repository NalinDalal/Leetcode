// 1415. The k-th Lexicographical String of All Happy Strings of Length n
function getHappyString(n: number, k: number): string {
  const happyStrings: string[] = [];
  generateHappyStrings(n, "", happyStrings);

  return k > happyStrings.length ? "" : happyStrings[k - 1]; // 1-based index
}

function generateHappyStrings(
  n: number,
  current: string,
  result: string[],
): void {
  if (current.length === n) {
    result.push(current);
    return;
  }

  for (const ch of ["a", "b", "c"]) {
    if (current.length === 0 || current[current.length - 1] !== ch) {
      generateHappyStrings(n, current + ch, result);
    }
  }
}
//sub: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/submissions/1548612856/?envType=daily-question&envId=2025-02-19
//sol: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/solutions/6442604/1415-the-k-th-lexicographical-string-of-t6zpu/
