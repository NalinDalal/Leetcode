//3307. Find the K-th Character in String Game II
function kthCharacter(k: number, operations: number[]): string {
  let ans = 0;
  while (k !== 1) {
    let t = Math.floor(Math.log2(k));
    if (Number(1n << BigInt(t)) === k) {
      t--;
    }
    k -= Number(1n << BigInt(t));
    if (operations[t]) {
      ans++;
    }
  }
  return String.fromCharCode("a".charCodeAt(0) + (ans % 26));
}
//sub: https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/submissions/1686126741/
//sol: https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/solutions/6919299/3307-find-the-k-th-character-in-string-g-vsi1/
