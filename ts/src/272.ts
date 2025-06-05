//1061. Lexicographically Smallest Equivalent String
function smallestEquivalentString(
  s1: string,
  s2: string,
  baseStr: string,
): string {
  const parent: number[] = Array.from({ length: 26 }, (_, i) => i);

  const find = (x: number): number => {
    if (parent[x] !== x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  };

  const unite = (x: number, y: number) => {
    const px = find(x);
    const py = find(y);
    if (px === py) return;
    if (px < py) parent[py] = px;
    else parent[px] = py;
  };

  for (let i = 0; i < s1.length; i++) {
    unite(s1.charCodeAt(i) - 97, s2.charCodeAt(i) - 97);
  }

  return [...baseStr]
    .map((c) => String.fromCharCode(find(c.charCodeAt(0) - 97) + 97))
    .join("");
}
//sub: https://leetcode.com/problems/lexicographically-smallest-equivalent-string/submissions/1654655246/
//sol: https://leetcode.com/problems/lexicographically-smallest-equivalent-string/solutions/6813531/1061-lexicographically-smallest-equivalent-string/
