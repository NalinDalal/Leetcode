// 3042. Count Prefix and Suffix Pairs I

//solution: https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/solutions/6249108/3042-count-prefix-and-suffix-pairs-i100-i6ntt/
//submissions: https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/submissions/1501760450/?envType=daily-question&envId=2025-01-08

function isPrefixAndSuffix(str1: string, str2: string): boolean {
  const n1 = str1.length,
    n2 = str2.length;
  if (n1 > n2) return false; // str1 cannot be both prefix and suffix if longer
  return str2.startsWith(str1) && str2.endsWith(str1);
}

function countPrefixSuffixPairs(words: string[]): number {
  const n = words.length;
  let count = 0;

  for (let i = 0; i < n; ++i) {
    for (let j = i + 1; j < n; ++j) {
      // Ensure i < j
      if (isPrefixAndSuffix(words[i], words[j])) {
        ++count;
      }
    }
  }

  return count;
}
