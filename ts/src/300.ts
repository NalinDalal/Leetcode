//3304. Find the K-th Character in String Game I
function kthCharacter(k: number): string {
  let ans = 0;
  while (k !== 1) {
    let t = 31 - Math.clz32(k);
    if (1 << t === k) {
      t--;
    }
    k -= 1 << t;
    ans++;
  }
  return String.fromCharCode("a".charCodeAt(0) + ans);
}
//sub: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/?envType=daily-question&envId=2025-07-03
//sol: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/solutions/6914654/3304-find-the-k-th-character-in-string-g-9m1m/
