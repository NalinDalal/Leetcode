//3170. Lexicographically Minimum String After Removing Stars
function clearStars(s: string): string {
  const cnt: number[][] = Array.from({ length: 26 }, () => []);

  const chars = s.split("");

  for (let i = 0; i < chars.length; i++) {
    const c = chars[i];
    if (c !== "*") {
      cnt[c.charCodeAt(0) - "a".charCodeAt(0)].push(i);
    } else {
      for (let j = 0; j < 26; j++) {
        if (cnt[j].length > 0) {
          const idx = cnt[j].pop()!;
          chars[idx] = "*";
          break;
        }
      }
    }
  }

  return chars.filter((c) => c !== "*").join("");
}

//sub: https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/submissions/1656201876/?envType=daily-question&envId=2025-06-07
