//3085. Minimum Deletions to Make String K-Special
function minimumDeletions(word: string, k: number): number {
  const freq = new Map<string, number>();

  for (const c of word) {
    freq.set(c, (freq.get(c) ?? 0) + 1);
  }

  const counts = Array.from(freq.values()).sort((a, b) => a - b);
  const maxCount = counts[counts.length - 1];

  let res = Infinity;

  for (let base = 1; base <= maxCount; base++) {
    let deletions = 0;

    for (const f of counts) {
      if (f < base) {
        deletions += f;
      } else if (f > base + k) {
        deletions += f - (base + k);
      }
    }

    res = Math.min(res, deletions);
  }

  return res;
}

// Example usage:
console.log(minimumDeletions("aabcab", 1)); // Output: 1
//sub: https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/submissions/1671043477/?envType=daily-question&envId=2025-06-21
//sol: https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/solutions/6867131/3085-minimum-deletions-to-make-string-k-toj6a/
