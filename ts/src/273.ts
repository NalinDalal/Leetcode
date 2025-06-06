//2434. Using a Robot to Print the Lexicographically Smallest String
function robotWithString(s: string): string {
  const n = s.length;
  const p: string[] = [];
  const t: string[] = [];
  const minRight: string[] = new Array(n);

  // Build minRight array
  minRight[n - 1] = s[n - 1];
  for (let i = n - 2; i >= 0; i--) {
    minRight[i] = s[i] < minRight[i + 1] ? s[i] : minRight[i + 1];
  }

  for (let i = 0; i < n; i++) {
    t.push(s[i]);
    while (
      t.length > 0 &&
      (i === n - 1 || t[t.length - 1] <= minRight[i + 1])
    ) {
      p.push(t.pop()!);
    }
  }

  return p.join("");
}

//sub: https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/submissions/1655315352/?envType=daily-question&envId=2025-06-06
