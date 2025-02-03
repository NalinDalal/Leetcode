// 131. Palindrome Partitioning
function partition(s: string): string[][] {
  const ans: string[][] = [];
  const current: string[] = [];
  partitionHelper(s, 0, current, ans);
  return ans;
}

function partitionHelper(
  s: string,
  start: number,
  current: string[],
  ans: string[][],
): void {
  if (start === s.length) {
    ans.push([...current]); // Use spread operator to copy the current array
    return;
  }

  for (let i = start; i < s.length; ++i) {
    if (isPalindrome(s, start, i)) {
      current.push(s.substring(start, i + 1));
      partitionHelper(s, i + 1, current, ans);
      current.pop();
    }
  }
}

function isPalindrome(s: string, left: number, right: number): boolean {
  while (left < right) {
    if (s[left] !== s[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}
//sub: https://leetcode.com/problems/palindrome-partitioning/submissions/1530011117/
//sol: https://leetcode.com/problems/palindrome-partitioning/solutions/6368813/131-palindrome-partitioning-by-nalindala-fv3j/
