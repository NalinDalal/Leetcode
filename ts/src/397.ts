//2273. Find Resultant Array After Removing Anagrams
function removeAnagrams(words: string[]): string[] {
  const res: string[] = [];
  res.push(words[0]);

  for (let i = 1; i < words.length; i++) {
    const prev = res[res.length - 1];
    const cur = words[i];

    if (!isAnagram(prev, cur)) {
      res.push(cur);
    }
  }

  return res;
}

function isAnagram(a: string, b: string): boolean {
  if (a.length !== b.length) return false;
  const sortedA = a.split("").sort().join("");
  const sortedB = b.split("").sort().join("");
  return sortedA === sortedB;
}

//sub: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/submissions/1800120948/?envType=daily-question&envId=2025-10-13
//sol: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/solutions/7271299/2273-find-resultant-array-after-removing-ss76/
